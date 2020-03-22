#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime(int num)
{
    if (num == 1 || num == 0)
    {
        return false;
    }
    bool check = true;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            check = false;
        }
    }
    return check;
}

bool check(int num)
{
    return isPrime(num) && isPrime((num + 1) / 2);
}

int main()
{
    int q, l, r;
    cin >> q;
    vector<bool> a;
    vector<int> b;
    vector<vector<int>> c;
    c.resize(q);
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        c[i].push_back(l);
        c[i].push_back(r);
    }
    for (int i = 0; i <= 100000; i++)
    {
        check(i) ? a.push_back(true) : a.push_back(false);
    }

    b.push_back(0);
    for (int i = 0; i <= 100000; i++)
    {
        b.push_back(b[i] + (a[i + 1] ? 1 : 0));
    }
    for (int i = 0; i < q; i++)
    {
        cout << b[c[i][1]] - b[c[i][0] - 1] << endl;
    }
}
