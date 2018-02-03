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
ll arr[100000];
ll size[100000];

ll root(ll x)
{
    ll temp=x;
    while(arr[x]!=x)
    x=arr[x];
    arr[temp]=x;
    return x;
}
void union1(ll x,ll y)
{
    ll root_x=root(x);
    ll root_y=root(y);
    
    ll size_x=size[x];
    ll size_y=size[y];
    if(size_x<size_y)
    {
        arr[root_x]=root_y;
        size[root_y]+=size[root_x];
    }
    else
    {
        arr[root_y]=root_x;
        size[root_x]+=size[root_y];
    }
}

int main()
{
  fast;
  ll t;
  cin>>t;
  while(t--)
  {
      ll n,i,m,x,y;
      cin>>n;
      cin>>m;
      f(i,0,n)
      arr[i]=i;
      f(i,0,n)
      size[i]=1;
      f(i,0,m)
      {
          cin>>x>>y;
          union1(x,y);
      }
      set<ll>s;
      f(i,0,n)
      {
          s.insert(root(i));
      }
      cout<<s.size()<<endl;
  }
}


