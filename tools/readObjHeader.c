#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum {
    OBJINFO_EMPTY    = 0x0000,
    OBJINFO_HASEXTRA = 0x0001,
    OBJINFO_LOOP     = 0x0002,
    OBJINFO_UNK3     = 0x0004,
    OBJINFO_UNK4     = 0x0008,
    OBJINFO_BG2FG    = 0x0010,
    OBJINFO_UNK6     = 0x0020,
    OBJINFO_UNK8     = 0x0040,
    OBJINFO_FG2BG    = 0x0080,
    OBJINFO_UNK10    = 0x0100,
    OBJINFO_UNK12    = 0x0200,
    OBJINFO_UNK13    = 0x0400,
    OBJINFO_UNK14    = 0x0800,
    OBJINFO_UNK15    = 0x1000,
    OBJINFO_UNK16    = 0x2000,
    OBJINFO_UNK17    = 0x4000,
    OBJINFO_UNK18    = 0x8000
} ObjInfoFlags;

typedef struct {
    uint16_t offset1;
    uint16_t offset2;
    uint32_t u1;
    uint16_t flags;
    uint16_t u2;
    uint16_t u3;
    uint8_t  obj_count;
    uint8_t  extra_obj_count;
} ObjInfo;

const char* objinfo_flags_to_string(uint16_t flags, char* buf, size_t bufsize) {
    buf[0] = '\0';

    if (flags == OBJINFO_EMPTY) {
        snprintf(buf, bufsize, "EMPTY");
        return buf;
    }

    struct { uint16_t bit; const char* name; } table[] = {
        {OBJINFO_HASEXTRA, "HASEXTRA"},
        {OBJINFO_LOOP,     "LOOP"},
        {OBJINFO_UNK3,     "UNK3"},
        {OBJINFO_UNK4,     "UNK4"},
        {OBJINFO_BG2FG,    "BG2FG"},
        {OBJINFO_UNK6,     "UNK6"},
        {OBJINFO_UNK8,     "UNK8"},
        {OBJINFO_FG2BG,    "FG2BG"},
        {OBJINFO_UNK10,    "UNK10"},
        {OBJINFO_UNK12,    "UNK12"},
        {OBJINFO_UNK13,    "UNK13"},
        {OBJINFO_UNK14,    "UNK14"},
        {OBJINFO_UNK15,    "UNK15"},
        {OBJINFO_UNK16,    "UNK16"},
        {OBJINFO_UNK17,    "UNK17"},
        {OBJINFO_UNK18,    "UNK18"},
    };

    for (size_t i = 0; i < sizeof(table)/sizeof(table[0]); i++) {
        if (flags & table[i].bit) {
            strncat(buf, table[i].name, bufsize - strlen(buf) - 2);
            strncat(buf, "|",          bufsize - strlen(buf) - 1);
        }
    }

    size_t len = strlen(buf);
    if (len > 0 && buf[len-1] == '|')
        buf[len-1] = '\0';

    return buf;
}

void objinfo_to_c(const ObjInfo* info) {
    char flagsbuf[128];

    printf(
        "    {.offset1 = 0x%04X, .offset2 = 0x%04X, .u1 = 0x%08X, "
        ".flags = 0x%04X /* %s */, .u2 = 0x%04X, .u3 = 0x%04X, "
        ".obj_count = %u, .extra_obj_count = %u},\n",

        __builtin_bswap16(info->offset1),
        __builtin_bswap16(info->offset2),
        __builtin_bswap32(info->u1),
        __builtin_bswap16(info->flags),
        objinfo_flags_to_string(__builtin_bswap16(info->flags),
                                flagsbuf, sizeof(flagsbuf)),
        __builtin_bswap16(info->u2),
        __builtin_bswap16(info->u3),
        info->obj_count,
        info->extra_obj_count
    );
}

int getFileSize(FILE* fp) {
    fseek(fp, 0, SEEK_END);
    int fSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

int main() {
    FILE* fp = fopen("assets/F27E0.bin", "rb");
    if (!fp) {
        fprintf(stderr, "Can't open file!\n");
        return EXIT_FAILURE;
    }

    int len = getFileSize(fp);
    if (len < (int)sizeof(ObjInfo)) {
        fprintf(stderr, "File too small.\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    char* buf = malloc(len);
    if (!buf) {
        fclose(fp);
        return EXIT_FAILURE;
    }

    if (fread(buf, 1, len, fp) != (size_t)len) {
        fprintf(stderr, "Failed to read file.\n");
        free(buf);
        fclose(fp);
        return EXIT_FAILURE;
    }

    fclose(fp);

    int count = len / sizeof(ObjInfo);
    ObjInfo* info = (ObjInfo*)buf;

    printf("ObjInfo info[] = {\n");

    for (int i = 0; i < count; i++)
        objinfo_to_c(&info[i]);

    printf("};\n");

    free(buf);
    return 0;
}
