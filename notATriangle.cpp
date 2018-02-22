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


int main()
{
   
    while(1)
    {
         ll i,x,ans=0,a,b,sum,j,n;
        cin>>n;
         if(n==0)
           return 0;
       
       vector<ll>vec;
       vector<ll>::iterator it;
       f(i,0,n)
       {
           cin>>x;
           vec.push_back(x);
       }
       sort(vec.begin(),vec.end());
       f(i,0,n)
       {
           a=vec[i];
           f(j,i+1,n)
           {
               b=vec[j];
               sum=a+b;
               it=upper_bound(vec.begin()+j+1,vec.end(),sum);
               ans+=vec.end()-it;
           }
       }
        cout<<ans<<endl;
    }
   
}


