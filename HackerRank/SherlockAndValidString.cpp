// Problem Link - https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem          Name - Sherlock and the Valid String
#include <bits/stdc++.h>

using namespace std;

string isValid(string s) {
int arr[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int count=0,t;
    vector<int> temp;
    for(int i=0;i<s.size();i++){
        arr[(int)s[i] - 97]++;
    }
    for(int i=0;i<26;i++){
        if(arr[i]!=0)
            temp.push_back(arr[i]);            
    }
    if (temp[0] == temp[1] || temp[1] == temp[2])
        t = temp[1];
    else
        t = temp[0];
    for(int i=0;i<temp.size();i++){
        if (abs(temp[i]-t)==1)
            count++;
        else if(abs(temp[i]-t)>1)
            {if(temp[i]==1)
                count++;
             else
                return "NO";
            }
    }
    if(count<=1)
        return "YES";
    else
        return "NO";
}

int main()
{
    string s;
    cin>>s;
    cout<<isValid(s);
    return 0;
}
