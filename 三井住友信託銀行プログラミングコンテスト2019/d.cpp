#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        int c[3] = {i / 100, (i / 10) % 10, i % 10};
        int cur = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '0' + c[cur])
            {
                cur++;
            }
            if (cur == 3)
            {
                break;
            }
        }
        if (cur == 3)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
