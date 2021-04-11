// Problem - https://www.codechef.com/problems/ECJAN20C     Name - Chefu and Tiles
#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int r = n;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            r -= r / i;
        }
    }
    if (n > 1)
        r -= r / n;
    return r;
}

int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;

        cout << phi(n) << endl;
    }
    return 0;
}