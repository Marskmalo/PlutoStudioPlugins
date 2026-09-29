# Pluto Gizmo Helper 使用与协作文档

## 插件定位

`Pluto_GizmoHelper` 是一个通用的 Unreal Engine 碰撞范围可视化插件，用于在不修改原碰撞组件、不接管碰撞逻辑的前提下，为关卡策划和开发人员提供更清楚、可配置的 Gizmo。

当前版本聚焦 Collision Gizmo，支持：

- `UBoxComponent`
- `USphereComponent`
- `UCapsuleComponent`
- `UBrushComponent`，包括常见 Brush 与 Volume 的实际凸碰撞几何

插件不依赖 SOD Gameplay，也不依赖其他 Pluto 插件。它可以独立迁移到其他 UE 项目。

## 策划使用方式

### 创建与绑定

1. 在关卡中选择 Box、Sphere、Capsule 或 Brush 碰撞组件。
2. 在 Details 面板顶部找到 `Pluto 可视化` 分类。
3. 点击 `创建并绑定碰撞 Gizmo`。
4. 已存在相同绑定时，按钮会改为定位已有 Gizmo，不会重复创建。

Gizmo 是附加在原碰撞组件上的伴生组件。原组件仍然负责碰撞、Overlap、导航和 Gameplay；Gizmo 只负责显示。

当前 Blueprint 编辑器内的一键创建不是推荐路径。建议先在关卡实例中创建和验证绑定。

### 显示方式

- `始终显示`：在编辑器和 PIE 中持续显示；Development 独立程序还需要启用全局控制台变量。
- `仅编辑器选中时`：只有所属对象在编辑器中被选中时显示，在 PIE 与独立程序中隐藏。
- `启用 Gizmo`：控制当前伴生组件是否参与可视化。

全局控制台命令：

```text
pluto.Gizmo.Collision 0
pluto.Gizmo.Collision 1
```

- 编辑器和 PIE 默认开启。
- 独立 Development 构建默认关闭，需要使用控制台命令开启。
- Shipping 不创建 Scene Proxy，不注册该 CVar，也不执行 Gizmo 同步 Tick。

### 样式配置

默认样式：

- 绘制线框：开启
- 线框颜色：青色 `#00FFFF`
- 线框粗细：`1.5`
- 绘制填充：开启
- 填充颜色：青色，颜色 Alpha 为 `0.1`
- 填充透明度：`0.15`

组件未启用 `覆盖项目默认样式` 时，会读取：

```text
项目设置 > Plugins > Pluto Gizmo Helper
```

启用覆盖后，可以为单个 Gizmo 设置颜色、线宽与透明度。Details 与 Blueprint Setter 的修改会立即刷新渲染状态。

### Brush 与 Volume

Brush Gizmo 读取 `BrushComponent` 的 `BodySetup->AggGeom.ConvexElems`，显示实际凸碰撞几何，而不是只显示 Bounds。

- 填充层按照凸体三角形绘制。
- 线框只保留边界和折角，过滤共面三角化产生的对角线。
- 凸分解产生的分块接缝可能仍然可见，这是实际碰撞结构的一部分。
- Brush 必须具有有效的 BodySetup 和凸碰撞数据，否则不会生成可视化几何。

## 常见问题

### PIE 中角色 Capsule 不显示

Gizmo 会优先通过附着父组件解析 PIE 世界中的碰撞组件，然后尝试同 Actor 引用和同名组件回退。这样可以避免 `FComponentReference` 的编辑器弱引用在 PIE 复制后仍指向编辑器世界对象。

如果仍不显示，请依次检查：

- Gizmo 的显示方式是否为 `始终显示`。
- `启用 Gizmo` 是否开启。
- 控制台变量 `pluto.Gizmo.Collision` 是否为 `1`。
- Gizmo 是否仍附着在目标碰撞组件下。
- 目标与 Gizmo 是否属于同一个 Actor。

### 修改项目默认样式后没有变化

检查实例是否开启了 `覆盖项目默认样式`。开启后，实例样式优先于项目设置。

### 填充看起来比预期更透明

最终填充 Alpha 为 `FillColor.A * FillOpacity`。两个值都会影响最终透明度。

## 智能体与程序维护信息

### 模块职责

- `PlutoGizmoHelperRuntime`
  - `UPlutoCollisionGizmoComponent`
  - Scene Proxy 与碰撞形状渲染
  - 项目默认样式
  - Blueprint/C++ Setter
  - CVar 与构建配置行为
- `PlutoGizmoHelperEditor`
  - Details 定制与一键绑定
  - 中英文界面切换
  - 编辑器通知、选择与刷新

Runtime 模块不得依赖 UnrealEd、PropertyEditor 或 SOD 私有模块。Editor 注册与注销必须成对维护。

### 核心数据流

```text
原碰撞组件
  -> UPlutoCollisionGizmoComponent 解析目标与样式
  -> 创建只读 RenderData
  -> FPrimitiveSceneProxy 在渲染线程绘制填充与线框
```

伴生组件本身必须保持：

- `NoCollision`
- 不生成 Overlap
- 不影响导航
- 不复制
- 不改变目标碰撞组件属性

### 目标解析规则

运行时按以下顺序寻找目标：

1. 同 Actor 且类型受支持的附着父组件。
2. `FComponentReference` 在当前 Owner 上解析出的组件。
3. 当前 Owner 中与 `ComponentProperty` 同名的受支持组件。

不要移除第一步。它是关卡实例伴生组件进入 PIE 后稳定绑定角色 Capsule 等运行时副本的关键。

### Brush 渲染规则

- 数据来源是 `UBrushComponent::GetBodySetup()` 的 `AggGeom.ConvexElems`。
- Scene Proxy 只持有复制后的顶点、索引和边数据，不在渲染线程读取 UObject。
- 共面三角形共享边不进入线框；边界边和法线明显不同的折角边会保留。
- Brush 几何签名包含 Transform、凸体 Bounds、顶点和索引；形状变化后才重建渲染状态。
- 不应为了支持 Brush 而调用 `BuildSimpleBrushCollision()`，插件只能观察现有碰撞数据，不能修改目标资产或 Actor。

### 公开接口

主要 Blueprint/C++ 接口：

- `SetTargetCollision`
- `SetGizmoEnabled`
- `SetOutlineColor`
- `SetLineThickness`
- `SetFillColor`
- `SetFillOpacity`
- `SetDrawOutline`
- `SetDrawFill`
- `SetStyle`
- `RefreshGizmo`

新增公开 Blueprint 函数时，按项目规范使用 `PF_` 前缀和 `Pluto|<Plugin>|<Feature>` Category；修改已有序列化接口前必须评估 Blueprint 兼容性。

### 本地化

- 默认语言为中文。
- 语言设置保存在 `EditorPerProjectUserSettings`。
- 切换语言只刷新插件 Details，不修改 Unreal 全局 Culture。
- 新增 Details 标签、按钮、Tooltip、通知或警告时，应同时维护中文与英文文本。

### 版本与构建

当前源码要求兼容：

- Unreal Engine 5.7
- Unreal Engine 5.8

涉及 Engine API 的修改至少应验证：

- UE 5.7：Editor、Development、Shipping
- UE 5.8：Editor、Development、Shipping

项目编辑器正在运行时，项目目录中的插件 DLL 可能被锁定。可以先通过 `BuildPlugin` 输出到临时目录完成兼容性验证，关闭编辑器后再执行项目目标构建。

### 功能边界

当前不包含：

- 自定义多边形或 Spline 空气墙生成
- 技能、AI、任务区域语义
- X-Ray 显示
- 交互式形状控制柄
- 正式游戏表现或运行时特效
- 对原始碰撞响应、物理和 Overlap 的修改

Spline 空气墙属于 `Pluto_SplineHelper`，不应把其几何生成与碰撞业务重新耦合到本插件。

## 修改后的验证清单

- Box、Sphere、Capsule、Brush 分别能够创建并绑定 Gizmo。
- 编辑器与 PIE 中，目标 Transform、尺寸和 Gizmo 样式能够热更新。
- 角色 Capsule 在 PIE 中使用 `始终显示` 时持续可见。
- Brush 显示实际凸碰撞，且共面三角形对角线不会污染线框。
- `仅编辑器选中时` 不会在 PIE 中显示。
- 项目默认样式更新能刷新未覆盖样式的实例。
- CVar 能立即控制全部 Collision Gizmo。
- Development 默认关闭，手动开启后显示。
- Shipping 不创建渲染和同步开销。
- 中英文切换后 Details 文本即时刷新。
- Unreal 原生 Collision Debug 与本插件可以同时使用，互不接管。

## 文档维护

本文档位于：

```text
Plugins/PlutoStudio/Pluto_GizmoHelper/Docs/PlutoGizmoHelper.zh-CN.md
```

修改插件的功能边界、公开接口、配置入口、默认值、构建支持或关键实现约束时，必须在同一次变更中更新本文档。

