#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long n, h[100001], s[100001];
long long mint = 1 << 30;

long long lower_bound(long long key) {
    long long l = -1, r = 1LL << 60;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (mid >= mint) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    cin >> n;
    long long a[n];
    long long l = -1, r = (long long)1e14;
    for (int i = 0; i < n; i++) cin >> h[i] >> s[i];
    while (r - l > 1) {
        long long x = (l + r) / 2;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            a[i] = (x - h[i]) / s[i];
            if (x - h[i] < 0) ok = false;
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            if (a[i] < i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            r = x;
        } else {
            l = x;
        }
    }
    cout << r << endl;
}
