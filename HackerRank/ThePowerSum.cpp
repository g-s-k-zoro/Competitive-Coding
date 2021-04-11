// Problem Link - https://www.hackerrank.com/challenges/the-power-sum/problem          Name - The Power Sum
#include <bits/stdc++.h>

using namespace std;

int powerSum(int X, int N, int i)
{
    if (pow(i, N) > X)
        return 0;
    if (pow(i, N) == X)
        return 1;
    return powerSum(X, N, i + 1) + powerSum(X - pow(i, N), N, i + 1);
}

// Default Main by Hackerrank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N, 1);

    fout << result << "\n";

    fout.close();

    return 0;
}
