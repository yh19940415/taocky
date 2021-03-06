#define OPTPARSE_IMPLEMENTATION
#define OPTPARSE_API static
#include "optparse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

void print_argv(char **argv)
{
    while (*argv)
        printf("%s ", *argv++);
    printf("\n");
}

void try_getopt(int argc, char **argv)
{
    int opt;

    print_argv(argv);
    while ((opt = getopt(argc, argv, "abc:d:e:")) != -1) {
        printf("%c (%d) = '%s'\n", opt, optind, optarg);
    }
    printf("optind = %d\n", optind);
    for (; optind < argc; optind++)
        printf("argument: %s\n", argv[optind]);
}

void try_optparse(char **argv)
{
    int opt;
    char *arg;
    struct optparse options;

    print_argv(argv);
    optparse_init(&options, argv);
    while ((opt = optparse(&options, "abc:d:e:")) != -1) {
        if (opt == '?')
            printf("%s: %s\n", argv[0], options.errmsg);

        printf("haocky:%c (%d) = '%s'\n", opt, options.optind, options.optarg);
    }
    printf("optind = %d\n", options.optind);
    while ((arg = optparse_arg(&options)))
        printf("argument: %s\n", arg);
}

void try_optparse_long(char **argv)
{
    char *arg;
    int opt, longindex;
    struct optparse options;
    struct optparse_long longopts[] = {
        {"amend", 'a', OPTPARSE_NONE},
        {"brief", 'b', OPTPARSE_NONE},
        {"color", 'c', OPTPARSE_REQUIRED},
        {"delay", 'd', OPTPARSE_OPTIONAL},
        {0, 0, 0}
    };

    print_argv(argv);
    optparse_init(&options, argv);
    while ((opt = optparse_long(&options, longopts, &longindex)) != -1) {
        if (opt == '?')
            printf("%s: %s\n", argv[0], options.errmsg);
        printf("%c (%d, %d) = '%s'\n",
               opt, options.optind, longindex, options.optarg);
    }
    printf("optind = %d\n", options.optind);
    while ((arg = optparse_arg(&options)))
        printf("argument: %s\n", arg);
}


struct option long_options[] = {
                   {"dcos_param2_file",  required_argument, 0,  0 },
                   {"dcos_param2_mode",  required_argument, 0,  0 },
               };

int main(int argc, char **argv)
{
  int i = 0;

  for (i = 0; i < argc; i++) {
    printf("%d:%s\n", i, *((argv) + i));
  }

  static struct option long_options[] = {
      {"dcos_param2_file", required_argument, NULL, 'f'},
      {"dcos_param2_mode", required_argument, NULL, 'm'},
  };


  int option_index = 0;
  int ret=0;
  while((ret=getopt_long(argc,argv,"",long_options,&option_index))!=-1)
  {
      switch(ret)
      {
          case 'f':
              printf("The argument of -f is  %s\n\n", optarg);
              break;
          case 'm':
              printf("The argument of -m is  %s\n\n", optarg);
              break;
          case '?':
              break;
      }
  }

  return 0;

  /*
    printf("coredump %s\n", NULL);
    char *long_argv[] = {
        "./main", "--amend", "-b", "--color", "red", "--delay=22",
        "subcommand", "example.txt", "--amend", NULL
    };
    size_t size = (argc + 1) * sizeof(*argv);//malloc the char *array[len] size
    char **argv_copy = malloc(size);

    memcpy(argv_copy, argv, size);
    printf("GETOPT\n");
    try_getopt(argc, argv_copy);

    memcpy(argv_copy, argv, size);
    printf("\nOPTPARSE\n");
    try_optparse(argv_copy);

    printf("\nOPTPARSE LONG\n");
    try_optparse_long(long_argv);

    return 0;
    */

}
