#include <getopt.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {

    const char *srtOp = "hvp:";

    static struct option lngOp[] = {
            {"help",    no_argument,       0, 'h'},
            {"version", no_argument,       0, 'v'},
            {"print",   required_argument, 0, 'p'},
            {0,         0,                 0, 0},
    };

    const char *hlpOp = "Option of the program:\n"
                        "-h or -- help                                      - print options of the program\n"
                        "-v or --version                                    - version of the file\n"
                        "-p[<int value>, ...], --print[<int value>, ...]    - print list of values\n";

    const char *version = "2.01.02";

    bool h, v, p = false;

    int Opindex, opt;

    while ((opt = getopt_long(argc, argv, srtOp, lngOp, &Opindex)) != -1) {

        switch (opt) {
            case 'h': {
                if (!h) {
                    h = true;
                    printf("%s\n", lngOp);
                }
                break;
            }
            case 'v': {
                if (!v) {
                    v = true;
                    printf("Current version: %s\n", version);
                }
                break;

            }
            case 'p':
            {
                if (!p)
                {
                    char *args;
                    printf("Array of options:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL)
                    {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    p = true;
                }
                break;
            }
            default: {
                printf("Error!\n");
                return 0;
            }
        }
    }
    return 0;
}