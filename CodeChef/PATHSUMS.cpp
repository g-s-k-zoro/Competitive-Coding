//Problem Link - https://www.codechef.com/problems/PATHSUMS    Name - Path-etic Sums

#include<bits/stdc++.h>
using namespace std;

void specialPath(vector< vector<int> > tree, int n){

    int ft;
    queue<int> Q;
    vector<int> level(n+1);
    vector<bool> visited(n+1, false);
    visited[0] = true;
    visited[1] = true;
    Q.push(1);
    level[1] = 1;

    while(!Q.empty()){
        ft = Q.front();
        Q.pop();

        for(int i=0;i<tree[ft].size();i++){

            if(!visited[tree[ft][i]]){
                visited[tree[ft][i]] = true;
                Q.push(tree[ft][i]);
                level[tree[ft][i]] = level[ft]+1;
            }
        }
    }
cout<<"1";
for(int i=2;i<=n;i++)
    if(level[i]&1)
        cout<<" 1";
    else
        cout<<" 2";
cout<<endl;

}

int main(int argc, char const *argv[])
{
    int t, n, u, v;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    vector< vector<int> > tree;
    vector<int> arr;
    while(t--){
        cin>>n;
        tree.resize(n+1, vector<int>(n+1));
        for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        }
        specialPath(tree, n);
        tree.clear();
        arr.clear();
    }
    return 0;
}