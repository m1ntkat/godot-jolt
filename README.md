# ![Godot Jolt][bnr]

Godot Jolt is a native extension for the [Godot game engine][gdt] (4.0 and later) that allows you to
use the [Jolt physics engine][jlt] to power Godot's 3D physics.

⚠️ Godot Jolt is still unfinished and not ready to be used in a production environment.

## Features

Godot Jolt is primarily meant to be a drop-in replacement for Godot Physics, utilizing the same node
types that you would use today, such as `StaticBody3D` or `RigidBody3D`. However, due to mismatching
feature sets between Godot Physics and Jolt there will be certain gaps in functionality, such as a
lack of support for `SoftBody3D` amongst other things.

You can track the progress of this work [here][cpb].

## Compatibility

Godot Jolt only supports the current stable version of Godot 4 and might not work with other
versions due to potential API differences in the GDExtension API.

Currently only the major desktop platforms are supported. These include:

- Windows (x86-64, x86)
- Linux (x86-64, x86)
- macOS (x86-64 + Apple Silicon)

## Download

Due to the current state of Godot Jolt there are no precompiled binaries available for download.
Eventually they will be provided here on GitHub and wherever Godot allows distribution of native
extensions.

## Configure

See [`docs/settings.md`][set] for information about the project settings that Godot Jolt offers.

## Build

See [`docs/building.md`][bld] for information about how to build Godot Jolt from source.

## License

This project is licensed under the MIT license. See [`LICENSE.txt`][lic] for details. See
[`THIRDPARTY.txt`][tdp] for third-party licenses and copyright notices.

[bnr]: docs/banner.png
[gdt]: https://godotengine.org/
[jlt]: https://github.com/jrouwe/JoltPhysics
[cpb]: https://github.com/godot-jolt/godot-jolt/issues/117
[set]: docs/settings.md
[bld]: docs/building.md
[lic]: LICENSE.txt
[tdp]: THIRDPARTY.txt
