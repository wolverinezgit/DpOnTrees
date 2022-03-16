#include <bits/stdc++.h>
using namespace std;


#define ll long long int 
#define pb push_back
vector<ll> subtree,dist;
ll n;
int dfs(int curr,int par,vector<vector<ll>>&G)
{
    ll add=0,sum=0;
for(auto x:G[curr])
{
    if(x!=par)
    {
      add+=dfs(x,curr,G);
sum=sum+dist[x]+subtree[x];
    }
}
subtree[curr]=add+1;
dist[curr]=sum;
return subtree[curr];
}
void dfs2(int curr,int par,vector<vector<ll>>&G)
{
    for(auto x:G[curr])
    {
        if(x!=par)
        {
dist[x]=dist[curr]-subtree[x]+(n-subtree[x]);
dfs2(x,curr,G);
        }
    }
}
int main()
{

cin>>n;
vector<vector<ll>> G(n+1);
ll i;
for(i=0;i<n-1;i++)
{
    ll xx,yy;
    cin>>xx>>yy;
    G[xx].pb(yy);
    G[yy].pb(xx);
}
subtree=vector<ll>(n+1,0);
dist=vector<ll>(n+1,0);
dfs(1,-1,G);

dfs2(1,-1,G);

for(i=1;i<=n;i++)
{
    cout<<dist[i]<<" ";
}



return 0;
}
