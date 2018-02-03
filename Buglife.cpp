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

vector<ll>vec[2005];
ll col[2005];

ll bfs(ll i)
{
    ll flag=0,x,j;
    queue<ll>q;
    q.push(i);
    col[i]=1;
    while(q.empty()!=1)
    {
        x=q.front();
        q.pop();
        for(j=0;j<vec[x].size();j++)
        {
            if(col[vec[x][j]]==-1)
            {
                q.push(vec[x][j]);
                col[vec[x][j]]=!col[x];
            }
            else if(col[vec[x][j]]==col[x])//CHECK FOR ODD CYCLE
            flag=1;
        }
    }
    return flag;
}
int main()
{
  ll t,g;
  cin>>t;
  for(g=1;g<=t;g++)
  {
      ll n,m,flag=0,i,x,y;
      cin>>n>>m;
      
      for(i=1;i<=n;i++)
      vec[i].clear();
      
      for(i=1;i<=n;i++)
         col[i]=-1;
      
      f(i,0,m)
      {
          cin>>x>>y;
          vec[x].push_back(y);
          vec[y].push_back(x);
          if(x==y)
          flag=1;
       }
       
       f(i,1,n+1)
       {
           if(col[i]==-1)
           {
               flag=bfs(i);
               if(flag==1)
               break;
           }
       }
       cout<<"Scenario #"<<g<<":\n";
       if(flag==1)
       cout<<"Suspicious bugs found!\n";
       else
       cout<<"No suspicious bugs found!\n";
       
       
     
  }
}


