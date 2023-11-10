## Requirements

- `ncurses`
- build environment (`base-devel` for Arch Linux)
- `cmake`
- `clang++`
- `nix` (optional)

For Windows, please see the `pdcurses` branch.

## Usage

```bash
mkdir bin && cd $_
cmake -DCMAKE_CXX_COMPILER=clang++ ..
cmake --build .
```