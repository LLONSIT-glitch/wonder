#include <stdio.h>
const int SegsAddr[] = { 0x807A0080, 0x807A1A20, 0x807A7B08, 0x807A7BE0, 0x80947340,
                        0x80949150, 0x8097F4D0, 0x80981A00, 0x80990020, 0x80990180, 0x80993AE0, 0x80993C00, 0x809968B0,
                        0x80996A20, 0x809973B0, 0x809973D0, 0x809975C0, 0x80997600, 0x80997740, 0x80997770, 0x80999028,
                        0x809990F0, 0x809996C0, 0x809996EC, 0x80999818, 0x80999888, 0x80999AA0, 0x809A8190, 0x809A8230,
                        0x809B1E10, 0x809B3C30, 0x809B3E00, 0x809B4200, 0x809D07B0, 0x809D3920, 0x809D45E0, 0x809D546C,
                        0x809DBB4C, 0x809DF1C4, 0x809E55D4, 0x809E55D8, 0x809E55DC, 0x809E55E0, 0x809E7530, 0x809EA6E8,
                        0x809EB550, 0x809EB868, 0x809EB978, 0x809F0F74, 0x809F1260 };



#define ARRAY_COUNT(arr) (int)(sizeof(arr) / sizeof(arr[0]))

int getPhysicalAddressFromVirtual(int base, int vStart, int vEnd) {
    return base + (vEnd - vStart);
}

int main() {
    const int physicalBase = 0x492860;
    const int vStart = 0x807A0080;

    for (int i = 0; i < ARRAY_COUNT(SegsAddr); i++) {
        int seg = getPhysicalAddressFromVirtual(physicalBase, vStart, SegsAddr[i]);
        printf("- { start: 0x%x, vram: 0x%x, type: databin, use_src_path: True, name: sprites/SpriteSeg2/Seg_%x }\n", seg, SegsAddr[i], seg);
    }
}