#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long n, a[3001], b[3002];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) b[i + 1] = b[i] + a[i];
    for (int i = 1; i <= n; i++) {
        long long ans = 0;
        for (int j = 0; i + j <= n; j++) {
            long long sum = b[i + j] - b[j];
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
}
