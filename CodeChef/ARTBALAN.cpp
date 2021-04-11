// Problem Link - https://www.codechef.com/FEB19B/problems/ARTBALAN/   Name - Art of Balance
#include <bits/stdc++.h>
using namespace std;

long solve(string s)
{

    int n = s.size();
    if (n == 1)
        return 0;
    if (n == 2)
    {
        if (s[0] == s[1])
            return 0;
        else
            return 1;
    }

    vector<int> alpha(26);

    for (int i = 0; i < n; i++)
    {
        alpha[int(s[i]) - 65]++;
    }

    sort(alpha.begin(), alpha.end(), greater<int>());

    vector<int> fact;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                fact.push_back(i);

            else
            {
                fact.push_back(n / i);
                fact.push_back(i);
            }
        }
    }

    long min1 = 999999999, sum = 0, count = 0, flag = 0, sum11 = 0, sum22 = 0;

    // sort(fact.begin(),fact.end());

    for (int i = 0; i < fact.size(); i++)
    {
        sum11 = 0;
        sum22 = 0;
        count = (n / fact[i]);
        flag = 0;
        if (fact[i] <= 26)
        {
            for (int j = 0; j < fact[i]; j++)
            {
                if (alpha[j] == 0)
                    break;

                if (alpha[j] >= count)
                    sum11 += (alpha[j] - count);
                else
                    sum22 += (count - alpha[j]);
                flag = 1;
            }
        }
        // else
        // 	break;

        sum = max(sum11, sum22);

        if (min1 > sum && (flag == 1))
            min1 = sum;
    }

    return min1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}