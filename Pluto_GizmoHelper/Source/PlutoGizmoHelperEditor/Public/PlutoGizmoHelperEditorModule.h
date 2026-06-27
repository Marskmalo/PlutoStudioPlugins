#pragma once

#include "Modules/ModuleManager.h"

class FPlutoGizmoHelperEditorModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void RegisterDetailsCustomizations();
	void UnregisterDetailsCustomizations();
};
