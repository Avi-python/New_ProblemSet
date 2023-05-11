// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define endl "\n"

int digitsum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

// int diff(int x) {
//     int res = 1;
//     while (x % 10 == 9) {
//         res -= 9;
//         x /= 10;
//     }
//     return res;
// }

void solve() 
{
    int L, R, V1, V2;

    cin >> L >> R >> V1 >> V2;
    
    int minX = L, maxX = L; 
    // mn_cur_digitsum = digitsum(L - 1), mx_cur_digitsum = digitsum(L - 1);

    long long minX_sum = 0, maxX_sum = 0, res = 0;

    for (int y = L; y <= R; y++) 
    {
        minX_sum += digitsum(y), maxX_sum += digitsum(y);
        while (minX_sum > V2) 
        {
            minX_sum -= digitsum(minX);
            minX++;
        }
        while (maxX_sum >= V1) 
        {
            maxX_sum -= digitsum(maxX);
            maxX++;
        }
        if (minX_sum >= V1 && minX_sum <= V2) 
        {
            res += maxX - minX;
        }
    }
    cout << res << endl;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);

    solve();

    cout.flush();
    return 0;
}