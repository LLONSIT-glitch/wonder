#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For getopt()

void printInfo(void) {
    printf("The ultimate SPI files tools: \n -c Compress (Disables Decompress)\n  -d Decompress (Default)\n -i Input file\n -o Output file\n -h Help\n");
}

void printOptionWarning(char* s) {
    printf("Option %s requires an argument\n", s);
}

typedef enum {
    OPTION_COMPRESS = 'c',
    OPTION_DECOMPRESS = 'd',
    OPTION_INPUT_FILE = 'i',
    OPTION_OUTPUT_FILE = 'o',
    OPTION_HELP = 'h'
} OPTIONS;

typedef enum {
    COMPRESS,
    DECOMPRESS
} PROGRAM_ACTION;

int main(int argc, char *argv[]) {
    int opt;
    static char* outputFile;
    static char* inputFile;
    // extern int optind; // Declaration is often implicit or in unistd.h
    PROGRAM_ACTION action = DECOMPRESS;

    if (argc < 2) {
        printInfo();
        exit(EXIT_SUCCESS);
    }

    while ((opt = getopt(argc, argv, "ho:i:dc")) != -1) {
        switch (opt) {
            case OPTION_COMPRESS:
                action = COMPRESS;
                break;
            case OPTION_DECOMPRESS:
                action = DECOMPRESS;
                break;
            case OPTION_OUTPUT_FILE:
                outputFile = optarg;
                break;
            case OPTION_INPUT_FILE:
                inputFile = optarg;
                break;
            case OPTION_HELP:
                printInfo();
                break;
            default:
                break;
        }
    }

    if (opt < 0 && argv[optind] != NULL) {
        printf("Warning: Option not recognized: %s\n", argv[optind]);
    }

    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Please specify the inputFile and outPutFile\n");
        exit(EXIT_FAILURE);
    }


    return 0;
}
