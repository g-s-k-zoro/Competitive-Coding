// Problem Link - https://www.codechef.com/FEB19B/problems/MANRECT/     Name - Manhattan Rectangle
#include<bits/stdc++.h>
using namespace std;


int main(){

	long long t,xz=0,yz=0,x,y,lbx,lby,rux,ruy,pnine = 1000000000,lux,luy,zero=0,temp1,temp2;
	long long sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,chk=1;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
	cin>>t;
for(int i=0;i<t;i++){
	xz =0;yz = 0;chk=1;temp1=0;temp2=0;
	cout<<"Q "<<xz<<" "<<yz<<endl;
	cin>>sum1;
	xz = 0;
	if(sum1<pnine)
		yz = sum1;
	else
		{yz = pnine;temp1 = sum1-pnine;}
	cout<<"Q "<<fixed<<setprecision(0)<<xz<<" "<<fixed<<setprecision(0)<<yz<<endl;
	cin>>sum2;
	if(sum2<pnine)
		xz = sum2;
	else
		{xz = pnine;temp2 = sum2-pnine;}
	cout<<"Q "<<fixed<<setprecision(0)<<xz<<" "<<fixed<<setprecision(0)<<yz<<endl;
	cin>>sum3;
	if(sum3 == 0){
		lbx = lux = xz;lby = sum1-xz;
		cout<<"Q "<<fixed<<setprecision(0)<<lbx<<" "<<fixed<<setprecision(0)<<pnine<<endl;
		cin>>sum4;
		ruy = luy = pnine-sum4;

		cout<<"Q "<<fixed<<setprecision(0)<<pnine<<" "<<fixed<<setprecision(0)<<luy<<endl;
		cin>>sum5;
		rux = pnine-sum5;

		cout<<"A "<<fixed<<setprecision(0)<<lbx<<" "<<fixed<<setprecision(0)<<lby<<" "<<fixed<<setprecision(0)<<rux<<" "<<fixed<<setprecision(0)<<ruy<<endl;
		cin>>chk;
		if(chk<0)
			exit(0);
		continue;
	}

	xz = xz - (((sum3+temp2)/2) - temp2);
	cout<<"Q "<<fixed<<setprecision(0)<<xz<<" "<<fixed<<setprecision(0)<<yz<<endl;
	cin>>sum4;
	luy = ruy = yz-sum4;
	cout<<"Q "<<fixed<<setprecision(0)<<zero<<" "<<fixed<<setprecision(0)<<luy<<endl;
	cin>>sum5;
	lbx = lux = sum5;
	lby = sum1-lbx;
	cout<<"Q "<<fixed<<setprecision(0)<<pnine<<" "<<fixed<<setprecision(0)<<ruy<<endl;
	cin>>sum6;
	rux = pnine-sum6;

		cout<<"A "<<fixed<<setprecision(0)<<lbx<<" "<<fixed<<setprecision(0)<<lby<<" "<<fixed<<setprecision(0)<<rux<<" "<<fixed<<setprecision(0)<<ruy<<endl;

	cin>>chk;
	if(chk<0)
		exit(0);
	}

return 0;
}