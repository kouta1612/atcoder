#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

long long n, m, a[109][109];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    long long  ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                continue;
            }
            long long num = 0;
            for (int k = 0; k < n; k++)
            {
                num += max(a[k][i], a[k][j]);
            }
            ans = max(ans, num);
        }
    }
    cout << ans << endl;
}
