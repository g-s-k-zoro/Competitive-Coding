// Problem Link - https://www.codechef.com/JAN19B/problems/HP18    Name - Lucky Number Game
#include <bits/stdc++.h>
using namespace std;

string solution(int a, int b, vector<int> arr)
{

    long lcm = (a * b) / (__gcd(a, b)), count1 = 0, count2 = 0, count3 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % b == 0)
            count1++;
        if (arr[i] % a == 0)
            count2++;
        if (arr[i] % lcm == 0)
            count3++;
    }

    count1 -= count3;
    count2 -= count3;

    if (a == b)
    {
        return "BOB";
    }
    if (count2 == 0)
        return "ALICE";
    else if (count1 == 0)
        return "BOB";
    if (count3 == 0)
    {
        if (count2 > count1)
            return "BOB";
        else
            return "ALICE";
    }
    else
    {
        if (count2 >= count1)
            return "BOB";
        else
            return "ALICE";
    }
}

int main()
{
    int t;
    cin >> t;
    vector<int> arr;
    int a, b, n, k;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> a >> b;
        for (int j = 0; j < n; j++)
        {
            cin >> k;
            arr.push_back(k);
        }
        cout << solution(a, b, arr) << endl;
        arr.clear();
    }
    return 0;
}