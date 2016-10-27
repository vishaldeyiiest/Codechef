#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	int m[26] = {0};
	int pos = -1, count = 0;
	cin >> a >> b;
	for(unsigned int i = 0; i < b.length(); i++)
		m[b[i]-'A'] = 1;
	for(unsigned int i = 0; i < a.length(); i++)
	{
		pos = b.find(a[i], pos+1);
		if(pos == string::npos)
		{
			
			if(m[a[i]-'A'] == 0)
			{
				cout << "-1" << endl;
				return 0;
			}
			pos = -1;
			count++;
			i--;
		}
	}
	cout << count+1 << endl;
	return 0;
}
