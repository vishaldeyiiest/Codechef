#include <iostream>
#include <bitset>
using namespace std;
 
int main()
{
    long int n1,n2,count=0;
    string a[10007],b[10007];
    cin>>n1>>n2;
    bitset<26> str1[n1],str2[n2],str3;
    
    for(int i=0; i < n1; i++)
        cin>>a[i];
    for(int i=0; i < n2; i++)
        cin>>b[i];
    for(int i=0; i < n1; i++)
        for(unsigned int j=0; j < a[i].size(); j++)
            str1[i][a[i][j]-'A']=1;
      
    for(long int i=0; i<n2; i++)
        for(unsigned int j=0; j<b[i].size(); j++)
            str2[i][b[i][j]-'A']=1;
 
    for(long int i=0; i<n1; i++)
    {
        for(long int j=0; j<n2; j++)
        {
            str3=str1[i];
            str3|=str2[j];
            if(str3.count()==26)
                count++;
 
        }
 
    }
    cout<<count<<endl;
}
