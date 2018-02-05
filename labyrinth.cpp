/* USED A VERY SIMPLE METHOD*/
/*1.CONVERTED THE GIVEN MATRIX TO GRAPH
2. SINCE IT IS A ACYCLIC GRAPH WE CAN APPLY LONGEST PATH BTW TWO NODES USING TWO BFS
3.BUT REMEMBER THIS CAN BE A DISCONNECTED GRAPH UNLIKE PTO7Z OF SPOJ.*/

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

vector<ll>vec[1000005];
ll visited1[1000005];
ll visited[1000005];
map<ll,ll>ma;

// CALCULATES NO OF ELEMENTS IN A PARTICULAR COMPONENT*/
ll bfs1(ll x)
{
    ll i,s,cou=0;
    queue<ll>q;
    q.push(x);
    visited1[x]=1;
    while(q.empty()!=1)
    {
        s=q.front();
        cou++;
        q.pop();
        f(i,0,vec[s].size())
        {
            if(visited1[vec[s][i]]==0)
            {
                q.push(vec[s][i]);
                visited1[vec[s][i]]=1;
            }
        }
    }
    return cou;
}

//CALCULATES THE LAST VERTEX AND STORE IT IN GIVEN NO OF ELEMENTS IN A PARTICULAR COMPONENT
void bfs(ll x,ll &g,ll n)
{
    ll i,s,cou=0;
    queue<ll>q;
    q.push(x);
    visited[x]=1;
    while(q.empty()!=1)
    {
        s=q.front();
        cou++;
        q.pop();
        if(cou==n)
           g=s;
        f(i,0,vec[s].size())
        {
            if(visited[vec[s][i]]==0)
            {
                q.push(vec[s][i]);
                visited[vec[s][i]]=1;
            }
        }
    }
   
}

//CALULATES DIAMETER
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

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    
        ll c,r,dot=0,i,j,ans=INT_MIN,cou1,cou2,con,maxi,g;
        cin>>c>>r;
        char mat[r+1][c+1];
        f(i,1,r+1)
        {
            f(j,1,c+1)
            {
                 cin>>mat[i][j];
                 if(mat[i][j]=='.')
                     dot++;//DOT STORES THE TOTAL NUMBER OF NODES IN  A GRAPH.
            }
        }
        
        f(i,1,dot+1)
        vec[i].clear();

        f(i,1,dot+1)
        visited1[i]=0;
        map<ll,ll>mp;
        map<ll,ll>::iterator it;
        
        //CREATES A MAP WHICH STORES THE ELEMENT NUMBER CORRESPONDING TO THE NODE NUMBER.
        cou1=1,cou2=1;
        f(i,1,r+1)
        {
            f(j,1,c+1)
            {
                if(mat[i][j]=='.')
                {
                    mp.insert(make_pair(cou1,cou2));
                    cou2++;
                }
                cou1++;
            }
        }

      //JOINS ADJACENT NODES IN A ROW
        cou1=1;
        f(i,1,r+1)
        {
            f(j,1,c)
            {
                if(mat[i][j]=='.' && mat[i][j+1]=='.')
                {
                    vec[mp[cou1]].push_back(mp[cou1+1]);
                    vec[mp[cou1+1]].push_back(mp[cou1]);
                }
                cou1++;
            }
            cou1++;
         }

        //JOINS ADJACENT NODES IN A COLUMMN
        cou2=1;
        f(j,1,c+1)
        {
             cou1=cou2;
              f(i,1,r)
            {
                if(mat[i][j]=='.' && mat[i+1][j]=='.')
                {
                    vec[mp[cou1]].push_back(mp[cou1+c]);
                    vec[mp[cou1+c]].push_back(mp[cou1]);
                }
                 cou1=cou1+c;
            }
           cou2++;
        }

       f(i,1,dot+1)
        {
          /*VISITED1 IS A UNIVERSAL ARRAY USED TO FIND MAX IN DISCONNECTED COMPONENTS*/
           if(visited1[i]==0)
            {
                maxi=INT_MIN;
                f(j,1,dot+1)
                  visited[j]=0;
                con=bfs1(i);
                bfs(i,g,con);
                f(i,1,dot+1)
                   visited[i]=0;
                bfsnew(g);
                for(it=ma.begin();it!=ma.end();it++)
                {
                    maxi=max(maxi,it->second);
                }
           }
           ma.clear();
           ans=max(ans,maxi);
        }
       cout<<"Maximum rope length is "<<ans<<"."<<endl;
      
    }
    
}
