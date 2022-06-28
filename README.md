# Nikumaru

Cave Story `.rec` file parser.

## Usage

Build binary with GNU Make

```
$ make
```

Install binary locally (will only work on \*NIX systems)

```
# make install
```

Parse your `.rec` file!

```bash
$ nikumaru
Time:   02:29.62
Frames: 7481
```

The path of your `.rec` file may be ommited when invoking Nikumaru, as seen in the above example.
In this case Nikumaru will default to reading from `290.rec`, the default output path used by freeware Cave Story.

## License

Nikumaru is licensed under the permissive MIT license, which can be seen [here](LICENSE).
