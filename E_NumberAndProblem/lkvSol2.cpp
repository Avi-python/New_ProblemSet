#include <bits/stdc++.h>
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

int diff(int x) {
    int res = 1;
    while (x % 10 == 9) {
        res -= 9;
        x /= 10;
    }
    return res;
}

void solve() {
    int L, R, V1, V2;
    cin >> L >> R >> V1 >> V2;
    int mnX = L, mxX = L, cur_digitsum = digitsum(L - 1), mn_cur_digitsum = digitsum(L - 1), mx_cur_digitsum = digitsum(L - 1);
    long long mnX_sum = 0, mxX_sum = 0, res = 0;
    for (int y = L; y <= R; y++) 
    {
        cur_digitsum += diff(y - 1);
        mnX_sum += cur_digitsum, mxX_sum += cur_digitsum;
        while (mnX_sum > V2)
        {
            mn_cur_digitsum += diff(mnX - 1);
            mnX_sum -= mn_cur_digitsum;
            mnX++;
        }
        while (mxX_sum >= V1) 
        {
            mx_cur_digitsum += diff(mxX - 1);
            mxX_sum -= mx_cur_digitsum;
            mxX++;
        }
        if (mnX_sum >= V1 && mnX_sum <= V2) 
        {
            res += mxX - mnX;
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