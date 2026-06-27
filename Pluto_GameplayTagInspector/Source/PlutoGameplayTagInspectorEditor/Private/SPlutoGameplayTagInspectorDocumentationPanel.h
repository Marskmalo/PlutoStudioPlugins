#pragma once

#include "CoreMinimal.h"
#include "PlutoGameplayTagInspectorEditorSettings.h"
#include "Widgets/SCompoundWidget.h"

class SScrollBox;
class SWidget;
class SVerticalBox;

enum class EPlutoGameplayTagDocumentationBlockType : uint8
{
	Heading1,
	Heading2,
	Heading3,
	Paragraph,
	Bullet,
	CodeBlock
};

struct FPlutoGameplayTagDocumentationBlock
{
	EPlutoGameplayTagDocumentationBlockType Type = EPlutoGameplayTagDocumentationBlockType::Paragraph;
	FString Text;
};

class SPlutoGameplayTagInspectorDocumentationPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPlutoGameplayTagInspectorDocumentationPanel)
	{
	}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	void ReloadDocument();
	void ParseMarkdown(const FString& MarkdownText);
	void FlushParagraph(TArray<FString>& ParagraphLines);
	FString GetDocumentPath() const;
	FText BuildStatusText() const;
	FText BuildLanguageButtonText() const;
	FReply HandleReloadClicked();
	FReply HandleLanguageClicked();
	void RebuildDocumentView();
	TSharedRef<SWidget> BuildBlockWidget(const FPlutoGameplayTagDocumentationBlock& Block) const;

private:
	TSharedPtr<SScrollBox> ScrollBoxWidget;
	TSharedPtr<SVerticalBox> DocumentBoxWidget;
	TArray<FPlutoGameplayTagDocumentationBlock> DocumentBlocks;
	FText StatusText;
	EPlutoGameplayTagInspectorLanguage DocumentLanguage = EPlutoGameplayTagInspectorLanguage::Chinese;
};
