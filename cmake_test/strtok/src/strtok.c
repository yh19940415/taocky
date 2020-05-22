#include <stdio.h>
#include <string.h>

typedef void* dcos_param2;
int main()
{
    const char str[10] = "ab.cd.efg";

     int i = 0;

    printf("len:%ld content:%s\n", strlen(str), str);
    for(i = 0; i < strlen(str); i++) {
      printf("%x", str[i]);
    }
    char delims[] = ".";
    char *result = NULL;
    result = strtok( str, delims );
    while( result != NULL ) {
      printf( "result is \"%s\"\n", result );
      result = strtok( NULL, delims );
    }

    int a = 10;
    char b = NULL;
    int * c = &a;
    a > 5 ? printf("a>1\n"):printf("a<1\n");

    a > 20 ? printf("a>20\n"):printf("a<20\n");

    printf("len:%ld content:%s\n", strlen(str), str);


    for(i = 0; i < strlen(str); i++) {
      printf("%x", str[i]);
    }
    char *result1 = strtok( NULL, delims );
    char *resul2 = strtok( NULL, delims );
    char *resul3 = strtok( NULL, delims );
    char *resul4 = strtok( NULL, delims );
    return 0;
}

