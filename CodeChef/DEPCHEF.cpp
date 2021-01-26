// Problem Link - https://www.codechef.com/FEB19B/problems/DEPCHEF/   Name - Deputy Chef

#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int solve(vector<int> a, vector<int> d){

int n=a.size();
int max = 0;
if((a[n-1]+a[1])<d[0]){
		max = d[0];
	}

if((a[n-2]+a[0])<d[n-1]){
		if(max<d[n-1]) max= d[n-1];
	}

for(int i=1;i<n-1;i++){

	if(( a[i-1] + a[i+1] ) < d[i]){
		if(max<d[i])
			max = d[i];
	}
}
if(max != 0)
	return max;

return -1;
} 

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t,n;
cin>>t;
for(int i=0;i<t;i++){
	cin>>n;
	vector<int> a(n),d(n);
	for(int j=0;j<n;j++){
		cin>>a[j];
	}
	for(int j=0;j<n;j++){
		cin>>d[j];
	}
	cout<<solve(a,d)<<endl;
	a.clear();
	d.clear();
}
return 0;
}