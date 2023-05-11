#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i = 0;
    for(i = 0; i < 100000000; i++)
    {
        i++;
    }
    printf("%d\n", i);

    system("pause");
    return 0;
}
