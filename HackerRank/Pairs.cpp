// Problem Link - https://www.hackerrank.com/challenges/pairs/problem          Name - Pairs
#include <bits/stdc++.h>

using namespace std;

int pairs(long k, map<long, long> m, vector<long> chk)
{
    map<long, long>::iterator it = m.begin(), temp = m.begin();
    int count = 0, i = 0;
    long total = m.size();
    while (total--)
    {
        temp = it;
        it = m.find(chk[i] + k);
        if (it != m.end())
            count++;
        else
        {
            it = temp;
        }
        it++;
        temp++;
        i++;
    }
    return count;
}

int main()
{

    map<long, long> m;
    vector<long> chk;
    long n, k, l;
    cin >> n >> k;
    for (long i = 0; i < n; i++)
    {
        cin >> l;
        chk.push_back(l);
        m.insert(make_pair(l, i));
    }
    cout << pairs(k, m, chk);
    return 0;
}