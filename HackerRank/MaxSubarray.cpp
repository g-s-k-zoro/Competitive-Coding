// Problem Link - https://www.hackerrank.com/challenges/maxsubarray/problem          Name - Max Subarray
#include <bits/stdc++.h>

using namespace std;

vector<long> sub_sum(vector<int> arr){
    long uptill_max=-999999,max_end=0,k,sum=0,sec_sum=0;
    vector<long> res;
    for(int i=0;i<arr.size();i++){
            max_end = max_end+arr[i];
        if(uptill_max<max_end)
            {uptill_max = max_end;k=i;}
        if(max_end<0)
            max_end=0;        
    }
    sort(arr.begin(),arr.end());
    if(arr[arr.size()-1] < 0)
        sec_sum = arr[arr.size()-1];
    else{
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]<0)
                break;
            else
                sec_sum += arr[i];
        }
    }
    res.push_back(uptill_max);
    res.push_back(sec_sum);
    return res;
}

int main()
{   long n,q,k;
    cin>>q;
    vector<int> arr;
    for(int i=0;i<q;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>k;
            arr.push_back(k);
        }
        vector<long> res = sub_sum(arr);
        cout<<res[0]<<" "<<res[1]<<endl;
        arr.clear();
    }
    
    return 0;
}