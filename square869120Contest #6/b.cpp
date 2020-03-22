#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    int n;
    long long a[31], b[31];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    long long ans = 1LL << 60;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] >= b[j])
            {
                continue;
            }
            long long num = 0;
            for (int k = 0; k < n; k++)
            {
                num += abs(a[i] - a[k]) + abs(a[k] - b[k]) + abs(b[k] - b[j]);
            }
            ans = min(ans, num);
        }
    }
    cout << ans << endl;
}
