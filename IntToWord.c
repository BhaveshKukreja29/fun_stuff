#include <stdio.h>
#include <stdlib.h>

int main()
{
    //collection of number we will use
    char *arr[3][10] = {
        {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"},
        {"","", "Twenty ", "Thirty ", "Fourty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "},
        {"", "One Hundred ", "Two Hundred ", "Three Hundred ", "Four Hundred ", "Five Hundred ", "Six  Hundred ", "Seven Hundred ", "Eight Hundred ", "Nine Hundred "},
    };

    //some numbers which we can't just show by concatenation
    char *edge[10] = {"Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    int n;
    printf("Enter the decimal number: ");
    scanf("%d", &n);


    //making some memory to store the digits of the integer
    int size = 1;
    int *narr = malloc(size * sizeof(int));;
  
    narr[size - 1] = n % 10;
    n = n/10;

    //storing each digit in the array and also increasing the size of array accordingly
    while(n > 0)
    {
        size++;

        narr = (int*)realloc(narr, size * sizeof(int));

        narr[size - 1] = n % 10;
        n = n/10;
    }

    printf("In words: ");

    for (int i = size - 1; i >= 0; i--)
    {
        if (size < 4)
        {
            if (size == 1 && narr[i] == 0)
            {
                printf("Zero");
            }

            else if (size == 1 && narr[i] > 0)
            {
                printf("%s", arr[i][narr[i]]);
            }

            
            //need break here since we only need one iteration to print the answer
            else if (size == 2 && narr[size - 1] == 1)
            {
                printf("%s", edge[narr[i - 1]]);
                break;
            }

            //substituting the index value to access the appropriate multiple
            //and then passing narr[i] to access the actual index for the number
            else if (size == 2 && narr[size - 1] > 1)
            {
                printf("%s", arr[i][narr[i]]);
            }

            else if (size == 3)
            {
                printf("%s", arr[i][narr[i]]);
                
                if (i == 2) printf("and ");
            }
        }

        else
        {
            printf("Too large number for this program to handle.");
            break;
        }
    }

    free(narr);

    return 0;
}
