#include<bits/stdc++.h>
using namespace std;
 
int sgt[400001][10];
int lazy[400001];
 
 
void build(int s,int e,int pos)
{
    if(s == e)
    {
        sgt[pos][0] = 1;
        return;
    }
 
    build(s, (s+e)/2, 2*pos+1);
    build((s+e+2)/2, e, 2*pos+2);
 
    for(int i = 0; i < 10; i++)
    {
        sgt[pos][i] = sgt[2*pos+1][i]+sgt[2*pos+2][i];
    }
}
 
void update(int s, int e, int us, int ue, int pos)
{
    if(lazy[pos] != 0)
    {
        int temp[10];
        for(int i = 0; i < 10; i++)
            temp[i] = sgt[pos][i];
 
        for(int i = 0;i <= 9; i++)
        {
            sgt[pos][i] = temp[(i+10-(lazy[pos]%10))%10];
        }
 
        if(s != e)
        {
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
 
    if(us<=s && ue>=e)
    {
        int temp[10];
        for(int i=0;i<10;i++)
            temp[i] = sgt[pos][i];
 
        for(int i=0;i<=9;i++)
            sgt[pos][i] = temp[(i+9)%10];

        if(s != e)
        {
            lazy[2*pos+1] +=1;
            lazy[2*pos+2] +=1;
        }
        return;
    }
    if(us > e || ue < s)
        return;
 
    update(s, (s+e)/2, us, ue, 2*pos+1);
    update((s+e)/2+1, e, us, ue, 2*pos+2);
 
    for(int i = 0; i <= 9; i++)
        sgt[pos][i] = sgt[2*pos+1][i] + sgt[2*pos+2][i];
}
 
int query(int s,int e,int qs,int qe,int pos)
{
    if(lazy[pos] != 0)
    {
        int temp[10];
        for(int i = 0;i < 10; i++)
            temp[i] = sgt[pos][i];
 
        for(int i=0;i<=9;i++)
        {
            sgt[pos][i] = temp[(i+10-(lazy[pos]%10))%10];
        }
 
        if(s!=e)
        {
            lazy[2*pos+1] += lazy[pos],lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
 
    if(qs>e || qe<s)
    {
        return 0;
    }
 
    if(qs<=s && qe>=e)
    {
        int s=0;
        for(int i=0;i<10;i++)
            s+=i*sgt[pos][i];
 
        return s;
    }
 
    return query(s,(s+e)/2,qs,qe,2*pos+1)+query((s+e+2)/2,e,qs,qe,2*pos+2);
}
 
int main()
{
    int n,q;
    cin>>n>>q;
 
    build(0,n-1,0);
    while(q--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        l--,r--;
        if(t==1)
			update(0,n-1,l,r,0);
        if(t==2)
            cout<<query(0,n-1,l,r,0)<<endl;
    }
}
