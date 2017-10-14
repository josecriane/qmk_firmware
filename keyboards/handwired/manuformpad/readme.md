ManuformPad keyboard firmware
======================

## Quantum MK Firmware

For the full Quantum feature list, see [the parent readme.md](/readme.md).

### Default
To build with the default keymap, simply run `make handwired/manuformpad:default`.

### Other Keymaps
Several version of keymap are available in advance but you are recommended to define your favorite layout yourself. To define your own keymap create file named `<name>.c` in the keymaps folder, and see keymap document (you can find in top readme.md) and existent keymap files.

To build the firmware binary hex file with a keymap just do `make handwired/manuformpad:default` with a keymap like this:

```
$ make handwired/manuformpad:default
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
