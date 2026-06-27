#include "SPlutoGameplayTagInspectorDocumentationPanel.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "PlutoGameplayTagInspectorEditorSettings.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

namespace PlutoGameplayTagInspectorDocumentationText
{
	FText Localized(const TCHAR* ChineseText, const TCHAR* EnglishText)
	{
		return PlutoGameplayTagInspectorEditor::MakeLocalizedText(ChineseText, EnglishText);
	}
}

void SPlutoGameplayTagInspectorDocumentationPanel::Construct(const FArguments& InArgs)
{
	DocumentLanguage = PlutoGameplayTagInspectorEditor::GetCurrentLanguage();

	ChildSlot
	[
		SNew(SBorder)
		.Padding(12.0f)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text_Lambda([]()
					{
						return PlutoGameplayTagInspectorDocumentationText::Localized(
							TEXT("Pluto GameplayTag 使用文档"),
							TEXT("Pluto GameplayTag Documentation"));
					})
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 14))
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 8.0f, 0.0f)
				[
					SNew(SButton)
					.Text_Lambda([]()
					{
						return PlutoGameplayTagInspectorDocumentationText::Localized(TEXT("重新加载"), TEXT("Reload"));
					})
					.ToolTipText_Lambda([]()
					{
						return PlutoGameplayTagInspectorDocumentationText::Localized(
							TEXT("重新读取当前语言对应的 Markdown 文档文件。"),
							TEXT("Reload the Markdown document file for the current language."));
					})
					.OnClicked(this, &SPlutoGameplayTagInspectorDocumentationPanel::HandleReloadClicked)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SButton)
					.Text(this, &SPlutoGameplayTagInspectorDocumentationPanel::BuildLanguageButtonText)
					.ToolTipText_Lambda([]()
					{
						return PlutoGameplayTagInspectorDocumentationText::Localized(
							TEXT("切换文档语言，不会修改插件的全局界面语言设置。"),
							TEXT("Switch the documentation language without changing the plugin's global UI language setting."));
					})
					.OnClicked(this, &SPlutoGameplayTagInspectorDocumentationPanel::HandleLanguageClicked)
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(STextBlock)
				.Text(this, &SPlutoGameplayTagInspectorDocumentationPanel::BuildStatusText)
				.AutoWrapText(true)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(SSeparator)
			]
			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
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

void SPlutoGameplayTagInspectorDocumentationPanel::ReloadDocument()
{
	DocumentBlocks.Reset();

	const FString DocumentPath = GetDocumentPath();
	FString MarkdownText;
	if (!FPaths::FileExists(DocumentPath))
	{
		StatusText = PlutoGameplayTagInspectorDocumentationText::Localized(
			*FString::Printf(TEXT("未找到文档文件：%s"), *DocumentPath),
			*FString::Printf(TEXT("Document file not found: %s"), *DocumentPath));
		RebuildDocumentView();
		return;
	}

	if (!FFileHelper::LoadFileToString(MarkdownText, *DocumentPath))
	{
		StatusText = PlutoGameplayTagInspectorDocumentationText::Localized(
			*FString::Printf(TEXT("读取文档失败：%s"), *DocumentPath),
			*FString::Printf(TEXT("Failed to read document: %s"), *DocumentPath));
		RebuildDocumentView();
		return;
	}

	ParseMarkdown(MarkdownText);
	StatusText = PlutoGameplayTagInspectorDocumentationText::Localized(
		*FString::Printf(TEXT("当前文档：%s"), *DocumentPath),
		*FString::Printf(TEXT("Current document: %s"), *DocumentPath));
	RebuildDocumentView();
}

void SPlutoGameplayTagInspectorDocumentationPanel::ParseMarkdown(const FString& MarkdownText)
{
	TArray<FString> Lines;
	MarkdownText.Replace(TEXT("\r\n"), TEXT("\n")).ParseIntoArray(Lines, TEXT("\n"), false);

	bool bInCodeBlock = false;
	FString CodeBlockText;
	TArray<FString> ParagraphLines;

	for (const FString& RawLine : Lines)
	{
		const FString Line = RawLine;
		const FString TrimmedLine = Line.TrimStartAndEnd();

		if (TrimmedLine.StartsWith(TEXT("```")))
		{
			FlushParagraph(ParagraphLines);

			if (bInCodeBlock)
			{
				FPlutoGameplayTagDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
				Block.Type = EPlutoGameplayTagDocumentationBlockType::CodeBlock;
				Block.Text = CodeBlockText;
				CodeBlockText.Reset();
				bInCodeBlock = false;
			}
			else
			{
				bInCodeBlock = true;
			}

			continue;
		}

		if (bInCodeBlock)
		{
			if (!CodeBlockText.IsEmpty())
			{
				CodeBlockText.AppendChar(TEXT('\n'));
			}
			CodeBlockText += Line;
			continue;
		}

		if (TrimmedLine.IsEmpty())
		{
			FlushParagraph(ParagraphLines);
			continue;
		}

		auto AddHeading = [this, &TrimmedLine](EPlutoGameplayTagDocumentationBlockType HeadingType, int32 PrefixLength)
		{
			FPlutoGameplayTagDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
			Block.Type = HeadingType;
			Block.Text = TrimmedLine.RightChop(PrefixLength).TrimStartAndEnd();
		};

		if (TrimmedLine.StartsWith(TEXT("# ")))
		{
			FlushParagraph(ParagraphLines);
			AddHeading(EPlutoGameplayTagDocumentationBlockType::Heading1, 2);
			continue;
		}

		if (TrimmedLine.StartsWith(TEXT("## ")))
		{
			FlushParagraph(ParagraphLines);
			AddHeading(EPlutoGameplayTagDocumentationBlockType::Heading2, 3);
			continue;
		}

		if (TrimmedLine.StartsWith(TEXT("### ")))
		{
			FlushParagraph(ParagraphLines);
			AddHeading(EPlutoGameplayTagDocumentationBlockType::Heading3, 4);
			continue;
		}

		if (TrimmedLine.StartsWith(TEXT("- ")) || TrimmedLine.StartsWith(TEXT("* ")))
		{
			FlushParagraph(ParagraphLines);
			FPlutoGameplayTagDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
			Block.Type = EPlutoGameplayTagDocumentationBlockType::Bullet;
			Block.Text = TrimmedLine.RightChop(2).TrimStartAndEnd();
			continue;
		}

		ParagraphLines.Add(TrimmedLine);
	}

	FlushParagraph(ParagraphLines);

	if (bInCodeBlock)
	{
		FPlutoGameplayTagDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
		Block.Type = EPlutoGameplayTagDocumentationBlockType::CodeBlock;
		Block.Text = CodeBlockText;
	}
}

void SPlutoGameplayTagInspectorDocumentationPanel::FlushParagraph(TArray<FString>& ParagraphLines)
{
	if (ParagraphLines.Num() == 0)
	{
		return;
	}

	FPlutoGameplayTagDocumentationBlock& Block = DocumentBlocks.AddDefaulted_GetRef();
	Block.Type = EPlutoGameplayTagDocumentationBlockType::Paragraph;
	Block.Text = FString::Join(ParagraphLines, TEXT(" "));
	ParagraphLines.Reset();
}

FString SPlutoGameplayTagInspectorDocumentationPanel::GetDocumentPath() const
{
	const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("Pluto_GameplayTagInspector"));
	if (!Plugin.IsValid())
	{
		return FString();
	}

	const TCHAR* FileName = DocumentLanguage == EPlutoGameplayTagInspectorLanguage::Chinese
		? TEXT("PlutoGameplayTagInspector.zh-CN.md")
		: TEXT("PlutoGameplayTagInspector.en.md");

	return FPaths::Combine(Plugin->GetBaseDir(), TEXT("Docs"), FileName);
}

FText SPlutoGameplayTagInspectorDocumentationPanel::BuildStatusText() const
{
	return StatusText;
}

FText SPlutoGameplayTagInspectorDocumentationPanel::BuildLanguageButtonText() const
{
	return PlutoGameplayTagInspectorDocumentationText::Localized(
		DocumentLanguage == EPlutoGameplayTagInspectorLanguage::Chinese ? TEXT("切换到 English") : TEXT("切换到中文"),
		DocumentLanguage == EPlutoGameplayTagInspectorLanguage::Chinese ? TEXT("Switch to English") : TEXT("Switch to Chinese"));
}

FReply SPlutoGameplayTagInspectorDocumentationPanel::HandleReloadClicked()
{
	ReloadDocument();
	return FReply::Handled();
}

FReply SPlutoGameplayTagInspectorDocumentationPanel::HandleLanguageClicked()
{
	DocumentLanguage = DocumentLanguage == EPlutoGameplayTagInspectorLanguage::Chinese
		? EPlutoGameplayTagInspectorLanguage::English
		: EPlutoGameplayTagInspectorLanguage::Chinese;

	ReloadDocument();
	return FReply::Handled();
}

void SPlutoGameplayTagInspectorDocumentationPanel::RebuildDocumentView()
{
	if (!DocumentBoxWidget.IsValid())
	{
		return;
	}

	DocumentBoxWidget->ClearChildren();

	if (DocumentBlocks.Num() == 0)
	{
		DocumentBoxWidget->AddSlot()
		.AutoHeight()
		.Padding(0.0f, 8.0f, 0.0f, 0.0f)
		[
			SNew(STextBlock)
			.Text(PlutoGameplayTagInspectorDocumentationText::Localized(
				TEXT("当前没有可显示的文档内容。"),
				TEXT("There is no documentation content to display.")))
			.AutoWrapText(true)
		];
		return;
	}

	for (const FPlutoGameplayTagDocumentationBlock& Block : DocumentBlocks)
	{
		DocumentBoxWidget->AddSlot()
		.AutoHeight()
		.Padding(0.0f, 0.0f, 0.0f, 8.0f)
		[
			BuildBlockWidget(Block)
		];
	}

	if (ScrollBoxWidget.IsValid())
	{
		ScrollBoxWidget->ScrollToStart();
	}
}

TSharedRef<SWidget> SPlutoGameplayTagInspectorDocumentationPanel::BuildBlockWidget(const FPlutoGameplayTagDocumentationBlock& Block) const
{
	switch (Block.Type)
	{
	case EPlutoGameplayTagDocumentationBlockType::Heading1:
		return SNew(STextBlock)
			.Text(FText::FromString(Block.Text))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 18))
			.AutoWrapText(true);

	case EPlutoGameplayTagDocumentationBlockType::Heading2:
		return SNew(STextBlock)
			.Text(FText::FromString(Block.Text))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 15))
			.AutoWrapText(true);

	case EPlutoGameplayTagDocumentationBlockType::Heading3:
		return SNew(STextBlock)
			.Text(FText::FromString(Block.Text))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 13))
			.AutoWrapText(true);

	case EPlutoGameplayTagDocumentationBlockType::Bullet:
		return SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0.0f, 0.0f, 6.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("\x2022")))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(STextBlock)
				.Text(FText::FromString(Block.Text))
				.AutoWrapText(true)
			];

	case EPlutoGameplayTagDocumentationBlockType::CodeBlock:
		return SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Brushes.Recessed"))
			.Padding(8.0f)
			[
				SNew(SMultiLineEditableTextBox)
				.Text(FText::FromString(Block.Text))
				.IsReadOnly(true)
				.AutoWrapText(false)
			];

	case EPlutoGameplayTagDocumentationBlockType::Paragraph:
	default:
		return SNew(STextBlock)
			.Text(FText::FromString(Block.Text))
			.AutoWrapText(true);
	}
}
