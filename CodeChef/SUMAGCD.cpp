//Problem link - https://www.codechef.com/JUNE19A/problems/SUMAGCD/   Name - Sum and GCD
#include<bits/stdc++.h>
using namespace std;

int AG_solve(vector<int> arr){

    int result = arr[0];
    
    for(int i=1;i<arr.size()-1;i++){
        result = __gcd(result, arr[i]);
    }
    return result;
}

int SolutionSG(vector<int> arr){
    
    // int n = arr.size();
    sort( arr.begin(), arr.end() );
    
    auto it = unique(arr.begin(), arr.end());
    
    arr.resize( distance(arr.begin(), it) );

    auto n = arr.size();

    if(arr[0] == 1)
    {
        return arr[n-1]+1;
    }

    if(n == 1)
    {
        return arr[0]<<1;
    }
    
    if( arr[n-2] < (arr[n-1]>>1) )
    {
        return AG_solve(arr)+arr[n-1];
    }
    
    else{

        auto mid1 = 0+AG_solve(arr)+arr[n-1];
        
        swap(arr[n-2], arr[n-1]);
        
        auto mid2 =  arr[n-1]+AG_solve(arr);
        
        return max(mid1, mid2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    int N;
    
    cin>>t;

    for(int j=0;j<t;j++)
    {
        cin>>N;
        
        vector<int> arrr(N);
        
        for(auto i=0;i<N;i++)
        {
            cin>>arrr[i];
        }

        cout<<SolutionSG(arrr)<<endl;
    }

}