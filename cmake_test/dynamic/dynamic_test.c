#include <stdio.h>

int dynamic_notify(char *key, char *new_value, char *old_value);

int dynamic_notify(char *key, char *new_value, char *old_value)
{
    FILE *fp = NULL;

    fp = fopen("./dynamic_notification.txt", "w+");
    fprintf(fp, "key:%s\nnew_value:%s\nold_value:%s\n", key, new_value, old_value);

    fclose(fp);
    return 0;
}
