# Pluto GameplayTag Inspector 使用文档

## 这个插件解决什么问题

`Pluto GameplayTag Inspector` 是一个用于观察真实 `GameplayTag` 数据的可视化检查器。

它主要解决三个实际问题：

- 在编辑器里查看某个 Actor 当前暴露了哪些 `GameplayTagContainer`
- 将单个 `GameplayTag` 统一显示在树状图底部的「孤立Tag」分组中
- 将 Provider 接入保留为高级逃生口，而不是普通使用入口

它不是 SOD 专用插件，也不是 GAS 调试器。
这个插件的目标是尽量贴近 Unreal 原生 `GameplayTag` 工作流，同时保持跨项目可复用。

## 设计边界

请优先这样理解这个插件：

- 它聚焦的是真实 `GameplayTagContainer` 和真实单个 `GameplayTag`
- 它不依赖 `AbilitySystemComponent`
- 它不要求目标对象必须是 `SOD_Actor` 或 `SOD_Character`
- 它的树状视图目标是展示 `Container -> Tag`
- 它不负责把无关的 bool、enum、string 或普通业务状态重新解释成 GameplayTag

最容易被误解的一点是：

- `IGameplayTagAssetInterface` 可以提供一个 OwnedTag 聚合视图
- 但它不能天然告诉 Inspector 每个 Tag 具体来自哪个容器

因此，这个插件的主路径是自动扫描：

- 扫描 Actor 和 Actor Component 上反射可见的 `FGameplayTagContainer`
- 扫描结构体、数组、Map Value 中嵌套的 `FGameplayTagContainer`
- 将单个 `FGameplayTag` 收集到「孤立Tag」分组
- 在必要时退回到 OwnedTag 汇总视图
- 只有自动扫描无法发现真实容器时，才使用 `PlutoGameplayTagContainerProvider` 作为高级逃生口

这意味着：

- 只靠反射的对象在很多常见场景下也能工作
- Provider 应用于暴露已有的真实 GameplayTagContainer，不应用于把无关业务变量翻译成 Tag

## 如何使用 Inspector

### 1. 打开工具

你可以在编辑器顶部菜单栏的 `Pluto` 菜单中打开：

- `Pluto GameplayTag Inspector`
- `Pluto GameplayTag Inspector Documentation`

Inspector 也可以从 `Window` 菜单中打开。

Inspector 支持同时打开最多 3 个面板实例。你可以让不同实例锁定不同 Actor，用于并排比较多个对象的 GameplayTag 数据。超过 3 个实例后，再次点击打开命令会聚焦第 3 个实例。

### 2. 选择观察目标 Actor

左上角的 Actor 选择器支持：

- 从选择框中选 Actor
- 使用吸管在场景里选择 Actor
- 清空当前目标

当没有有效 Actor 时，Inspector 会显示明确的状态提示，而不是一个空白面板。

### 3. Lock / Unlock

- `Lock`：锁定当前观察对象，不再跟随编辑器选中变化
- `Unlock`：解除锁定，重新跟随当前编辑器选中对象

如果当前没有有效观察对象，锁定按钮会被禁用。

### 4. Refresh 和 Auto Refresh

- `Refresh`：立即重新读取一次目标对象的 Tag 数据
- `Auto Refresh`：在编辑器级 Tick 中自动检查数据变化

当前实现不是一个固定 0.5 秒轮询。
它会跟随编辑器主循环，并在重建树之前先比较轻量级的数据版本。

这意味着：

- Tag 变化通常会较快显示出来
- 如果数据没有变化，树不会每帧都重建

### 5. Search

搜索框可以过滤：

- 容器名称
- Tag 文本

搜索只会影响当前可见视图，不会修改目标对象的数据。

### 6. 如何理解树状视图

树状视图按 `Container -> Tag` 组织：

- 每个根节点表示一个 `GameplayTagContainer`
- 子节点表示该容器当前持有的 Tag
- 单个 `FGameplayTag` 会收集到最底部的「孤立Tag」根节点

Tag 的颜色通常由 Tag 本身的前缀决定，而不是由所属容器决定。

容器来源路径会使用明确标签来避免歧义：

- 数组元素：`PhaseTagGroups[Index 0]`
- Map 元素：`EnemyTypeTags[Key Goblin]`

## 和 Inspector 耦合的 Blueprint 函数

本节只记录和 Inspector 插件自身耦合的 Blueprint 函数。
通用的 GameplayTag 编辑、批量增删、查询、变化检测等辅助函数属于 `PlutoFunctionLibrary`，不是 Inspector 插件功能，因此不在本文档中展开。

### PF_FindGameplayTagContainerName

作用：

- 尝试获取某个容器在目标对象上的名称或路径

说明：

- 当存在反射路径时，函数会优先返回属性路径字符串
- 当目标对象通过 Provider 接口提供容器数据时，也可能返回接口给出的命名

### PF_GetInspectableGameplayTagContainers

作用：

- 按插件的混合策略收集目标对象上的可观察容器描述列表

这个函数主要面向工具与调试工作流。

说明：

- 这个函数只返回容器类数据
- 单个 `FGameplayTag` 会由 Inspector UI 显示在「孤立Tag」分组中，但不会通过这个容器专用函数返回

## 推荐接入方式

大多数项目不需要自定义接口。建议优先保留可反射的数据：

- 在对象上保留可读的 `FGameplayTagContainer` 属性
- 在 Actor Component 上保留可读的 `FGameplayTagContainer` 属性
- 需要分组时，使用 Value 类型为 `FGameplayTagContainer` 的数组或 Map
- 如果某个值本来就是单个真实 `FGameplayTag`，可以直接保留为单 Tag 属性，Inspector 会将它放入「孤立Tag」

只有当真实容器存在，但自动扫描无法触达时，才建议实现 `PlutoGameplayTagContainerProvider`。

更适合把 Inspector 理解为“观察层”，而不是“编辑层”。
它当前的优势是读取、组织和诊断 Tag 数据，而不是直接在工具面板里修改标签。

## 常见误解

### 1. OwnedGameplayTags 不等于完整的容器树

OwnedTag 聚合视图只能告诉你对象当前拥有哪些 Tag。
它不会自动告诉你这些 Tag 分别来自哪个容器。

### 2. 反射扫描很有用，但不是万能的

如果容器藏在复杂嵌套、临时运行时结构，或没有暴露到可扫描路径的数据里，Inspector 可能无法完整还原树状结构。

### 3. PlutoFunctionLibrary 函数不在本文档中展开

通用 `GameplayTagContainer` 节点是对 Unreal 原生工作流的补充，不是 Inspector 自身功能。
例如批量增删、通用查询、变化检测等函数由 `PlutoFunctionLibrary` 提供；本文档只保留和 Inspector 插件耦合的 PF 函数。

### 4. 这个插件不引入 GAS

你不需要：

- `AbilitySystemComponent`
- `GameplayAbility`
- `GameplayEffect`

即使项目里没有 GAS，这个插件也可以正常工作。

## 文档如何维护

这个页面来自插件目录中的 Markdown 文件。

你可以直接修改这个文件：

- `Plugins/Pluto_GameplayTagInspector/Docs/PlutoGameplayTagInspector.zh-CN.md`

修改后，如果想在编辑器里重新读取最新内容：

- 打开文档窗口
- 点击 `Reload`

如果文件缺失，文档窗口会明确显示缺失状态和预期路径。
