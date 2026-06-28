# Pluto GameplayTag Inspector Documentation

## Purpose

`Pluto GameplayTag Inspector` is a visual inspector for real `GameplayTag` data on an Actor.

It focuses on three practical problems:

- Inspect which `GameplayTagContainer` values an Actor currently exposes in the editor
- Show standalone `GameplayTag` values under the bottom `Isolated Tags` group
- Keep Provider-based integration as an advanced fallback, not the primary setup path

It is not a SOD-only plugin, and it is not a GAS debugger.
The goal is to stay close to Unreal's native `GameplayTag` workflow and remain reusable across projects.

## Design boundaries

This plugin should be understood in the following way:

- It focuses on real `GameplayTagContainer` values and real standalone `GameplayTag` values
- It does not depend on `AbilitySystemComponent`
- It does not require the target object to be `SOD_Actor` or `SOD_Character`
- Its tree view is meant to show `Container -> Tag`
- It is not intended to reinterpret unrelated bools, enums, strings, or state variables as tags

The easiest misunderstanding is this:

- `IGameplayTagAssetInterface` can provide an owned-tag aggregate view
- It cannot naturally tell the inspector which exact container each tag came from

Because of that, the plugin primarily uses automatic scanning:

- Scan reflected `FGameplayTagContainer` properties on Actors and Components
- Scan containers nested in reflected structs, arrays, and map values
- Scan standalone `FGameplayTag` values into the `Isolated Tags` group
- Fall back to an owned-tag summary view when needed
- Use `PlutoGameplayTagContainerProvider` only as an advanced escape hatch when real containers cannot be discovered automatically

This means:

- Reflection-only targets already work in many common cases
- Provider implementations should expose existing gameplay tag containers, not translate unrelated gameplay variables into tags

## How to use the Inspector

### 1. Open the tool

From the `Pluto` menu in the editor top bar, you can open:

- `Pluto GameplayTag Inspector`
- `Pluto GameplayTag Inspector Documentation`

The Inspector is also available from the `Window` menu.

The Inspector supports up to 3 simultaneous panel instances. Different instances can lock different Actors, which is useful when comparing gameplay tag data across multiple objects. When all 3 instances are already open, the open command focuses the third instance.

### 2. Pick an observed Actor

The top-left Actor picker supports:

- Selecting an Actor from the picker field
- Using the eyedropper to choose an Actor in the level
- Clearing the current target

When no valid Actor is available, the Inspector shows an explicit status message instead of an empty silent panel.

### 3. Lock / Unlock

- `Lock`: keep observing the current target and stop following editor selection changes
- `Unlock`: resume following the current editor selection

If there is no valid observed Actor, the lock button is disabled.

### 4. Refresh and Auto Refresh

- `Refresh`: immediately re-read tag data from the target object
- `Auto Refresh`: check for data changes on the editor project-level tick

The current implementation is not a simple fixed 0.5 second poll.
It follows the editor main loop and compares a lightweight data revision before rebuilding the tree.

That means:

- Tag changes should show up quickly
- The tree is not rebuilt every frame when nothing changed

### 5. Search

The search box can filter:

- Container names
- Tag text

Search only filters the visible view.
It does not modify the target object.

### 6. Reading the tree view

The tree is organized as `Container -> Tag`:

- Each root item represents one `GameplayTagContainer`
- Child items represent the current tags inside that container
- Standalone tags are collected under the bottom `Isolated Tags` root

Container source paths use explicit labels:

- array item: `PhaseTagGroups[Index 0]`
- map item: `EnemyTypeTags[Key Goblin]`

Tag colors are derived from the tag itself, usually by tag prefix, not by the owning container.

## Inspector-coupled Blueprint functions

This section only documents Blueprint functions that are coupled to the Inspector plugin itself.
General-purpose gameplay tag editing, batch add/remove, query, or change-detection helpers belong to `PlutoFunctionLibrary`, not to this Inspector plugin, so they are intentionally not documented here.

### PF_FindGameplayTagContainerName

Purpose:

- Try to resolve the name or path of a target container on an object

Notes:

- When reflection data is available, the function prefers returning a property path string
- When the provider interface is used, the resolved name may come from that provider data

### PF_GetInspectableGameplayTagContainers

Purpose:

- Collect inspectable container descriptors from a target object using the plugin's hybrid strategy

This function is mainly intended for tooling and debugging workflows.

It returns container-style data only. Standalone `FGameplayTag` values are displayed by the Inspector UI under `Isolated Tags`, but they are not exposed through this container-specific helper.

## Recommended integration

In most projects, no custom interface is required. Prefer readable reflected data first:

- Keep readable `FGameplayTagContainer` properties on the object
- Keep readable `FGameplayTagContainer` properties on Actor Components
- Use arrays or maps whose value type is `FGameplayTagContainer` when you need named groups
- Use standalone `FGameplayTag` properties when the value is truly a single tag; the Inspector will place them under `Isolated Tags`

Only implement `PlutoGameplayTagContainerProvider` when a real container exists but automatic scanning cannot reach it.

It is best to think of the Inspector as an observation layer, not a direct editing layer.
Its current strength is reading, organizing, and diagnosing tag data.

## Common misunderstandings

### 1. OwnedGameplayTags is not the same as a full container tree

The aggregate owned-tag view only tells you which tags the object has.
It does not automatically explain which container produced each tag.

### 2. Reflection scanning is helpful, but not universal

If containers live inside complex nesting, temporary runtime-only structures, or data that is not visible through the expected reflection path, the Inspector may not fully reconstruct the tree.

### 3. PlutoFunctionLibrary functions are intentionally not documented here

General-purpose `GameplayTagContainer` nodes complement Unreal's native workflow, but they are not Inspector features.
For example, batch add/remove and common gameplay tag queries are part of `PlutoFunctionLibrary`, so this document only keeps Inspector-coupled PF functions.

### 4. This plugin does not introduce GAS

You do not need:

- `AbilitySystemComponent`
- `GameplayAbility`
- `GameplayEffect`

The plugin still works in projects that do not use GAS at all.

## How the docs are maintained

This page is loaded from a Markdown file inside the plugin folder.

You can modify this file directly:

- `Plugins/Pluto_GameplayTagInspector/Docs/PlutoGameplayTagInspector.en.md`

After editing the file, open the documentation window and click `Reload` to read the latest content again.

If the file is missing, the documentation window will show a clear missing-file message and the expected path.
