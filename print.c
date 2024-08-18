#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print(char arr[], ...);
int toStr(int n, char **narr);

int main()
{
    char t = 'g';

    print("Hello #i #d #c #d", 1, 1454, t, 2);
}

int print(char arr[], ...)
{
    int a = 1;
 
    int i = 0;
    while(arr[i] != '\0')
    {
        if (arr[i] == '#')
        {
            a++;
        }
        i++;
    }

    int j = 1;
    char *buff = (char *)malloc(j);

    va_list args;
    va_start(args, arr);

    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '#')
        {
            if (arr[i + 1] == 'i' || arr[i + 1] == 'd')
            {
                int val = (int)va_arg(args, int);
                char *temp = NULL;
                int size = toStr(val, &temp);

                int k = size - 1;
                while (k >= 0)
                {
                    buff[j - 1] = temp[k];
                    j++;
                    buff = (char *)realloc(buff, j);
                    k--;
                }
                i++;
            }

            else if (arr[i + 1] == 'c')
            {
                buff[j - 1] = (char)va_arg(args, int);
                j++;
                buff = (char *)realloc(buff, j);
                i++;
            }
        }

        else
        {
            buff[j - 1] = arr[i];
            j++;
            buff = (char *)realloc(buff, j);
        }
    }

    buff[j] = '\0';

    va_end(args);

    printf("%s",buff);
    int len = strlen(buff);

    free(buff);

    return len;
}

int toStr(int n, char **narr)
{
    int size = 1;
    *narr = malloc(size);
    if (*narr == NULL) {
        return 0;
    }
  
    (*narr)[size - 1] = ((n % 10) + 48);
    n = n/10;

    while(n > 0)
    {
        size++;

        char *temp = (char *)realloc(*narr, size);
        if (temp == NULL) {
            free(*narr);
            return 0;
        }
        *narr = temp;

        (*narr)[size - 1] = ((n % 10) + 48);
        n = n/10;
    }

    return size;
}
