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

ll root(ll arr[],ll x)
{
    ll temp=x;
    while(arr[x]!=x)
    x=arr[x];
    arr[temp]=x;
    return x;
}

ll size[100001];

void union1(ll arr[],ll x,ll y)
{
    ll root_x=root(arr,x);
    ll root_y=root(arr,y);
    
    ll size_x=size[x];
    ll size_y=size[y];
    
    if(size_x<size_y)
    {
        arr[root_x]=root_y;
        size[root_y]+=size_x;
    }
    else
    {
        arr[root_y]=root_x;
        size[root_x]+=size_y;
        
    }
}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,mo,i,x,y,ans1,pro;
        cin>>n>>mo;
        ll arr[n+1];
        
        f(i,1,n+1)
        arr[i]=i;
        
          f(i,1,n+1)
          size[i]=1;
        
        f(i,0,mo)
        {
            cin>>x>>y;
            union1(arr,x,y);
        }
        
        map<ll,ll>m;
        f(i,1,n+1)
        {
            m.insert(make_pair(root(arr,i),0));
        }
        f(i,1,n+1)
        {
            m[root(arr,i)]++;
        }
        ans1=m.size();
         map<ll,ll>::iterator it;pro=1;
         for(it=m.begin();it!=m.end();it++)
         {
             pro=((pro%mod)*(it->second%mod))%mod;
         }
        cout<<ans1<<" "<<pro<<endl;
        
    }
  
}



