

#include <stdio.h>
#include <string.h>

int main ()
{
    char buf[] ="the cat in the hat jumped over the lazy fox";
    int i = 0;
    char *p = strtok (buf, " ");
    char *array[20];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, " ");
    }

    for (i = 0; i < 20; ++i) 
        printf("%s\n", array[i]);

    return 0;
}