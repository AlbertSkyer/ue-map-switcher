# Map Switcher

Map Switcher is a lightweight Unreal Engine editor plugin for quickly opening configured maps from the Level Editor toolbar.

## Features

- Adds a compact map-switching dropdown icon to the Level Editor toolbar.
- Lets you configure display names and map assets in Project Settings.
- Opens configured maps without searching the Content Browser.
- Handles empty configuration, missing map assets, invalid paths, and Play-In-Editor sessions.
- Uses Unreal's standard dirty-map prompt before switching maps.

## Compatibility

- Unreal Engine 5.6
- Editor-only plugin

## Installation

### Option A: Clone into your project

From your Unreal project root:

```bash
git clone https://github.com/AlbertSkyer/ue-map-switcher.git Plugins/MapSwitcher
```

Your project should look like this:

```text
YourProject/
  Plugins/
    MapSwitcher/
      MapSwitcher.uplugin
      Source/
```

### Option B: Download ZIP

1. Download this repository as a ZIP file.
2. Extract it into your Unreal project's `Plugins` folder.
3. Rename the extracted folder to `MapSwitcher` if needed.

Final path:

```text
YourProject/Plugins/MapSwitcher/MapSwitcher.uplugin
```

After installing:

1. Regenerate project files if needed.
2. Build your editor target.
3. Enable `Map Switcher` in the Plugins window if it is not already enabled.

## Configuration

Open:

```text
Edit > Project Settings > Plugins > Map Switcher
```

Add entries to `Levels`:

- `Name`: The label shown in the dropdown.
- `Level`: The map asset to open.

If `Name` is empty, the plugin uses the map asset name as the dropdown label.

## Usage

Click the Map Switcher dropdown icon in the Level Editor toolbar and select a configured map.

The plugin blocks map switching while PIE/SIE is active. If the current map has unsaved changes, Unreal's standard save prompt is shown before loading the selected map.

## License

MIT

---

# Map Switcher 中文说明

Map Switcher 是一个轻量级 Unreal Engine 编辑器插件，用于在 Level Editor 工具栏中快速打开你配置好的地图。

## 功能

- 在 Level Editor 工具栏中添加一个紧凑的地图切换下拉图标。
- 可在 Project Settings 中配置显示名称和地图资源。
- 无需在 Content Browser 中查找，即可快速打开常用地图。
- 处理空配置、地图资源缺失、非法路径、PIE/SIE 运行中等边界情况。
- 切换地图前使用 Unreal 标准的未保存修改提示。

## 兼容性

- Unreal Engine 5.6
- 仅编辑器插件，不影响打包运行时

## 安装

### 方式 A：直接克隆到项目

在你的 Unreal 项目根目录执行：

```bash
git clone https://github.com/AlbertSkyer/ue-map-switcher.git Plugins/MapSwitcher
```

目录结构应为：

```text
YourProject/
  Plugins/
    MapSwitcher/
      MapSwitcher.uplugin
      Source/
```

### 方式 B：下载 ZIP

1. 下载本仓库的 ZIP。
2. 解压到 Unreal 项目的 `Plugins` 文件夹。
3. 如有需要，将解压后的文件夹改名为 `MapSwitcher`。

最终路径应为：

```text
YourProject/Plugins/MapSwitcher/MapSwitcher.uplugin
```

安装后：

1. 如有需要，重新生成项目文件。
2. 编译你的 Editor target。
3. 如果插件没有自动启用，在 Plugins 窗口中启用 `Map Switcher`。

## 配置

打开：

```text
Edit > Project Settings > Plugins > Map Switcher
```

在 `Levels` 中添加条目：

- `Name`：下拉菜单中显示的名称。
- `Level`：要打开的地图资源。

如果 `Name` 留空，插件会使用地图资源名作为下拉菜单显示名称。

## 使用

点击 Level Editor 工具栏中的 Map Switcher 下拉图标，然后选择已配置的地图。

插件会阻止在 PIE/SIE 运行中切换地图。如果当前地图有未保存修改，Unreal 会先显示标准保存提示，再打开目标地图。

## 许可证

MIT