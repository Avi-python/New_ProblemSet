#include <stdio.h>
#include <stdlib.h>

// failure

int DigiSum(int);
int Counter(int *, int, int, int, int);

int main()
{
    int L, R, V1, V2;
    scanf("%d %d %d %d", &L, &R, &V1, &V2);
    // printf("%d %d %d %d", L, R, V1, V2);

    // 我猜 O(2nlogn)

    // int l = L, r = L;
    // int prefix = 0;
    // int ans = 0;
    // int offset = 0;
    // int cur = DigiSum(r);

    // if(cur >= V1 && cur <= V2) ans += 1;

    // while(l <= R)
    // {
    //     printf("l:%d, r:%d, cur:%d, prefix:%d, ans:%d\n", l, r, cur, prefix, ans);
    //     if(cur < V1)
    //     {
    //         if(prefix + cur < V1)
    //         {
    //             prefix += cur;
    //             cur = DigiSum(++r);
    //         }
    //         else if(prefix + cur <= V2)
    //         {
    //             offset++;
    //             ans += offset;
    //             prefix += cur;
    //             cur = DigiSum(++r);
    //         }
    //         else // prefix + cur > V2
    //         {
    //             while(l < r && prefix > V2) 
    //             {
    //                 if(offset > 0) offset--;
    //                 prefix -= DigiSum(l++);    
    //             }
    //             if(prefix <= V2 && prefix >= V1) 
    //             {
    //                 offset++;
    //                 ans += offset;
    //                 cur = DigiSum(++r);
    //             }
    //             else
    //             {
    //                 cur = DigiSum(++r);
    //                 prefix = cur;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         if(cur <= V2)
    //         {
    //             if(cur + prefix <= V2)
    //             {
    //                 offset++;
    //                 if(l == r) ans += 1;
    //                 else  ans += offset;      
    //                 prefix += cur;
    //                 cur = DigiSum(++r);
    //             }
    //             else
    //             {
    //                 ans += 1;
    //                 while(l < r && prefix + cur > V2) 
    //                 {
    //                     if(offset > 0) offset--;
    //                     prefix -= DigiSum(l++);    
    //                 }
    //                 printf("%d ", prefix);
    //                 prefix += cur;
    //                 printf("%d\n\n", prefix);
    //                 if(prefix == cur || prefix < V1) 
    //                 {
    //                     cur = DigiSum(++r);
    //                 }
    //                 else if(prefix <= V2)
    //                 {
    //                     offset++;
    //                     ans += offset;
    //                     cur = DigiSum(++r);
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             l = r;
    //             prefix = cur;
    //             offset = 0;
    //             cur = DigiSum(++r);
    //         }
    //     }
    // }

    printf("%d\n", ans);

    // system("pause");
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

int Counter(int *ans, int l, int r, int cur_sum, int V1)
{
    while(cur_sum >= V1 && l <= r)
    {
        *ans += 1;
        cur_sum -= DigiSum(l);
        l++;
    }
}