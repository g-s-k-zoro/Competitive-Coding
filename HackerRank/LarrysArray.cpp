// Problem Link - https://www.hackerrank.com/challenges/larrys-array/problem          Name - Larry's Array
#include <bits/stdc++.h>

using namespace std;

string larrysArray(vector<int> A) {
int count = 0;
    for(int i=0;i<A.size()-1;i++)
        for(int j=i+1;j<A.size();j++)
            if(A[i]>A[j])
                count++;
    
    if(count & 1)
        return "NO";
    return "YES";
}

int main(){
    vector<int> arr;
    vector<string> str;
    int t,n,k;
    cin>>t;
 	for(int i=0;i<t;i++){
    	cin>>n;
     	for(int j=0;j<n;j++)
     	{
        	 cin>>k;arr.push_back(k);
     	}
     	str.push_back(larrysArray(arr));
     	arr.clear();
 	}
 	for(int i=0;i<t;i++)
    	 cout<<str[i]<<endl;
    return 0;
}