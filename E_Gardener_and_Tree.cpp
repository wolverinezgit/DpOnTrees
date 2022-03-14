#include <bits/stdc++.h> 
using namespace std;
 #define ff first
#define ss second
#define ll long long 
#define pb push_back
  
int main()
{
 
 
  ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
 ll t;
 cin>>t;
 while(t--)
 {
     ll n,k;
     cin>>n>>k;
     if(n==1)
     {
         if(k)
         {
             cout<<0<<endl;
         
         }
         else
         cout<<1<<endl;
continue; 
         
             }
     vector<vector<ll>> G(n+1);
     ll i,j;
     ll x,y;
       vector<ll> deg(n+1,0);
       vector<ll> vis(n+1,0);
     for(i=0;i<n-1;i++)
     {
cin>>x>>y;
G[x].pb(y);
G[y].pb(x);
     }
     queue<ll> q,q1;
  
    
     for(i=1;i<=n;i++)
     {
         if(G[i].size()==1)
         {
         vis[i]=1;
           q.push(i);
           q1.push(i);
          
         
         }
         deg[i]=G[i].size();
     }  
     ll deleted=0;
     
     
     while(k--&&deleted<n)
     {
         ll sz=q.size();
         
         for(i=0;i<sz;i++)
         {
ll start=q.front();
q.pop();

deleted++;
deg[start]=0;
             for(auto z:G[start])
             {  
                
deg[z]--;
                    
                 
             }
         }
         
             for(j=1;j<=sz;j++)
             {
                 ll val=q1.front();
                 q1.pop();
                //  cout<<"val"<<val<<endl;
               for(auto zz:G[val])
             {
               
                    if(deg[zz]==1&&vis[zz]==0||(deg[zz]==0&&vis[zz]==0))
                    {
                        q.push(zz);
                        q1.push(zz);
                        vis[zz]=1;
                        
                       
                    }
                 
             }  
             }

         }
         cout<<n-deleted<<endl;
    

 }
 return 0;
}