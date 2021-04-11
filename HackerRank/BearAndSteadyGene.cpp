// Problem Link - https://www.hackerrank.com/challenges/bear-and-steady-gene/problem          Name - Bear and Steady
// Gene
#include <bits/stdc++.h>

using namespace std;

int index(char c)
{
    if (c == 'A')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'G')
        return 2;
    if (c == 'T')
        return 3;

    return 0;
}

int steadyGene(string gene)
{
    int count[] = {0, 0, 0, 0}; // A,C,G,T
    int i, j, flag = 0, n = gene.size();
    for (j = gene.size() - 1; j >= 0; j--)
    {
        count[index(gene[j])]++;
        if (count[index(gene[j])] == (gene.size() / 4))
        {
            break;
        }
    }

    int mini = j;
    for (i = 0; i < gene.size(); i++)
    {
        count[index(gene[i])]++;
        for (; count[index(gene[i])] > (n / 4) && j != n; j++)
            count[index(gene[j])]--;

        if (j == n)
            return mini;
        else if (mini > j - i - 1)
            mini = j - 1 - i;
    }

    return mini;
}

int main()
{
    int n, k;
    string s;
    cin >> n >> s;
    cout << steadyGene(s);
    return 0;
}
