/*DETECTION OF CYCLE USING DFS */

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

ll n,cnt=0;
vector<ll>vec[10005];
vector<ll>adj[10005];
priority_queue<ll,vector<ll>,greater<ll> >pq;
vector<ll>v;

ll d=0;
 set<ll>white;
 set<ll>gray;
 set<ll>black;
    
ll dfs(ll x)
{
    ll i;
    gray.insert(x);
    white.erase(white.find(x));
    for(i=0;i<vec[x].size();i++)
    {
        if(white.count(vec[x][i]))
           d=d|dfs(vec[x][i]);
        if(gray.count(vec[x][i]))
             d=1;
    }
    black.insert(x);
    gray.erase(gray.find(x));
    return d;
}

ll iscycle()
{
    ll a=0,i;
   
   for(i=1;i<=n;i++)
      white.insert(i);
   while(white.size()!=0)
   {
       a=dfs(*white.begin());
       //cout<<"Hi";
   }
      return a;
}







void topos()
{
  
      ll i,j,x;
       ll indegree[n+1];
       f(i,1,n+1)
       indegree[i]=0;

       f(i,1,n+1)
           f(j,0,vec[i].size())
               indegree[vec[i][j]]++;

       f(i,1,n+1)
          if(indegree[i]==0)
              {
               pq.push(i);
               
              }
   
     while(pq.empty()!=1)
       {
           x=pq.top();
           v.push_back(x);
           cnt++;
           pq.pop();
          
           f(i,0,vec[x].size())
           {
                  indegree[vec[x][i]]--;
              if(indegree[vec[x][i]]==0)
             {
                 pq.push(vec[x][i]);
              }    
          }
   }
}

int main()
{
    ll m,i,x,y,ans=0,j,flag;
    cin>>n>>m;
    f(i,0,m)
    {
        cin>>x>>y;
       vec[x].push_back(y);
    }
    ans=iscycle();
    if(ans==1)
    cout<<"Sandro fails.";
    else
    {
       topos();
       f(i,0,v.size())
         cout<<v[i]<<" ";
    }  
  
}


