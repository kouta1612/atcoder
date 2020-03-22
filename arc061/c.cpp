#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    long long ans = 0;
    for (int bit = 0; bit < (1 << (len - 1)); bit++)
    {
        long long num = 0;
        for (int i = 0; i < len; i++)
        {
            num = num * 10 + s[i] - '0';
            if (bit & (1 << i))
            {
                ans += num;
                num = 0;
            }
        }
        ans += num;
    }
    cout << ans << endl;
}
