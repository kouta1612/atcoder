#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j <= len - i; j++)
        {
            string t = s.substr(i, j);
            int lent = t.size();
            bool check = true;
            for (int k = 0; k < lent; k++)
            {
                if (!(t[k] == 'A' || t[k] == 'T' || t[k] == 'G' || t[k] == 'C'))
                {
                    check = false;
                }
            }
            if (check)
            {
                ans = max(ans, lent);
            }
        }
    }
    cout << ans << endl;
}
