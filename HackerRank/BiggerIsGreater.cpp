//Problem Link - https://www.hackerrank.com/challenges/bigger-is-greater/problem     Name - Bigger Is Greater

#include <bits/stdc++.h>

using namespace std;

string biggerIsGreater(string w) 
{
  int j,i,max,flag=0,pos;

    for(i=w.size()-1; i>=0; i--)
    {
      for(j=i-1;j>=0;j--)
      {
          if(w[i]>w[j])
          {
            if(flag == 0)
              {
                flag = 1;max = j;pos = i;continue;
              }
             
             if(max<j)
              {
                max = j; pos=i;
              }  
          }
      }
    }

  if(flag){
      
      swap(w[max],w[pos]);

      sort(w.begin()+max+1,w.end());
      
      return w;
  }
  else
      return "no answer";
    
  return "0";
}

int main()
{
  unsigned int n;
    
  string s;
  cin>>n;
  
  for(int i=0;i<n;i++)
  {
    cin>>s;
    cout<<(biggerIsGreater(s))<<endl;
  }
    return 0;
}