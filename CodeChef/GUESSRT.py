#Problem Link - https://www.codechef.com/FEB19B/problems/GUESSRT/    Name - Guess It Right
import math

def power(x, y, p = 1000000007) : 
    res = 1
    x = x % p  
  
    while (y > 0) : 

        if ((y & 1) == 1) : 
            res = (res * x) % p 

        y = y >> 1
        x = (x * x) % p 
          
    return res 

def inverse(x, m = 1000000007) : 
	if x==1:
		return 1
	else:
		return ((m - (m//x))*inverse(m%x, m))%m

def prob(n, k, m):
	if m == 1:
		return inverse(n);
	mod = 1000000007

	l = (m+1)//2

	num = power(n,l) - power(n-1,l)
	num = num%mod

	denom = power(n,l)
	denom = denom%mod

	if(m&1 == 1):
		temp = num*inverse(denom)
		temp = temp%mod
		return temp
	else:
		num = num * (n+k)
		num = num%mod
		num = num+ (power(n-1,l))%mod
		num = num%mod

		denom = denom * (n+k)
		denom = denom%mod
		temp = num*inverse(denom)
		temp = temp%mod
		return temp	



t = int(input())
while t>0:
	t-=1
	no = list(map(int, input().split(" ")))
	print(prob(no[0],no[1],no[2]))