// Problem Link - https://www.hackerrank.com/challenges/lilys-homework/problem          Name - Lily's Homework
#include <bits/stdc++.h>

using namespace std;

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b)
{
	return (a.first > b.first);
}

int lilysHomework(vector<pair<long,int> > arr) {

	int count=0,sum=0,sum1=0;
	vector< pair<long,int> > grave;
    for(int i=0;i<arr.size();i++)
        grave.push_back(arr[i]);
	
	int *link = (int *)calloc(arr.size(),sizeof(int));
	int *link1 = (int *)calloc(arr.size(),sizeof(int));

    sort(arr.begin(),arr.end());
    sort(grave.begin(),grave.end(), sortinrev);

    for(int i=0;i<arr.size();i++){
        count=0;
        if(link[i]==1)   //if it's already checked for the need of swap  
             continue;
        if(i==arr[i].second)
            {link[i] = 1;continue;}       //it's index is in it's appropriate position
        
        for(int j=i;link[j]==0;j=arr[j].second){
            count++;
            link[j]=1;
        }
            sum+=(count-1);
    }
    
    for(int i=0;i<arr.size();i++){
        count=0;
        if(link1[i]==1)   //if it's already checked for the need of swap  
             continue;
        if(i==grave[i].second)
            {link1[i] = 1;continue;}       //it's index is in it's appropriate position
        
        for(int j=i;link1[j]==0;j=grave[j].second){
            count++;
            link1[j]=1;
        }
            sum1+=(count-1);
    }

    return min(sum,sum1);
}

int main(){
 long n,k;
 vector<pair<long,int>> arr;
 cin>>n;
 for(long i=0;i<n;i++){
        cin>>k;arr.push_back(make_pair(k,i));
 }
 cout<<lilysHomework(arr);
    return 0;
}
