#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf 2e18
#define pb push_back
#define fi first
#define se second

typedef int l;
typedef unsigned int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;


int main()
{
    ll n,i,a,b,c,d,e,f,j,k,val1,val2,ans=0;
    cin>>n;
    ll arr[n];
    f(i,0,n)
    cin>>arr[i];
    vector<ll>vec1,vec2;
    f(i,0,n)
    {
        a=arr[i];
        f(j,0,n)
        {
            b=arr[j];
            f(k,0,n)
            {
                c=arr[k];f=arr[k];
                val1=a*b+c;
                
                vec1.push_back(val1);
               
            }
        }
    }
    f(i,0,n)
    {
        d=arr[i];if(d!=0){
        f(j,0,n)
        {
            e=arr[j];
            f(k,0,n)
            {
                f=arr[k];
                
                val2=(f+e)*d;
              vec2.push_back(val2);
            }
        }}
    }
    sort(vec2.begin(),vec2.end());
    f(i,0,vec1.size())
    {
        ans=ans+(upper_bound(vec2.begin(),vec2.end(),vec1[i])-lower_bound(vec2.begin(),vec2.end(),vec1[i]));
    }
    cout<<ans;
}


