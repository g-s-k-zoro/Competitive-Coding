//Problem Link - https://www.codechef.com/NOV18B/problems/CHHAPPY         Name - Chef and Happiness
#include<bits/stdc++.h>
using namespace std;

string happy(vector<int> arr){
	vector<pair<int,int> >shuf;
	map<int,int> chk;
	shuf.push_back(make_pair(0,0));

	for(int i=1;i<=arr.size();i++){
		shuf.push_back(make_pair(arr[i-1],i));
		chk.insert(make_pair(arr[i-1],i));
	} 

	sort(shuf.begin(),shuf.end());

	map<int,int> :: iterator it = chk.begin();

	int count=0;

	for(int i=1;i<shuf.size();i++){

		if(shuf[i].first != shuf[i-1].first)
			count =0;

		it = chk.find(shuf[i].second);
		if(it!=chk.end())
			count++;

		it = chk.begin();

		if(count == 2)
			return "Truly Happy";


	}

	return "Poor Chef";
}

int main(){
    int t,n,k;
    cin>>t;
    vector<int> arr;
    for(int i=0;i<t;i++){
    	cin>>n;
    	for(int j=0;j<n;j++){
    		cin>>k;
    		arr.push_back(k);
    	}
    	cout<<happy(arr)<<endl;
    	arr.clear();
    }
    return 0;
}