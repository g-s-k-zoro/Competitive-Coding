// Problem Link - https://www.hackerrank.com/challenges/minimum-loss/problem         Name - Minimum Loss
#include <bits/stdc++.h>

using namespace std;

int minimumLoss(vector<pair<long, long>> price)
{
    long mini = 999999999999999;
    sort(price.begin(), price.end());
    for (int i = 1; i < price.size(); i++)
    {

        if (price[i].second < price[i - 1].second)
        {
            if ((price[i].first - price[i - 1].first) < mini)
                mini = price[i].first - price[i - 1].first;
        }
    }

    return mini;
}

int main()
{
    long n, k;
    vector<pair<long, long>> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr.push_back(make_pair(k, i));
    }
    cout << minimumLoss(arr);
    return 0;
}