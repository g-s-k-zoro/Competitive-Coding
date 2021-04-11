// Problem Link - https://www.codechef.com/JAN19B/problems/DIFNEIGH/     Name - Different Neighbours
#include <bits/stdc++.h>
using namespace std;

void solution(long n, long m)
{
    // int arr[n+1][m+1];

    if ((n == 1) && (m == 1))
    {
        cout << "1\n1" << endl;
        return;
    }
    if (n == 1)
    {
        if (m == 2)
        {
            cout << "1\n1 1" << endl;
            return;
        }
        else
        {
            cout << "2" << endl;
            for (int i = 0; i < m; i++)
            {
                if (((i % 4) + 1) < 3)
                    cout << "1 ";
                else
                    cout << "2 ";
            }
            cout << endl;
            return;
        }
    }

    if (n == 2)
    {
        if (m == 1)
        {
            cout << "1\n1\n1" << endl;
            return;
        }
        if (m == 2)
        {
            cout << "2\n1 1\n2 2" << endl;
            return;
        }
        cout << "3" << endl;
        for (int i = 0; i < m; i++)
            cout << ((i % 3) + 1) << " ";
        cout << endl;
        for (int i = 0; i < m; i++)
            cout << ((i % 3) + 1) << " ";
        cout << endl;
        return;
    }

    if (m == 1)
    {
        cout << "2" << endl;
        for (int i = 0; i < n; i++)
        {
            if (i % 4 < 2)
                cout << "1" << endl;
            else
                cout << "2" << endl;
        }
        return;
    }

    if (m == 2)
    {
        cout << "3" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << ((i % 3) + 1) << " " << ((i % 3) + 1) << endl;
        }
        return;
    }

    cout << "4" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 1)
        {
            for (int j = 0; j < m; j++)
            {
                if (((j % 4) + 1) < 3)
                    cout << "1 ";
                else
                    cout << "3 ";
            }
            cout << endl;
            // continue;
        }

        if (i % 4 == 2)
        {
            for (int j = 0; j < m; j++)
            {
                if (((j % 4) + 1) < 3)
                    cout << "2 ";
                else
                    cout << "4 ";
            }
            cout << endl;
            // continue;
        }

        if (i % 4 == 3)
        {
            for (int j = 0; j < m; j++)
            {
                if (((j % 4) + 1) < 3)
                    cout << "3 ";
                else
                    cout << "1 ";
            }
            cout << endl;
            // continue;
        }

        if (i % 4 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                if (((j % 4) + 1) < 3)
                    cout << "4 ";
                else
                    cout << "2 ";
            }
            cout << endl;
            // continue;
        }
    }
}

int main()
{
    long t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        solution(n, m);
    }

    return 0;
}