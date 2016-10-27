#include <bits/stdc++.h>
#define N 10000

using namespace std;
typedef long long ll;	

long long A[N];
ll dp[N];
int main() 
{
	int n;
    cin >> n;
    assert(1 <= n && n <= 10000);
    ll sol = 0;
    for (int i = 0; i < n; ++i) 
    {
        cin >> A[i];
        assert(A[i] <= 1000 && A[i] >= -1000);
    }
    ll cur = A[0];
    for (int i = 0; i < n; ++i) 
		dp[i] = LLONG_MAX;
    dp[0] = 0;
    for (int i = 1; i < n; ++i) 
    {
        sol += cur + (cur * cur) * (1LL * i * i - (1LL * (i - 1LL) * (i - 1LL)));
        if (abs(A[i]) < abs(cur) || (abs(A[i]) == abs(cur) && A[i] < cur)) 
			cur = A[i];
    }
    cout << sol << endl;
    return 0;
}
