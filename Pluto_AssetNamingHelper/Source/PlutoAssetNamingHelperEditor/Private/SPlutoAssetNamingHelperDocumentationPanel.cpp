#include "SPlutoAssetNamingHelperDocumentationPanel.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SPlutoAssetNamingHelperDocumentationPanel"

void SPlutoAssetNamingHelperDocumentationPanel::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SBorder)
		.Padding(12.0f)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Title", "Pluto 资产命名助手使用文档"))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 14))
				]
				+ SHorizontalBox::Slot().AutoWidth()
				[
					SNew(SButton)
					.Text(LOCTEXT("Reload", "重新加载"))
					.ToolTipText(LOCTEXT("ReloadTooltip", "重新读取插件目录中的 Markdown 文档。"))
					.OnClicked(this, &SPlutoAssetNamingHelperDocumentationPanel::HandleReloadClicked)
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(STextBlock)
				.Text(this, &SPlutoAssetNamingHelperDocumentationPanel::BuildStatusText)
				.AutoWrapText(true)
				.ColorAndOpacity(FSlateColor::UseSubduedForeground())
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(SSeparator)
			]
			+ SVerticalBox::Slot().FillHeight(1.0f)
			[
				SAssignNew(ScrollBoxWidget, SScrollBox)
				+ SScrollBox::Slot()
				[
					SAssignNew(DocumentBoxWidget, SVerticalBox)
				]
			]
		]
	];

	ReloadDocument();
}

void SPlutoAssetNamingHelperDocumentationPanel::ReloadDocument()
{
	DocumentBlocks.Reset();
	const FString DocumentPath = GetDocumentPath();
	FString MarkdownText;

	if (DocumentPath.IsEmpty() || !FPaths::FileExists(DocumentPath))
	{
		StatusText = FText::Format(LOCTEXT("Missing", "未找到文档文件：{0}"), FText::FromString(DocumentPath));
		RebuildDocumentView();
		return;
	}

	if (!FFileHelper::LoadFileToString(MarkdownText, *DocumentPath))
	{
		StatusText = FText::Format(LOCTEXT("ReadFailed", "读取文档失败：{0}"), FText::FromString(DocumentPath));
		RebuildDocumentView();
		return;
	}

	ParseMarkdown(MarkdownText);
	StatusText = FText::Format(LOCTEXT("CurrentDocument", "当前文档：{0}"), FText::FromString(DocumentPath));
	RebuildDocumentView();
}

void SPlutoAssetNamingHelperDocumentationPanel::ParseMarkdown(const FString& MarkdownText)
{
	TArray<FString> Lines;
	MarkdownText.Replace(TEXT("\r\n"), TEXT("\n")).ParseIntoArray(Lines, TEXT("\n"), false);

	bool bInCodeBlock = false;
	FString CodeBlockText;
	TArray<FString> ParagraphLines;

	for (const FString& RawLine : Lines)
	{
		const FString TrimmedLine = RawLine.TrimStartAndEnd();
		if (TrimmedLine.StartsWith(TEXT("```")))
		{
			FlushParagraph(ParagraphLines);
			if (bInCodeBlock)
			{
				FPlutoAssetNamingDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
				Block.Type = EPlutoAssetNamingDocumentationBlockType::CodeBlock;
				Block.Text = CodeBlockText;
				CodeBlockText.Reset();
			}
			bInCodeBlock = !bInCodeBlock;
			continue;
		}

		if (bInCodeBlock)
		{
			if (!CodeBlockText.IsEmpty())
			{
				CodeBlockText.AppendChar(TEXT('\n'));
			}
			CodeBlockText += RawLine;
			continue;
		}

		if (TrimmedLine.IsEmpty())
		{
			FlushParagraph(ParagraphLines);
			continue;
		}

		auto AddHeading = [this, &TrimmedLine](EPlutoAssetNamingDocumentationBlockType Type, int32 PrefixLength)
		{
			FPlutoAssetNamingDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
			Block.Type = Type;
			Block.Text = TrimmedLine.RightChop(PrefixLength).TrimStartAndEnd();
		};

		if (TrimmedLine.StartsWith(TEXT("### ")))
		{
			FlushParagraph(ParagraphLines);
			AddHeading(EPlutoAssetNamingDocumentationBlockType::Heading3, 4);
		}
		else if (TrimmedLine.StartsWith(TEXT("## ")))
		{
			FlushParagraph(ParagraphLines);
			AddHeading(EPlutoAssetNamingDocumentationBlockType::Heading2, 3);
		}
		else if (TrimmedLine.StartsWith(TEXT("# ")))
		{
			FlushParagraph(ParagraphLines);
			AddHeading(EPlutoAssetNamingDocumentationBlockType::Heading1, 2);
		}
		else if (TrimmedLine.StartsWith(TEXT("- ")) || TrimmedLine.StartsWith(TEXT("* ")))
		{
			FlushParagraph(ParagraphLines);
			FPlutoAssetNamingDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
			Block.Type = EPlutoAssetNamingDocumentationBlockType::Bullet;
			Block.Text = TrimmedLine.RightChop(2).TrimStartAndEnd();
		}
		else
		{
			ParagraphLines.Add(TrimmedLine);
		}
	}

	FlushParagraph(ParagraphLines);
	if (bInCodeBlock && !CodeBlockText.IsEmpty())
	{
		FPlutoAssetNamingDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
		Block.Type = EPlutoAssetNamingDocumentationBlockType::CodeBlock;
		Block.Text = CodeBlockText;
	}
}

void SPlutoAssetNamingHelperDocumentationPanel::FlushParagraph(TArray<FString>& ParagraphLines)
{
	if (ParagraphLines.IsEmpty())
	{
		return;
	}

	FPlutoAssetNamingDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
	Block.Type = EPlutoAssetNamingDocumentationBlockType::Paragraph;
	Block.Text = FString::Join(ParagraphLines, TEXT(" "));
	ParagraphLines.Reset();
}

FString SPlutoAssetNamingHelperDocumentationPanel::GetDocumentPath() const
{
	const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("Pluto_AssetNamingHelper"));
	return Plugin.IsValid()
		? FPaths::Combine(Plugin->GetBaseDir(), TEXT("Docs"), TEXT("PlutoAssetNamingHelper.zh-CN.md"))
		: FString();
}

FText SPlutoAssetNamingHelperDocumentationPanel::BuildStatusText() const
{
	return StatusText;
}

FReply SPlutoAssetNamingHelperDocumentationPanel::HandleReloadClicked()
{
	ReloadDocument();
	return FReply::Handled();
}

void SPlutoAssetNamingHelperDocumentationPanel::RebuildDocumentView()
{
	if (!DocumentBoxWidget.IsValid())
	{
		return;
	}

	DocumentBoxWidget->ClearChildren();
	if (DocumentBlocks.IsEmpty())
	{
		DocumentBoxWidget->AddSlot().AutoHeight().Padding(0.0f, 8.0f)
		[
			SNew(STextBlock).Text(LOCTEXT("NoContent", "当前没有可显示的文档内容。")).AutoWrapText(true)
		];
		return;
	}

	for (const FPlutoAssetNamingDocumentationBlock& Block : DocumentBlocks)
	{
		DocumentBoxWidget->AddSlot().AutoHeight().Padding(0.0f, 0.0f, 0.0f, 8.0f)
		[
			BuildBlockWidget(Block)
		];
	}

	if (ScrollBoxWidget.IsValid())
	{
		ScrollBoxWidget->ScrollToStart();
	}
}

TSharedRef<SWidget> SPlutoAssetNamingHelperDocumentationPanel::BuildBlockWidget(const FPlutoAssetNamingDocumentationBlock& Block) const
{
	switch (Block.Type)
	{
	case EPlutoAssetNamingDocumentationBlockType::Heading1:
		return SNew(STextBlock).Text(FText::FromString(Block.Text)).Font(FCoreStyle::GetDefaultFontStyle("Bold", 18)).AutoWrapText(true);
	case EPlutoAssetNamingDocumentationBlockType::Heading2:
		return SNew(STextBlock).Text(FText::FromString(Block.Text)).Font(FCoreStyle::GetDefaultFontStyle("Bold", 15)).AutoWrapText(true);
	case EPlutoAssetNamingDocumentationBlockType::Heading3:
		return SNew(STextBlock).Text(FText::FromString(Block.Text)).Font(FCoreStyle::GetDefaultFontStyle("Bold", 13)).AutoWrapText(true);
	case EPlutoAssetNamingDocumentationBlockType::Bullet:
		return SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0.0f, 0.0f, 6.0f, 0.0f)
			[
				SNew(STextBlock).Text(FText::FromString(TEXT("\x2022")))
			]
			+ SHorizontalBox::Slot().FillWidth(1.0f)
			[
				SNew(STextBlock).Text(FText::FromString(Block.Text)).AutoWrapText(true)
			];
	case EPlutoAssetNamingDocumentationBlockType::CodeBlock:
		return SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Brushes.Recessed"))
			.Padding(8.0f)
			[
				SNew(SMultiLineEditableTextBox).Text(FText::FromString(Block.Text)).IsReadOnly(true).AutoWrapText(false)
			];
	case EPlutoAssetNamingDocumentationBlockType::Paragraph:
	default:
		return SNew(STextBlock).Text(FText::FromString(Block.Text)).AutoWrapText(true);
	}
}

#undef LOCTEXT_NAMESPACE
