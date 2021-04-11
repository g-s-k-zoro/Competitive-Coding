// Problem Link - https://www.codechef.com/JAN19B/problems/EARTSEQ/     Name - Yet Another Problem About Sequences
#include <bits/stdc++.h>
using namespace std;
vector<long> final;

void sieve(long n)
{
    vector<int> prime(n);

    for (long p = 2; p * p <= n; p++)
    {
        if (prime[p] == 0)
        {
            for (long i = p * p; i <= n; i += p)
                prime[i] = 1;
        }
    }
    for (long i = 2; i < n; i++)
        if (prime[i] == 0)
            final.push_back(i);
}

void solution(long n)
{
    if (n == 3)
    {
        cout << "6 10 15" << endl;
        return;
    }
    if (n == 4)
    {
        cout << "374 595 1365 858" << endl;
        return;
    }
    if (n == 5)
    {
        cout << "6 15 35 77 22" << endl;
        return;
    }

    if (n <= 3333)
    {
        int j;
        for (j = 0; j < n - 1; j++)
        {
            cout << fixed << setprecision(0) << final[j] * final[j + 1] << " ";
        }
        cout << fixed << setprecision(0) << final[j] * 2 << endl;
        return;
    }
    cout << "6 15 ";
    long m = 2, k = 2;
    if (n % 3 == 0)
    {
        for (int i = 2; i < n; i++)
        {
            if ((i - 2) % 3 == 0)
            {
                cout << 2 * final[m] << " ";
                m++;
            }
            else if ((i - 2) % 3 == 1)
            {
                cout << 2 * k * 3 << " ";
                k++;
            }
            else
            {
                cout << 3 * final[m] << " ";
            }
        }
        cout << endl;
    }
    else if (n % 3 == 2)
    {
        for (int i = 2; i < n - 3; i++)
        {
            if ((i - 2) % 3 == 0)
            {
                cout << 2 * final[m] << " ";
                m++;
            }
            else if ((i - 2) % 3 == 1)
            {
                cout << 2 * k * 3 << " ";
                k++;
            }
            else
            {
                cout << 3 * final[m] << " ";
            }
        }
        cout << final[m] * 5 << " 35 28" << endl;
    }
    else
    {
        for (int i = 2; i < n - 2; i++)
        {
            if ((i - 2) % 3 == 0)
            {
                cout << 2 * final[m] << " ";
                m++;
            }
            else if ((i - 2) % 3 == 1)
            {
                cout << 2 * k * 3 << " ";
                k++;
            }
            else
            {
                cout << 3 * final[m] << " ";
            }
        }
        cout << final[m] * 5 << " 20" << endl;
    }
}

int main()
{
    long t, n;
    sieve(615000);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        solution(n);
    }

    return 0;
}