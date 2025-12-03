# Wonder

A work in progress decompilation of Wonder Project J2

It currently builds the following ROM:
- wonderprojectj2.jp.z64: `0ff1f8628d8fe69582db54572d2bea79 MD5` 

# Extracting sprites
To extract the main sprites of the game use `make assets` please note that i haven't figure out the right palettes for each of the sprites so for now most of them will just look like "gray images"

# Contributing
There are 3 main aspects to contribute to this project which are documenting the codebase, decompiling more functions and figuring out more about the rom layout which is essential to finally resolve those undefined symbols located in `resolve.txt` and in the auto generated file `undefined_syms.txt`


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
The layout for this game seems to be quite simple since it only has a single segments containing all the game's logic and various segments with the sprites and textures and at the end the audio data (banks, sequences, etc..)

## Compression
The ROM appears to have some sections compressed by what seems to be a custom version of the LZSS compression algorithm. This algorithm is called SPI have three different known "versions":

- SPI1, SPI0: The encoded variants, dunno what's the exact difference between their algorithms, the header size for both is `0x14`
- SPIN: This seems to be the uncompressed variant, it seems to be mostly used in small rgba32 and rgba16 textures its header size: `0x8`


# Special thanks 
Thanks to @Ruin0x11 for it's josette tool which has been really useful to figure out the SPI compression and the segments containing the sprites. Most of the structures in `obj.h` are ported directly from the mentioned tool


