# Map Switcher

Map Switcher is a lightweight Unreal Engine editor plugin that adds a configurable Level Editor toolbar dropdown for quickly opening project maps.

## Features

- Adds a small map-switching dropdown icon to the Level Editor toolbar.
- Lets you configure display names and map assets in Project Settings.
- Opens configured maps from the editor without searching the Content Browser.
- Handles empty configuration, missing map assets, invalid paths, and Play-In-Editor sessions.
- Uses Unreal's normal dirty-map prompt when switching maps.

## Compatibility

- Unreal Engine 5.6
- Editor-only plugin

## Installation

1. Copy this repository folder into your Unreal project under `Plugins/MapSwitcher`.
2. Regenerate project files if needed.
3. Build your editor target.
4. Enable `Map Switcher` in the Plugins window if it is not already enabled.

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
