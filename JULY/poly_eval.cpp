#include <iostream>
using namespace std;
 
long int horner(int poly[], int n, int x)
{
    long int result = poly[n-1]; 
    for (int i = n - 2; i >= 0; i--)
        result = ((result * x)+ poly[i]);
 
    return result;
}

int main()
{
	int n, c = 1;
	while(1){
	cin >> n;
	if(n == -1)
		return 0;
		
	int x = n + 1;
	int poly[250001];
	for(int i = n; i >=0 ; i--)
		cin >> poly[i];
	
	int nq;
	cin >> nq;
	cout <<"Case "<<c++<<":"<<endl; 
	while(nq--)
	{
		int q;
		cin >> q;
		cout << horner(poly, x, q) << endl;
	}
	}
	return 0;
}
