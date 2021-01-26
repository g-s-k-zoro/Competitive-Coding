//Problem Link - https://www.codechef.com/JUNE19A/problems/SUMAGCD/    Name - Dungeons & Dragons
#include<bits/stdc++.h>
using namespace std;

map<int,int> prime;

void sieve(int n){
	vector<int> arr(n+1);

	int p=2;
	for(int p=2;p*p<=n;p++){

		if(arr[p] == 0){
			for(int j=2*p;j<=n;j+=p)
				arr[j]=1;
		}
	}
	int k = 1;
	for(int i =2;i<=n;i++){
		if(arr[i] == 0)
			prime.insert({i,k++});
	}
}

int sol(int n){
	if(n<4)
		return 0;

	map<int,int> :: iterator it =prime.begin();
	int sqt = sqrt(n);
	for(int i=sqt;i>=2;i--){
		it = prime.find(i);
		if(it!=prime.end())
			return it->second;
	}
	return 0;
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
sieve(1000001);
int n;
cin>>t;
for(int i=0;i<t;i++){
	cin>>n;
	cout<<sol(n)<<endl;
}
return 0;
}