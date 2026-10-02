#include "PlutoFunctionLibraryModule.h"

#include "Modules/ModuleManager.h"
#include "UObject/CoreRedirects.h"

void FPlutoFunctionLibraryModule::StartupModule()
{
	// Preserve existing Blueprint connections when reconstructing the renamed parameter.
	const FCoreRedirect Redirects[] = {
		FCoreRedirect(ECoreRedirectFlags::Type_Property,
			TEXT("PlutoSelectionFunctionLibrary.PF_ResolveLatestActivatedPair.State"),
			TEXT("PlutoSelectionFunctionLibrary.PF_ResolveLatestActivatedPair.Snapshot"))
	};
	FCoreRedirects::AddRedirectList(Redirects, TEXT("PlutoFunctionLibrary"));
}

void FPlutoFunctionLibraryModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FPlutoFunctionLibraryModule, PlutoFunctionLibrary)
