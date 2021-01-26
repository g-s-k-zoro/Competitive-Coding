//Problem Link - https://www.codechef.com/JAN19B/problems/DPAIRS/     Name - Distinct Pairs
#include<bits/stdc++.h>
using namespace std;

void solution(vector<long> a,vector<long> b){
long maxx=b[0],maxi=0,minn = a[0],mini=0;
int n=a.size(),m=b.size();
for(int i=0;i<m;i++){
	if(maxx<b[i]){
		maxx = b[i];
		maxi = i;
	}
}

for(int i=0;i<n;i++){
	if(minn>a[i]){
		minn = a[i];
		mini = i;
	}
}
for(int i=0;i<m;i++)
	cout<<mini<<" "<<i<<endl;

for(int i=0;i<n;i++)
	if(i!=mini)
		cout<<i<<" "<<maxi<<endl;
	else
		continue;
}

int main(){
	long n,m;
	
	cin>>n>>m;
	vector<long> a(n);
	vector<long> b(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
		cin>>b[i];

	solution(a,b);
	return 0;
}
