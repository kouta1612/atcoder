#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k, x1, y1, x2, y2, J[1001][1001], O[1001][1001], I[1001][1001];
char s[1001][1001];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            J[i + 1][j + 1] =
                J[i][j + 1] + J[i + 1][j] - J[i][j] + (s[i][j] == 'J' ? 1 : 0);
            O[i + 1][j + 1] =
                O[i][j + 1] + O[i + 1][j] - O[i][j] + (s[i][j] == 'O' ? 1 : 0);
            I[i + 1][j + 1] =
                I[i][j + 1] + I[i + 1][j] - I[i][j] + (s[i][j] == 'I' ? 1 : 0);
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int a = J[x2][y2] - J[x1][y2] - J[x2][y1] + J[x1][y1];
        int b = O[x2][y2] - O[x1][y2] - O[x2][y1] + O[x1][y1];
        int c = I[x2][y2] - I[x1][y2] - I[x2][y1] + I[x1][y1];
        cout << a << b << c << endl;
    }
}
