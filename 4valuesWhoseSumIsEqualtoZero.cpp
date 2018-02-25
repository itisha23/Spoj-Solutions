#include<bits/stdc++.h>
using namespace std;
 
#define f(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf 2e18
#define pb push_back
#define fi first
#define se second
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld",a)
 
 
typedef int l;
typedef unsigned int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
 
 
int main()
{
   // fast;
    ll n,i,x,a,b,c,d,j,cou=0,ans=0,sum1,sum2;
    cin>>n;
  vector<ll>vec[6];
  pair<vector<ll>::iterator,vector<ll>::iterator> it;
  
    f(i,0,n)
    {
      cin>>a>>b>>c>>d;
       vec[0].push_back(a);
       vec[1].push_back(b);
       vec[2].push_back(c);
       vec[3].push_back(d);
       
    }
    f(i,0,n)
    {
       f(j,0,n)
       {
           sum1=vec[0][i]+vec[1][j];
           sum2=-(vec[2][i]+vec[3][j]);
           vec[4].push_back(sum1);
           vec[5].push_back(sum2);
       }
    }
    sort(vec[5].begin(),vec[5].end());
    f(i,0,vec[4].size())
    {
        x=vec[4][i];
        if(binary_search(vec[5].begin(),vec[5].end(),x))
         {it=equal_range(vec[5].begin(),vec[5].end(),x);cou=it.second-it.first;
        ans+=cou;}
    }
    cout<<ans;
}
