//Problem Link - https://www.hackerrank.com/challenges/3d-surface-area/problem     Name - 3D Surface Area

#include <bits/stdc++.h>

using namespace std;

int main(){

int h,w;
cin>>h>>w;
int A[h+2][w+2];

for(int i=0;i<=h+1;i++)
	for(int j=0;j<=w+1;j++)
        A[i][j]=0;
 
for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++)
        cin>>A[i][j];
 
int sum=0,crap=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            sum+=min(A[i][j-1],A[i][j])+min(A[i][j+1],A[i][j])+min(A[i-1][j],A[i][j])+min(A[i+1][j],A[i][j]);
            sum+=(A[i][j]-1)*2;
            crap+=A[i][j];
    }
}
 
    cout<<crap*6-sum;
    return 0;
}