#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Error: invalid options count\n");
        return 1;
    }

    FILE *file_source = fopen(argv[1], "rb");
    if (!file_source) {
        printf("Error: could not opened source file\n");
        return 1;
    } 

    FILE *file_dest = fopen(argv[2], "wb");
    if (!file_dest) {
        printf("Error: could not opened destination file\n");
        return 1;
    } 

    int symbol = 0;
    while (symbol = fgetc(file_source) != EOF) {
        fputc(symbol, file_dest);
    }

    fclose(file_source);
    fclose(file_dest);

    return 0;
}
