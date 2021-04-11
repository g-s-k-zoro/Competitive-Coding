// Problem Link - https://www.hackerrank.com/challenges/coin-change/problem          Name - The Coin Change Problem
#include <bits/stdc++.h>

using namespace std;
vector<vector<long>> dp;
long getWays(long total, vector<long> c)
{
    long change_track[total + 1][c.size()];
    for (int i = 0; i < c.size() + 1; i++)
    {
        change_track[0][i] = 1;
    }
    for (int i = 1; i < total + 1; i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            change_track[i][j] = 0;
            if (j >= 1) // without current consideration
                change_track[i][j] += change_track[i][j - 1];
            if (i >= c[j]) // with current consideration
                change_track[i][j] += change_track[i - c[j]][j];
        }
    }
    return change_track[total][c.size() - 1];
}

int main()
{
    long n, paisa, k;
    vector<long> arr;
    cin >> paisa >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr.push_back(k);
    }
    cout << getWays(paisa, arr);
    return 0;
}