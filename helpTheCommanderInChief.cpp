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

vector<l>vec[100005];
ll path[100005];

ll countpaths(ll u,ll v)
{
    ll i,cou;
    if(u==v)
    return 1;
    if(path[u]!=-1)
      return path[u];
    cou=0;
    f(i,0,vec[u].size())
    {
        cou=((cou%mod)+(countpaths(vec[u][i],v)%mod))%mod;;
    }
    path[u]=cou;
    return path[u];
}

int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
      ll n,m,s,d,i,x,y,ans;
      cin>>n>>m>>s>>d;
      f(i,1,n+1)
      vec[i].clear();
      f(i,1,n+1)
      path[i]=-1;
      f(i,0,m)
      {
          cin>>x>>y;
          vec[x].push_back(y);
      }
      ans=countpaths(s,d);
      cout<<ans<<endl;
  }
}


