#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
long long a[100001], b[100001], c[100002], MOD = 100000;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n - 1; i++) c[i + 1] = c[i] + a[i];
    int cur = 0;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans = (ans % MOD + (abs(c[cur + b[i]] - c[cur])) % MOD) % MOD;
        cur += b[i];
    }
    cout << ans << endl;
}
