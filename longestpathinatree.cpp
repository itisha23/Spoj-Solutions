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

ll no,g,count1=0,maxi=INT_MIN;
vector<ll>vec[100005];
ll visited[100005];

map<ll,ll>ma;

void bfsnew(ll x)
{
    ll i,s;
    queue<ll>q;
    q.push(x);
   visited[x]=1;
   ma.insert(make_pair(x,0));
     while(q.empty()!=1)
   {
       s=q.front();
       q.pop();
       for(i=0;i<vec[s].size();i++)
       {
           if(visited[vec[s][i]]==0)
             {
                 q.push(vec[s][i]);
                 visited[vec[s][i]]=1;
                 ma.insert(make_pair(vec[s][i],ma[s]+1));
             }
       }
       
   }
}
void bfs(ll x)
{
   ll i,s;
    queue<ll>q;
    q.push(x);
     visited[x]=1;
     while(q.empty()!=1)
   {
      
       s=q.front();
       q.pop();
       count1++;
       if(count1==no)
           g=s;
     // {  cout<<count1<<endl;g=s;cout<<s<<endl;}
        //cout<<s<<endl;
       for(i=0;i<vec[s].size();i++)
       {
           if(visited[vec[s][i]]==0)
             {
                 q.push(vec[s][i]);
                 visited[vec[s][i]]=1;
                 //m.insert(make_pair(vec[s][i],ma[vec[s][i]])+1);
             }
       }
       
   }
}

int main()
{

  
      ll i,x,y,ans,n;
      cin>>n;
      no=n;
      if(n==1)
       {
         cout<<0<<endl;
       }
     else
{
      
      f(i,1,n+1)
        visited[i]=0;
      f(i,1,n)
      {
          cin>>x>>y;
          vec[x].push_back(y);
          vec[y].push_back(x);
      }
     
     bfs(1);
     //cout<<g<<endl;
     f(i,1,n+1)
        visited[i]=0;
     bfsnew(g);
    map<ll,ll>::iterator it;
    // for(it=ma.begin();it!=ma.end();it++)
       //  cout<<it->second<<" ";
     // cout<<endl;
    for(it=ma.begin();it!=ma.end();it++)
    maxi=max(maxi,it->second);
    cout<<maxi;
}
  }



