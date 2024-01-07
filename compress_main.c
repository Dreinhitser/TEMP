#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stdout, "Error: invalid options count\n");
        return 1;
    }

    char cmd[256];
    memset(cmd, 0, sizeof(cmd));
    char gzip_name[6] = "gzip ";
    memcpy(cmd, gzip_name, sizeof(gzip_name));
    memcpy(cmd + sizeof(gzip_name) - 1, argv[1], strlen(argv[1]));

    FILE *terminal = popen(cmd, "r");
    if (!terminal) {
        fprintf(stdout, "Error: could not opened terminal fd\n");
        return 1;
    }

    char buff[256];
    while (fgets(buff, sizeof(buff), terminal)) {
        fprintf(stdout, "%s", buff);
    }

    if (pclose(terminal) == -1) {
        fprintf(stdout, "Error: could not closed fd terminal\n");
        return 1;
    }

    return 0;
}
