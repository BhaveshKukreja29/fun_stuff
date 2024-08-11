#include <stdio.h>

#define i(x, val) \
    typeof(val) x = val
    
int main()
{
    
    i(a, 5);
    
    printf("%d", a);

    return 0;
}
