//Problem Link - https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem   Name - Climbing the Leaderboard
#include <bits/stdc++.h>

using namespace std;

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
int *count;
    vector<int> res;
    count = (int*) calloc (scores.size(),sizeof(int));
    count[0]=1;
for(int i=1;i<scores.size();i++){
    if(scores[i]==scores[i-1])
        count[i]=count[i-1];
    else
        count[i]=count[i-1]+1;
}
    int max=scores.size()-1;
    int j = max;
    for(int i=0;i<alice.size();i++){
        for(;j>=0 && alice[i]>scores[j];j--);
        if(alice[i]<scores[j])
            res.push_back(count[j]+1);
        if(alice[i] == scores[j])
            res.push_back(count[j]);
        if(j==-1)
            res.push_back(1);
    
    }
    
  return res;  

}

int main()
{   int n,g,k;
    vector<int> score,alice;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>k;score.push_back(k);
    }
    cin>>g;
    for(int i =0;i<g;i++){
        cin>>k;alice.push_back(k);
    }
    vector<int> res = climbingLeaderboard(score,alice);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
