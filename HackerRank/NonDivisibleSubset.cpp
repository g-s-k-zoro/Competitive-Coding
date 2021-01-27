//Problem Link - https://www.hackerrank.com/challenges/non-divisible-subset/problem    Name - Non-Divisible Subset
#include <bits/stdc++.h>

using namespace std;

unsigned long nonDivisibleSubset(unsigned long k, vector<unsigned long> S) {
unsigned long track[k];
    if(k==1)
        return 1;
    for(unsigned long i=0;i<k;i++)
        track[i] =0;
    unsigned long count=0;
    for(unsigned long i=0;i<S.size();i++)
        track[S[i]%k]++;
    for(unsigned long i=1;i<(k/2);i++){
        count+=max(track[i],track[k-i]);
    }
    if(k%2 == 0)
        count++;
    else
        count+=max(track[(k/2)],track[(k/2)+1]);
    
    if(track[0]!=0)
        count++;
    return count;
}

int main()
{   unsigned long n,k,l;
    vector<unsigned long> S;
    cin>>n>>k;
    for(unsigned long i=0;i<n;i++){
        cin>>l;
        S.push_back(l);
        }
    cout<<nonDivisibleSubset(k,S);
    return 0;
}