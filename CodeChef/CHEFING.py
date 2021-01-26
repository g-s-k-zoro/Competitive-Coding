# Problem link- https://www.codechef.com/JUNE19A/problems/CHFING/   Name - Chef and Ingredients
from math import floor
test = int(input())
mod = 1000000007
for i in range(test):
	iNp = list(map(int, input().split()))
	N = iNp[0]
	k = iNp[1]
	nos = floor((k-1)//(N-1))
	nos+=1
	if (k-1)%(N-1) == 0:
		nos-=1
	result = ( ((2*(k-1)+(nos-1)*(1-N))*nos)>>1)%mod
	print(result)