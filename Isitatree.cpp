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

vector<ll>vec[10005];
ll visited[100005];

void dfs(ll s)
{
    ll i;
    //cout<<s<<" ";
    visited[s]=1;
    for(i=0;i<vec[s].size();i++)
    {
        if(visited[vec[s][i]]==0)
        dfs(vec[s][i]);
    }
}

int main()
{
    ll n,m,i,x,y,cc=0;
    cin>>n>>m;

    
    f(i,1,n+1)
    visited[i]=0;

    f(i,0,m)
    {
       cin>>x>>y;
       vec[x].push_back(y);
       vec[y].push_back(x);
    }
    f(i,1,n+1)
    {
        if(visited[i]==0)
        {
           
            dfs(i);
             cc++;
        }
    }
    //cout<<cc<<endl;
    if(cc==1 && m==(n-1))
    cout<<"YES";
    else
    cout<<"NO";
  
}


