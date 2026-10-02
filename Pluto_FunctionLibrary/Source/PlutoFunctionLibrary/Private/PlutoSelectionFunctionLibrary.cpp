#include "PlutoSelectionFunctionLibrary.h"

void UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(
	const bool bAActive,
	const bool bBActive,
	FPlutoLatestActivatedPairState& Snapshot,
	bool& bADominant,
	bool& bBDominant,
	const bool bPreferAOnSimultaneousActivation)
{
	bool bSelectA = false;
	if (bAActive && bBActive)
	{
		const bool bAJustActivated = !Snapshot.bPreviousAActive;
		const bool bBJustActivated = !Snapshot.bPreviousBActive;
		if (bAJustActivated && bBJustActivated)
		{
			bSelectA = bPreferAOnSimultaneousActivation;
		}
		else if (bAJustActivated || bBJustActivated)
		{
			bSelectA = bAJustActivated;
		}
		else
		{
			bSelectA = Snapshot.bPreviousADominant;
		}
	}
	else
	{
		bSelectA = bAActive;
	}

	bADominant = bSelectA;
	bBDominant = bBActive && !bSelectA;
	Snapshot.bPreviousAActive = bAActive;
	Snapshot.bPreviousBActive = bBActive;
	Snapshot.bPreviousADominant = bSelectA;
}
