
# Wonder

A work in progress decompilation of Wonder Project J2

It currently builds the following ROM:
- wonderprojectj2.jp.z64: `0ff1f8628d8fe69582db54572d2bea79 MD5`

# Progress
- Game Code
<p align="left">
    <a href="" alt="Progress">
        <img src="https://img.shields.io/badge/Bytes-20.17%25-blue" /></a>
</p>


```diff
- WARNING -

**This repo does not include any assets or assembly code necessary for compiling the ROM. A prior copy of the game is required to extract the required assets.**

```

## Installation

#### 1. Install build dependencies

### Windows

For Windows 10, install WSL and a distribution by following this
[Windows Subsystem for Linux Installation Guide](https://docs.microsoft.com/en-us/windows/wsl/install-win10).
We recommend using Debian or Ubuntu 22.04 Linux distributions.

### Linux (Native or under WSL / VM)

The build process has the following package requirements:

* make
* git
* build-essential
* binutils-mips-linux-gnu
* python3
* pip3
* libpng-dev

Under Debian / Ubuntu (which we recommend using), you can install them with the following commands:

```bash
sudo apt update
sudo apt install make cmake git build-essential binutils-mips-linux-gnu python3 python3-pip clang-format-14 clang-tidy
```

### MacOS

Install [Homebrew](https://brew.sh) and the following dependencies:
```
brew update
brew install coreutils make pkg-config tehzz/n64-dev/mips64-elf-binutils
```

#### 2. Clone the repository

Create your own fork of the repository at `https://github.com/LLONSIT-glitch/wonder`. Then clone your fork where you wish to have the project, with the command:

```bash
git clone https://github.com/<YOUR_USERNAME>/wonder.git
```

This will copy the GitHub repository contents into a new folder in the current directory called `wonder`. Change into this directory before doing anything else:

```bash
cd wonder
```

#### 3. Install python dependencies

The build process has a few python packages required that are located in `/tools/requirements-python.txt`.

To install them simply run in a terminal:

```bash
python3 -m pip install -r ./tools/requirements-python.txt
```
* Depending on your python version, you might need to add  --break-system-packages, or use venv.

#### 4. Update submodules & build toolchain

```bash
git submodule update --init --recursive
make dependencies
```

#### 5. Prepare a base ROM
Copy your ROM to the root of this new project directory, and rename the file of the baserom to reflect the version of ROM you are using. ex: `baserom.jp.z64`

#### 6. Make and Build the ROM

To start the extraction/build process, run the following command:

```bash
make extract
```
This will create the build folders, a new folder with the assembly as well as containing the disassembly of nearly all the files containing code.

this make target will also build the ROM. If all goes well, a new ROM called "wonderprojectj2.jp.z64" should be built and the following text should be printed:

```bash
build/wonderprojectj2.jp.z64: OK
```

If you instead see the following:

```bash
build/wonderprojectj2.jp.z64: FAILED
```

This means that something is wrong with the ROM's contents. Either the base files are incorrect due to a bad ROM, or some of the code is not matching.

From now on you should be able to build the rom by running `make`.


# Extracting sprites
To extract the main sprites of the game, use `make extract`. Please note that I haven't determined the correct palette for each sprite, so for now most of them will just look like "gray images".

# Contributing
There are 3 main aspects to contribute to this project, which are documenting the codebase, decompiling more functions, and researching more about the ROM layout, which is essential to finally resolve those undefined symbols located in `resolve.txt` and in the auto-generated file `undefined_syms.txt`.


# Project structure
```
.
├── assets: Assets of the game (sprites, textures, etc..) 
│   └── yaml
├── bins: Binary blobs of the game (Data that has not been correctly identified)
├── include: Source files header 
├── src: Game source code
│   ├── audio: Audio code for the game
│   ├── code: Main code segment
│   ├── libultra: N64 library code
│   ├── sprites: Binary blobs containing the sprites (TODO)
│   └── sys: Game system code
└── tools: Utilities to decompile the game
```

# ROM Info

## Layout
The layout for this game seems to be quite simple since it only has a single segment containing all the game's logic and various segments with the sprites and textures. The remaining part seems to be audio data (banks, sequences, etc.).

## Compression
The ROM appears to have some sections compressed by what seems to be a custom version of the LZSS compression algorithm. This algorithm is called SPI and has three different known "versions":

- SPI1, SPI0: The encoded variants, I don't know what's the exact difference between them is; the header size for both is `0x14`

- SPIN: This seems to be the uncompressed variant; it seems to be mostly used in small rgba32 and rgba16 textures. its header size: `0x8`


# Special thanks 
Thanks to @Ruin0x11 for it's josette tool which has been really useful to know more about the SPI compression format and the segments containing the sprites and object data. Most of the structures in `obj.h` are ported directly from the mentioned tool.


