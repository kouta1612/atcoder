#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int k[m], p[m];
    vector<vector<int>> s(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            s[i].resize(k[i]);
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        bool isOn = true;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < k[i]; j++) {
                if (bit & (1 << (s[i][j] - 1))) {
                    cnt++;
                }
            }
            if (cnt % 2 != p[i]) {
                isOn = false;
            }
        }
        if (isOn) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
