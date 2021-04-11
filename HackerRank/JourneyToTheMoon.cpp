// Problem Link - https://www.hackerrank.com/challenges/journey-to-the-moon/problem          Name - Journey To the Moon
#include <bits/stdc++.h>

using namespace std;

long journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<int> arr(n), cnt(n);
    long sum = 0, subsum = 0, nalle = 0;
    for (int i = 0; i < n; i++)
        arr[i] = -1;

    for (int i = 0; i < astronaut.size(); i++)
    {
        if (arr[astronaut[i][0]] == arr[astronaut[i][1]] && arr[astronaut[i][0]] != -1)
            continue;
        else
        {
            if (arr[astronaut[i][0]] != arr[astronaut[i][1]])
            {
                int k = max(arr[astronaut[i][0]], arr[astronaut[i][1]]),
                    mini = min(arr[astronaut[i][0]], arr[astronaut[i][1]]);
                if (mini != -1)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (arr[j] == mini)
                            arr[j] = k;
                    }
                }
                else
                {
                    arr[astronaut[i][0]] = arr[astronaut[i][1]] = k;
                }
            }
            else
                arr[astronaut[i][0]] = arr[astronaut[i][1]] = i;
        }
    }
    for (int i = 0; i < n; i++)
        if (arr[i] != -1)
            cnt[arr[i]]++;
        else
            nalle++;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] != 0)
        {
            subsum += (cnt[i] * (cnt[i] - 1)) / 2;
        }
        sum += cnt[i];
    }
    long res = ((sum * (sum - 1)) / 2) - subsum;
    res += (nalle * sum) + ((nalle * (nalle - 1)) / 2);
    return res;
}

int main()
{
    int k, n, m, l;
    vector<int> arr;
    vector<vector<int>> astro;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k >> l;
        arr.push_back(k);
        arr.push_back(l);
        astro.push_back(arr);
        arr.clear();
    }
    cout << journeyToMoon(n, astro);
    return 0;
}