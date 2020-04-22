
#include <stdio.h>
#include <unistd.h>
 
void usage() {
    printf("Usage:\n");
    printf("\tOptDemo [-a] [-b] [-c message]");
}
 
int main(int argc, char *argv[]) {
    int o;
    printf("getopt begin:\n");
    const char *optstring = "abc:"; 
    while ((o = getopt(argc, argv, optstring)) != -1) {
        switch (o) {
            case 'a':
                printf("opt is a, oprarg is: %s\n", optarg);
                break;
            case 'b':
                printf("opt is b, oprarg is: %s\n", optarg);
                break;
            case 'c':
                printf("opt is c, oprarg is: %s\n", optarg);
                break;
            case '?':
                printf("\n");
                usage();
                break;
        }
    }
    return 0;
}
