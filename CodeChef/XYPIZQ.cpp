//Problem Link - https://www.codechef.com/JAN19B/problems/XYPIZQ       Name - A Pizza Slice

#include<bits/stdc++.h>
using namespace std;

void solution(long long n,long long t,long long x,long long y,long long z){
if(y == 0)
	{cout<<"1 "<<fixed<<setprecision(0)<<2*n+1<<endl;return;}
if(t == 1)
{
	if(x==0){
		cout<<fixed<<setprecision(0)<<2*n-1<<" "<<fixed<<setprecision(0)<<2*n+1<<endl;return;
	}
	if(x<y && y<z){
		cout<<fixed<<setprecision(0)<<(2*n-y)/__gcd((2*n-y),2*n+1)<<" "<<fixed<<setprecision(0)<<(2*n+1)/__gcd((2*n-y),2*n+1)<<endl;return;
	}
	if(x>y && y>z){
		cout<<fixed<<setprecision(0)<<(2*n+2-y)/__gcd((2*n+2-y),2*n+1)<<" "<<fixed<<setprecision(0)<<(2*n+1)/__gcd((2*n+2-y),2*n+1)<<endl;return;
	}
	
	cout<<fixed<<setprecision(0)<<(x)/__gcd((x),2*n+1)<<" "<<fixed<<setprecision(0)<<(2*n+1)/__gcd((x),2*n+1)<<endl;
	return;
}

if((t == 2) || (t == 4)){
	cout<<fixed<<setprecision(0)<<(2*(n-y)+1)/__gcd((2*(n-y)+1),2*n+1)<<" "<<fixed<<setprecision(0)<<(2*n+1)/__gcd((2*(n-y)+1),2*n+1)<<endl;return;
}

if(t == 3)
{
	if(x == 0){
		cout<<"1 1"<<endl;return;
	}
	if(x<y && y<z){
		cout<<fixed<<setprecision(0)<<(2*n+2-y)/__gcd((2*n+2-y),2*n+1)<<" "<<fixed<<setprecision(0)<<(2*n+1)/__gcd((2*n+2-y),2*n+1)<<endl;return;
	}
	if((x == z) && (y>x)){
		cout<<fixed<<setprecision(0)<<(y-1)/__gcd((y-1),2*n+1)<<" "<<fixed<<setprecision(0)<<(2*n+1)/__gcd((y-1),2*n+1)<<endl;return;
	}
	if((x == z) && (y<x)){
		cout<<fixed<<setprecision(0)<<(y+1)/__gcd((y+1),2*n+1)<<" "<<fixed<<setprecision(0)<<(2*n+1)/__gcd((y+1),2*n+1)<<endl;return;
	}

	cout<<fixed<<setprecision(0)<<(2*n-y)/__gcd((2*n-y),2*n+1)<<" "<<fixed<<setprecision(0)<<(2*n+1)/__gcd((2*n-y),2*n+1)<<endl;
	return;
}

}

int main(){
	long long t,n,T,x,y,z;
	cin>>T;
	for(long i=0;i<T;i++){
		cin>>n>>t>>x>>y>>z;
		solution(n,t,x,y,z);
	}
return 0;

}