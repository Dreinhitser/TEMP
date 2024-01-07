#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/stat.h>


int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stdout, "Error: invalid options count\n");
        return 1;
    }

    int status = mkdir("/home/arch", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    if (status == -1) {
        fprintf(stdout, "Error: could not created arch dir\n");
        return 1;
    }

    char dir_path[] = "/home/arch/";
    char path_to_copy[256];
    memset(path_to_copy, 0, sizeof(path_to_copy));
    memcpy(path_to_copy, dir_path, sizeof(dir_path));

    size_t pos = 0;
    for (int i = strlen(argv[1]) - 1; i >= 0; i--) {
        if (argv[1][i] == '/') {
            pos = i + 1;
            break;
        }
    }
    memcpy(path_to_copy + sizeof(dir_path) - 1, argv[1] + pos, strlen(argv[1]) - pos);

    FILE *file_source = fopen(argv[1], "rb");
    if (!file_source) {
        printf("Error: could not opened source file\n");
        return 1;
    }

    FILE *file_dest = fopen(path_to_copy, "wb");
    if (!file_dest) {
        printf("Error: could not opened destination file\n");
        return 1;
    } 

    int symbol = 0;
    while ((symbol = fgetc(file_source)) != EOF) {
        fputc(symbol, file_dest);
    }

    fclose(file_source);
    fclose(file_dest);

    if (remove(argv[1]) != 0) {
        fprintf(stdout, "Error: could not removed source file\n");
        return 1;
    }

    return 0;
}
