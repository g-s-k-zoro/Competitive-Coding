//Problem Link - https://www.hackerrank.com/challenges/the-grid-search/problem    Name - The Grid Search

#include <bits/stdc++.h>

using namespace std;

string gridSearch(vector<string> G,int R, int C, vector<string> P, int r, int c) {

if(r>R || c>C)
    return "NO";
int flag=0,flag1=0;    
for(int i=0;i<R-r+1;i++){
    for(int j=0;j<C-c+1;j++){
        flag=flag1=0;
        if(G[i][j]==P[0][0]){
            for(int l=i;l<i+r;l++){
                for(int m=j;m<j+c;m++){
                    if(G[l][m]!=P[l-i][m-j])
                    {flag=1;break;}
                }
                if(flag==1)
                {flag1=1;break;}
            }
            if(flag1!=1){
                return "YES";
            }
        }
    }
}    
return "NO";
}

int main(){

 int t,r,c,R,C;
 vector<string> g,p,res;
 string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>R>>C;
        for(int j=0;j<R;j++)
        {cin>>s;g.push_back(s);}
        cin>>r>>c;
        for(int j=0;j<r;j++)
        {cin>>s;p.push_back(s);}
        res.push_back(gridSearch(g,R,C,p,r,c));
        g.clear();
        p.clear();
    }
 for(int i=0;i<res.size();i++)
            cout<<res[i]<<endl;
    return 0;
}