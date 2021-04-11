// Problem Link - https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem    Name - Organizing
// Containers of Balls

#include <bits/stdc++.h>

using namespace std;

string organizingContainers(long **container, int n)
{
    vector<long> ele_count, size;
    unsigned long sum1 = 0, sum2 = 0;
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum1 += container[i][j];
        }
        size.push_back(sum1);
        sum1 = 0;
        for (k = 0; k < n; k++)
        {
            sum2 += container[k][i];
        }
        ele_count.push_back(sum2);
        sum2 = 0;
    }
    sort(ele_count.begin(), ele_count.end());
    sort(size.begin(), size.end());
    for (i = 0; i < n; i++)
        if (ele_count[i] != size[i])
            return "Impossible";
    return "Possible";
}

int main()
{
    long **container;
    vector<string> arr;
    long l, n, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        container = new long *[n];
        for (long i = 0; i < n; i++)
            *(container + i) = new long[n];
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                cin >> container[j][k];
                // container[j].push_back(l);
            }

        arr.push_back(organizingContainers(container, n));
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
    return 0;
}
