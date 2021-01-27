//Problem Link - https://www.hackerrank.com/challenges/absolute-permutation/problem     Name - Absolute Permutation

#include <bits/stdc++.h>

using namespace std;

vector<int> absolutePermutation(int n, int k) {
vector<int> arr;
    arr.push_back(0);
    if(k==0){
        for(int i=1;i<=n;i++)
            arr.push_back(i);
        return arr;        
    }
    if(k>(n/2) || n%(2*k)!=0)
    {arr.push_back(-1);return arr;}
    int i=1;
    while(i<=n){
        if(((i-1)/k)%2==0)
            for(int j=1;j<=k;i++,j++){
                arr.push_back(i+k);
                }
        else
            for(int j=1;j<=k;j++,i++)
                arr.push_back(i-k);
    }
    return arr;
}

int main(){
	int n,t,k;
	vector<vector<int>> res;
	cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        res.push_back(absolutePermutation(n,k));
    }
    for(int i=0;i<t;i++){
        for(int j=1;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}