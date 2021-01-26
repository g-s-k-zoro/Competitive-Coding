//Problem Link - https://www.codechef.com/LTIME67B/problems/PPATTERN/     Name - Print Pattern
#include<bits/stdc++.h>
using namespace std;
void func(int n){
	int arr[n][n];
	
	int count=1,j,k;
for(int i=0;i<n;i++){
	k=0;
	j=i;
	do{
		arr[k++][j--] = count++;
	}while(j>=0);
}
for(int i=1;i<n;i++){
	j=n-1;
	k=i;
	do{
		arr[k++][j--] = count++;
	}while(j>=i);
}

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}
}

int main()
{
int t,n;
cin>>t;
for(int i=0;i<t;i++){
	cin>>n;
	func(n);
}
	return 0;
}