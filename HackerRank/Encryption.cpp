//Problem Link - https://www.hackerrank.com/challenges/encryption/problem    Name - Encryption

#include <bits/stdc++.h>

using namespace std;

void encryption(string s) {
    int r=sqrt(s.size());
    int c=r+1,flag=0;
    if(r*(r+1)<s.size())
        {r++;}
    else {if(r*r == s.size())
                c--;}
    char **mat;
    mat = new char*[r];
    for(int i=0;i<r;i++)
        *(mat+i) = new char[c];
    int k=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c && k!=s.size();j++){
            mat[i][j] = s[k++];
        }
        if(k==s.size())
            break;
    }

    for(int j=0;j<c;j++){
        for(int i=0;i<r;i++){
            if(s.size()%c!=0 && i==r-1 && j>=s.size()%c)
            {continue;}
            cout<<mat[i][j];
        }
        if(j==(c-1))
            continue;
        else cout<<" ";
    }
}

int main(){
	string s;
    cin>>s;
    encryption(s);
    return 0;
}