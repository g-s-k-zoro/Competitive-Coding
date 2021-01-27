// Problem Link - https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem          Name - Hackerland Radio Transmitters
#include <bits/stdc++.h>

using namespace std;

int hackerlandRadioTransmitters(vector<int> x, int k) {
sort(x.begin(),x.end());

int n=x.size(),count=0,flag=0,j,cnt=0,i=0,m=0;
    if(n==1)
        return 1;
    for( j=1;j<n;j++){
        if(x[j]-x[i]>k){
            count+=1;
            m=j;
            while(x[m]-x[j-1]<=k && m<n){
                m++;
            }
            j = i = m;
            if(m==n-1)
                count++;
        }
        else if(j==n-1)
            count++;
    }    
    return count;
}

int main(){
 int n,k,l;
 vector<int> arr;
 cin>>n>>k;
 for(int i=0;i<n;i++){
     cin>>l;
     arr.push_back(l);
 }
 cout<<hackerlandRadioTransmitters(arr,k);
    return 0;
}
