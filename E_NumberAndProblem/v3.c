#include <stdio.h>
#include <stdlib.h>

int DigiSum(int);

int main()
{
    int L, R, V1, V2;
    scanf("%d %d %d %d", &L, &R, &V1, &V2);

    int l = L, r = L;
    int prefix = 0, offset = 0, ans = 0;

    while(l <= R)
    {
        if(l == r)
        {
            prefix = DigiSum(r);
            if(prefix < V1)
            {  
                r++;
            }   
            else if(prefix <= V2) 
            {
                r++;
                // offset++;
            }
            else
            {
                l++; r++;
            }
        }
        else
        {
            prefix += DigiSum(r);
            if(prefix < V1)
            {
                r++;
            }
            else if(prefix <= V2)
            {
                offset++;
                ans += offset;
            }
            else
            {
                
            }
        }
    }

    system("pause"0);
    return 0;
}

int DigiSum(int input)
{
    int sum = 0;
    while(input)
    {
        sum += input % 10;
        input /= 10;
    }
    return sum;
}
