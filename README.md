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

# Map Switcher 涓枃璇存槑

Map Switcher 鏄竴涓交閲忕骇 Unreal Engine 缂栬緫鍣ㄦ彃浠讹紝鐢ㄤ簬鍦?Level Editor 宸ュ叿鏍忎腑蹇€熸墦寮€浣犻厤缃ソ鐨勫湴鍥俱€?
## 鍔熻兘

- 鍦?Level Editor 宸ュ叿鏍忎腑娣诲姞涓€涓揣鍑戠殑鍦板浘鍒囨崲涓嬫媺鍥炬爣銆?- 鍙湪 Project Settings 涓厤缃樉绀哄悕绉板拰鍦板浘璧勬簮銆?- 鏃犻渶鍦?Content Browser 涓煡鎵撅紝鍗冲彲蹇€熸墦寮€甯哥敤鍦板浘銆?- 澶勭悊绌洪厤缃€佸湴鍥捐祫婧愮己澶便€侀潪娉曡矾寰勩€丳IE/SIE 杩愯涓瓑杈圭晫鎯呭喌銆?- 鍒囨崲鍦板浘鍓嶄娇鐢?Unreal 鏍囧噯鐨勬湭淇濆瓨淇敼鎻愮ず銆?
## 鍏煎鎬?
- Unreal Engine 5.6
- 浠呯紪杈戝櫒鎻掍欢锛屼笉褰卞搷鎵撳寘杩愯鏃?
## 瀹夎

### 鏂瑰紡 A锛氱洿鎺ュ厠闅嗗埌椤圭洰

鍦ㄤ綘鐨?Unreal 椤圭洰鏍圭洰褰曟墽琛岋細

```bash
git clone https://github.com/AlbertSkyer/ue-map-switcher.git Plugins/MapSwitcher
```

鐩綍缁撴瀯搴斾负锛?
```text
YourProject/
  Plugins/
    MapSwitcher/
      MapSwitcher.uplugin
      Source/
```

### 鏂瑰紡 B锛氫笅杞?ZIP

1. 涓嬭浇鏈粨搴撶殑 ZIP銆?2. 瑙ｅ帇鍒?Unreal 椤圭洰鐨?`Plugins` 鏂囦欢澶广€?3. 濡傛湁闇€瑕侊紝灏嗚В鍘嬪悗鐨勬枃浠跺す鏀瑰悕涓?`MapSwitcher`銆?
鏈€缁堣矾寰勫簲涓猴細

```text
YourProject/Plugins/MapSwitcher/MapSwitcher.uplugin
```

瀹夎鍚庯細

1. 濡傛湁闇€瑕侊紝閲嶆柊鐢熸垚椤圭洰鏂囦欢銆?2. 缂栬瘧浣犵殑 Editor target銆?3. 濡傛灉鎻掍欢娌℃湁鑷姩鍚敤锛屽湪 Plugins 绐楀彛涓惎鐢?`Map Switcher`銆?
## 閰嶇疆

鎵撳紑锛?
```text
Edit > Project Settings > Plugins > Map Switcher
```

鍦?`Levels` 涓坊鍔犳潯鐩細

- `Name`锛氫笅鎷夎彍鍗曚腑鏄剧ず鐨勫悕绉般€?- `Level`锛氳鎵撳紑鐨勫湴鍥捐祫婧愩€?
濡傛灉 `Name` 鐣欑┖锛屾彃浠朵細浣跨敤鍦板浘璧勬簮鍚嶄綔涓轰笅鎷夎彍鍗曟樉绀哄悕绉般€?
## 浣跨敤

鐐瑰嚮 Level Editor 宸ュ叿鏍忎腑鐨?Map Switcher 涓嬫媺鍥炬爣锛岀劧鍚庨€夋嫨宸查厤缃殑鍦板浘銆?
鎻掍欢浼氶樆姝㈠湪 PIE/SIE 杩愯涓垏鎹㈠湴鍥俱€傚鏋滃綋鍓嶅湴鍥炬湁鏈繚瀛樹慨鏀癸紝Unreal 浼氬厛鏄剧ず鏍囧噯淇濆瓨鎻愮ず锛屽啀鎵撳紑鐩爣鍦板浘銆?
## 璁稿彲璇?
MIT
