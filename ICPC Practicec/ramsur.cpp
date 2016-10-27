#include <bits/stdc++.h>
#define ll long long int
#define L 100005
using namespace std ;
char s[L] ;
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int ans = 0, cur_len=0 ;
        ll A, B, val = 0 ;
        scanf("%s %lld %lld", s, &A, &B );
        int len = strlen(s) ;
        for(int i = 0; i < len; i++)
        {
            cur_len++;
            val = val*10 + s[i]-'0' ;
            if(val > B && cur_len == 1 ) 
            { 
				ans = -1;
				break;
			}
            if(val > B)
            {
                ll temp = 0;
                cur_len = 0;
                while(val > B)
					temp = (temp*10) + (val%10), cur_len++, val = val/10 ;
                if(val >= A) 
					ans++, val = temp ;
                else 
                { 
					ans = -1;
					break;
				}
            }
        }
        cout<<ans<<endl ;
    }
    return 0 ;
}

