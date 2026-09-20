#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SScrollBox;
class SVerticalBox;
class SWidget;

enum class EPlutoAssetNamingDocumentationBlockType : uint8
{
	Heading1,
	Heading2,
	Heading3,
	Paragraph,
	Bullet,
	CodeBlock
};

struct FPlutoAssetNamingDocumentationBlock
{
	EPlutoAssetNamingDocumentationBlockType Type = EPlutoAssetNamingDocumentationBlockType::Paragraph;
	FString Text;
};

class SPlutoAssetNamingHelperDocumentationPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPlutoAssetNamingHelperDocumentationPanel) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	void ReloadDocument();
	void ParseMarkdown(const FString& MarkdownText);
	void FlushParagraph(TArray<FString>& ParagraphLines);
	FString GetDocumentPath() const;
	FText BuildStatusText() const;
	FReply HandleReloadClicked();
	void RebuildDocumentView();
	TSharedRef<SWidget> BuildBlockWidget(const FPlutoAssetNamingDocumentationBlock& Block) const;

private:
	TSharedPtr<SScrollBox> ScrollBoxWidget;
	TSharedPtr<SVerticalBox> DocumentBoxWidget;
	TArray<FPlutoAssetNamingDocumentationBlock> DocumentBlocks;
	FText StatusText;
};
