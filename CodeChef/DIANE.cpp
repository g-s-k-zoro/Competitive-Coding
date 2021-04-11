// Problem link - https://www.codechef.com/problems/DIANE     Name - Yet Another Crossover Episode

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    int t, n, k, twoORthree = 2;
    ll d;
    int coPrime = 99991;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {

        cin >> d;
        n = floor(sqrt(2 * d));
        if (d == 0)
        {
            cout << "1" << endl << "1" << endl;
            continue;
        }
        if (d == 1)
        {
            cout << "2" << endl << "2 3" << endl;
            continue;
        }
        if (n * (n + 1) < 2 * d)
            n += 1;

        k = 2 + d - ((n * (n - 1)) >> 1);

        twoORthree = n & 1 ? 2 : 3;
        if (k & 1)
            coPrime = k + 2;
        else
            coPrime = k + 1;
        cout << n << endl;
        for (int i = 0; i < n - 2; i++)
        {
            cout << twoORthree << " ";
            twoORthree = twoORthree & 1 ? 2 : 3;
        }
        cout << coPrime << " " << k << endl;
    }
    return 0;
}