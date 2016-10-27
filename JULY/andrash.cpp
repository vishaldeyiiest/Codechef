#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[100000];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		double avg = 0;
		
		for(int i = 0; i < n; i++)
			avg += a[i];
		avg = avg / n;
		int flag1 = 0, flag2 = 0;
		
		for(int i = 0; i < n; i++)
		{
			if(a[i] <= 2)
				flag1 = 1;
				
			if(a[i] == 5)
				flag2 = 1;
		}
		if(avg >= 4.0 && flag2 == 1 && flag1 != 1)
		{
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
	return 0;	
}
