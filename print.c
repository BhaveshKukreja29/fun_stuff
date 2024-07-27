#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int print(char arr[], ...);

int main()
{
    int t = 'g';

    print("Hello #i #d #c #d", 1, 14, t, 2);
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

    char buff[i];

    va_list args;
    va_start(args, arr);

    int j = 0;

    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '#')
        {
            if (arr[i + 1] == 'i' || arr[i + 1] == 'd')
            {
                int val = (int)va_arg(args, int);
                
                sprintf(buff + j, "%d", val);
                j++;
                i++;
            }

            else if (arr[i + 1] == 'c')
            {
                buff[j] = (char)va_arg(args, int);
                j++;
                i++;
            }
        }

        else
        {
            buff[j] = arr[i];
            j++;
        }
    }

    buff[j] = '\0';

    va_end(args);

    printf("%s",buff);

    return strlen(buff);
}
