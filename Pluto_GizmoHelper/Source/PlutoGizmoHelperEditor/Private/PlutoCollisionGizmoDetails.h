#pragma once

#include "IDetailCustomization.h"

class UPlutoCollisionGizmoComponent;
class UShapeComponent;

class FPlutoShapeComponentDetails final : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	FReply HandleCreateOrLocate();
	UPlutoCollisionGizmoComponent* FindExistingGizmo(FName* OutTargetVariableName = nullptr) const;
	bool ResolveSubobjectContext(
		UObject*& OutContext,
		class UBlueprint*& OutBlueprint,
		struct FSubobjectDataHandle& OutTargetHandle,
		FName& OutTargetVariableName) const;

	TWeakObjectPtr<UShapeComponent> TargetComponent;
	IDetailLayoutBuilder* DetailBuilderPtr = nullptr;
};

class FPlutoCollisionGizmoComponentDetails final : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
};

class FPlutoGizmoHelperSettingsDetails final : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
};

class FPlutoGizmoHelperEditorSettingsDetails final : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
};
