#pragma once

#include "Modules/ModuleManager.h"

class FPlutoSplineHelperEditorModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void HandleValidationFailed(class APlutoSplineWall* Wall);
	FDelegateHandle ValidationFailedHandle;
};
