# school

## Requirements

- `ncurses`
- build environment (`base-devel` for Arch Linux)
- `cmake`
- `clang++`

For Windows, please see the `pdcurses` branch.

For [Nix](https://en.wikipedia.org/wiki/Nix_(package_manager)), you may simply run `nix develop` in your local copy of this repository and proceed.

## Usage

> [!NOTE]
> Before using, clone required submodules with `git submodule update --init --recursive`. Alternatively, see [this question](https://stackoverflow.com/questions/3796927/how-do-i-git-clone-a-repo-including-its-submodules "StackOverflow – How do I \"git clone\" a repo, including its submodules?") for more information.

```bash
mkdir bin && cd $_
cmake -DCMAKE_CXX_COMPILER=clang++ ..
cmake --build .
```

## Refactoring Checklist

- [x] act11.cpp
- [x] act12.cpp
- [x] act21.cpp
- [x] act22.cpp
- [x] act31.cpp
- [ ] act32a.cpp
- [ ] act32b.cpp
- [ ] act41.cpp
- [x] act42.cpp
- [ ] act51.cpp
- [ ] act52.cpp
- [ ] act61.cpp
- [ ] act62.cpp
- [x] act71.cpp
- [x] act72.cpp
- [ ] act81.cpp