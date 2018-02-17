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

vector<pair<ll,ll> >vec[10001];
ll visited[10001];
ll dist[10001];
ll n;

void dijkstra(ll s,ll d)
{
    ll i,ver,v,wt;
    f(i,1,n+1)
    visited[i]=0;
    
    f(i,1,n+1)
    dist[i]=inf;
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq ;
    pq.push(make_pair(0,s));
    dist[s]=0;pair<ll,ll>p,b;
    while(pq.empty()!=1)
    {
        p=pq.top();
        ver=p.second;
        visited[ver]=1;
        pq.pop();
        for(i=0;i<vec[ver].size();i++)
        {
            b=vec[ver][i];
            v=b.first;
            wt=b.second;
            if(visited[v]==0)
            {
                if(dist[v]>dist[ver]+wt)
                {
                    dist[v]=dist[ver]+wt;
                     pq.push(make_pair(dist[v],v));
                }
               
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
        ll no,i,x,w,m,so,de,j;
        string s,s1,s2;
        cin>>n;
        f(i,1,n+1)
        vec[i].clear();
        map<string,ll>mp;
        f(i,1,n+1)
        {
            cin>>s;
            cin>>no;
            mp.insert(make_pair(s,i));
            f(j,1,no+1)
            {
                cin>>x>>w;
                vec[i].push_back(make_pair(x,w));
            }
        }
        cin>>m;
        f(i,0,m)
        {
            cin>>s1>>s2;
            so=mp[s1];
            de=mp[s2];
            dijkstra(so,de);
            cout<<dist[de]<<endl;
        }
      
    }
   
}


