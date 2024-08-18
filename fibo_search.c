#include <stdio.h>

int fibo(int arr[], int size, int n);

int main()
{
    //Sorted array
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]); 

    int n;

    printf("Enter the number to search: ");
    scanf("%d", &n);

    int ans = fibo(arr, size, n);

    if (ans >= 0)
    {
        printf("It was found at index: %d", ans);
    }

    else
    {
        printf("The element %d doesn't exist in this array.", n);
    }

    return 0;
}

int fibo(int arr[], int size, int n)
{
    int a = 0;
    int b = 1;
    int c = a + b;

    //Finding the fibonacci number that is just one bigger than the size of array.
    while (c < size)
    {
        a = b;
        b = c;
        c = a + b;
    }

    /*
    var c represents the total area we're currently searching.
    var a or b represent the next division of the subarray depending if the number is 
    greater or less than our comparision.
    */

    //Initial point since we aren't looking at any element yet.
    int offset = -1;

    //using c >= 1 to check till size of subarray is 1
    while (c >= 1)
    {
        int i = offset + a; //We could use 'b' and it'd be the same.

        if (arr[i] == n)
        {
            return i;
        }

        //Taking the right subarray. 
        else if (arr[i] < n)
        {
            offset = i; //Like offset = -1, but for the subarray.

            c = b;
            b = a;
            a = c - b;
        }

        //Taking the left subarray.
        else if (arr[i] > n)
        {
            c = a;
            b = b - c;
            a = c - b;
        }
    }

    return -1;
}
