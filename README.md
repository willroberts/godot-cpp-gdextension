# godot-cpp-gdextension

This is an example of leveraging C++ in Godot via GDExtension.

Using C++ in this way allows us to isolate performance-critical pieces of game logic in C++ while still using the native GDScript Godot binary. This removes the need to use Mono, striking a good balance between compatibility and performance while fully supporting the Android, iOS, and WebGL platforms.

Based on David Snopek's GDExtension workshop at GodotCon 2024.

## General Flow

1. Create a new extension repo using the [godot-cpp-template](https://github.com/godotengine/godot-cpp-template). This will leverage the official [godot-cpp](https://github.com/godotengine/godot-cpp) bindings.
2. Update `EXTENSION-NAME` throughout the repo with your desired name.
3. Add your classes to the `src/` directory, and update `register_types.cpp`. See this repo for examples.
4. Build the project by running `scons`. This will output binaries to `demo/bin`.
5. Reference the new C++ classes in GDScript directly by name in the `demo/` project.

Note: In Godot 4.3 and older, you may need to use the `Reload Project` feature to enable auto-complete in GDScript. This will be fixed in Godot 4.4.

## Hot Reloading

To enable hot reloading, add `reloadable = true` under the `[configuration]` section of the `.gdextension` file. With this enabled, recompiling will automatically reflect updates in the editor.

## Generating Docs

To generate docs for C++ GDExtensions, use the Godot binary from the directory where the compiled GDExtension lives:
```
cd demo
godot --doctool .. --gdextension-docs
```