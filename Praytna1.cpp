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

vector<ll>vec[100000];
ll visited[100000];
void bfs(ll i)
{
    ll x,j;
    queue<ll>q;
    q.push(i);
    visited[i]=1;
    while(q.empty()!=1)
    {
        x=q.front();
        q.pop();
        for(j=0;j<vec[x].size();j++)
        {
            if(visited[vec[x][j]]==0)
            {
                visited[vec[x][j]]=1;
                q.push(vec[x][j]);
            }
        }
    }
}

int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
      ll n,i,cc=0,m,x,y;
      cin>>n;
      cin>>m;
     f(i,0,n)
     vec[i].clear();
     f(i,0,n)
     visited[i]=0;
     f(i,0,m)
     {
         cin>>x>>y;
         vec[x].push_back(y);
         vec[y].push_back(x);
     }
     
     f(i,0,n)
     {
         if(visited[i]==0)
         {
             cc++;
             bfs(i);
         }
     }
     cout<<cc<<endl;
  }
}


