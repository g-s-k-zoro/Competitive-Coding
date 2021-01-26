//Problem Link - https://www.codechef.com/problems/BINFUN     Name - Binary Concatenation
#include<bits/stdc++.h>
using namespace std;

typedef long long ull;

int numberObits(ull n){
	return floor(log2(n))+1;
}
ull expression(ull x, ull y){
	return abs(( (x<<( numberObits(y)) ) + y ) - ( (y<<( numberObits(x)) ) + x ));
}

ull maxBinConcat(vector<ull>arr){

	//sort(arr.begin(), arr.end());

	ull x, intermediate;
	ull maxi = 0;
	vector<ull> max_for_y(32, 0);
	vector<ull> min_for_x(32, INT_MAX);

	int bit_length=0;
	for(auto&i : arr){
		bit_length = numberObits(i);
		max_for_y[bit_length] = max(max_for_y[bit_length], i);
		min_for_x[bit_length] = min(min_for_x[bit_length], i);
	}

	for(auto&i: min_for_x){
		for(auto&j: max_for_y){
			if(i == INT_MAX || j == 0)
				continue;
			intermediate = expression(i, j);
			maxi = maxi<intermediate?intermediate:maxi;
		}
	}
	return maxi;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	vector<ull> arr;

	cin>>t;
	while(t--){
		cin>>n;
		arr.resize(n);
		for (int i=0;i<n;i++){
			cin>>arr[i];
			//cout<<arr[i]<<" : "<<expression(arr[i], 19)<<endl;
		}
		cout<<setprecision(12)<<fixed<<maxBinConcat(arr)<<endl;
		arr.clear();
	}
	return 0;
}