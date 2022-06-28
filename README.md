# Nikumaru

Cave Story 'Hell' time extraction tool.

## Usage

Build binary with GNU Make

```
$ make
```

Install binary locally (will only work on \*NIX systems)

```
# make install
```

Parse freeware Cave Story `.rec` files

```
$ nikumaru
Time:   02:29.62
Frames: 7481
```

Parse Cave Story+ `.dat` files

```
$ nikumaru -p
Time:   02:59.00
Frames: 10740
```

The path of your `.rec` or `.dat` file may be ommited when invoking Nikumaru, as seen in the above examples.
In this case Nikumaru will default to reading from `Profile.dat` if the `csplus` flag is set, or `290.rec` otherwise.

## License

Nikumaru is licensed under the permissive MIT license, which can be seen [here](LICENSE).
