// Problem Link - https://www.hackerrank.com/challenges/extra-long-factorials/problem   Name - Extra Long Factorials

#include <bits/stdc++.h>

using namespace std;

void extraLongFactorials(int n)
{
    int num_len = 1, i, j, k, carry, arr[158];
    arr[0] = 1;
    for (i = 2; i <= n; i++)
    {
        carry = 0;
        for (j = 0; j < num_len; j++)
        {
            int temp = i * arr[j] + carry;
            carry = temp / 10;
            arr[j] = temp % 10;
        }
        for (; carry != 0; carry /= 10)
        {
            arr[j++] = carry % 10;
            num_len++;
        }
    }
    for (int k = num_len - 1; k >= 0; k--)
        cout << arr[k];
}

int main()
{
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}