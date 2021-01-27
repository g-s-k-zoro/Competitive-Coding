// Problem Link - https://www.hackerrank.com/challenges/almost-sorted/problem          Name - Almost Sorted
#include <bits/stdc++.h>

using namespace std;

void almostSorted(vector<int> arr) {
    vector<int> arr_sort,ind;
    for(int i=0;i<arr.size();i++)
        arr_sort.push_back(arr[i]);
    sort(arr_sort.begin(),arr_sort.end());
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=arr_sort[i])
            ind.push_back(i+1);     
    }
    if(ind.size()==0)
    {cout<<"yes";return;}
    if(ind.size()==2){
        cout<<"yes\nswap "<<ind[0]<<" "<<ind[1];
        return;
    }

    reverse(arr.begin()+ind[0]-1,arr.begin()+ind[ind.size()-1]);
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=arr_sort[i])
        {cout<<"no";return;}     
    }
	cout<<"yes\nreverse "<<ind[0]<<" "<<ind[ind.size()-1];
}

int main()
{
    int n,k;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>k;arr.push_back(k);}
    almostSorted(arr);
    return 0;
}
