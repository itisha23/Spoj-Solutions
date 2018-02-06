/*BFS FOR UNWEIGHTED GRAPH  AND SEIVE (BRUTE FORCE)*/


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

ll prime[10005];

void seive()
{
    ll i,j;
    f(i,1,10005)
    prime[i]=1;
    for(i=2;i*i<10005;i++)
    {
        if(prime[i]==1)
        {
            for(j=2*i;j<10005;j+=i)
                prime[j]=0;
        }
    }
}

void make_digit(ll digit[],ll a)
{
    ll k=3;
    while(a!=0)
    {
        digit[k]=a%10;
        a=a/10;
        k--;
    }
}

ll make_number(ll digit[])
{
    ll nu=0,k;
    for(k=0;k<=3;k++)
    {
        nu=nu*10+digit[k];
    }
    return nu;
}

int main()
{
   ll t;
   cin>>t;
   seive();
   while(t--)
   {
       ll a,b,i,j,s,num;
       cin>>a>>b;
       ll digit[4];
       ll dist[10005];
       f(i,0,10005)
       dist[i]=-1;
       queue<ll>q;
       q.push(a);
       dist[a]=0;
       while(q.empty()!=1)
       {
           s=q.front();
           q.pop();
           for(i=0;i<=3;i++)
       {
           make_digit(digit,s);
           for(j=0;j<=9;j++)
           {
                digit[i]=j;
                num=make_number(digit);
                if(prime[num]==1 && dist[num]==-1 && num>=1000)
                {
                    dist[num]=dist[s]+1;//PRIMARY STEP IN BFS.
                    q.push(num);
                }
           }
          
       }
       }
       if(dist[b]==-1)
       cout<<"Impossible";
       else
       cout<<dist[b]<<endl;
   }
}


