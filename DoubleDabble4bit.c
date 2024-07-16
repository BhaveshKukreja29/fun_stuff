#include <stdio.h>
#include <math.h>

void left_shift(int num[], int bcd[], int s_n);
void binary_banao(int n,int num[]);
void binary_check(int num[]);

int main()
{
    int n = 14;
    int num[4];

    binary_banao(n,num);

    int bcd[] = {0,0,0,0,0,0,0,0};

    for (int i = 0; i < 4; i++)
    {
        left_shift(num,bcd,i);
    }

    printf("Digit 1 in binary: ");
    for (int i = 0; i < 4; i++)
    {
        printf(" %d",bcd[i]);
    }
    printf("\n\nDigit 2 in binary: ");
    for (int i = 4; i < 8; i++)
    {
        printf(" %d",bcd[i]);
    }

    return 0;
}

void binary_check(int num[])
{
    int i,j;
    int sum = 0;
    for (i = 3, j = 0; i >= 0 && j < 4; i--, j++)
    {
        sum += pow(2,i)*num[j];
    }

    if (sum >= 5)
    {
        sum += 3;
        binary_banao(sum, num);
    }

    return;
}

void binary_banao(int n, int num[])
{
    int i = 3;
    while(n != 0)
    {
        num[i] = n % 2;
        n = n / 2;
        i--;
    }
}

void left_shift(int num[], int bcd[], int s_n)
{
    for (int i = 0; i < 7; i++)
    {
        bcd[i] = bcd[i + 1];
    }

    bcd[7] = num[s_n];

    binary_check(&bcd[4]);
}
