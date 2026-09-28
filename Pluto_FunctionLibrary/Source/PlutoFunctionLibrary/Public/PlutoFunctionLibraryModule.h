#pragma once

#include "Modules/ModuleManager.h"

class FPlutoFunctionLibraryModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
