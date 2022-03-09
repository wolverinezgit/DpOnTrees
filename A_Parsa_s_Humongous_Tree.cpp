    #include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define pb push_back
ll dp[(ll)(1e5+1)][2];
void dfs(int node,int par,vector<vector<ll>>&G,vector<ll>&f,vector<ll> &s)
{
for(auto x:G[node])
{

    if(x!=par)
    {
        dfs(x,node,G,f,s);
        if(abs(f[x]-f[node])+dp[x][0]>abs(s[x]-f[node])+dp[x][1])
     dp[node][0]+=(dp[x][0]+abs(f[x]-f[node]));
     else
        dp[node][0]+=(dp[x][1]+abs(s[x]-f[node]));
        if(abs(f[x]-s[node])+dp[x][0]>abs(s[x]-s[node])+dp[x][1])
     dp[node][1]+=(dp[x][0]+abs(f[x]-s[node]));
     else
        dp[node][1]+=(dp[x][1]+abs(s[x]-s[node]));
    }
}

}

int main()
{
    ll t;
     ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
    cin>>t;

    while(t--)
    {
        memset(dp,0,sizeof dp);
        ll n;
cin>>n;
vector<ll> f(n),s(n);
ll i;
for(i=0;i<n;i++)
cin>>f[i]>>s[i];
vector<vector<ll>> G(n);
for(i=0;i<n-1;i++)
{
ll x,y;
cin>>x>>y;
G[x-1].pb(y-1);
G[y-1].pb(x-1);
}
dfs(0,-1,G,f,s);
cout<<max(dp[0][0],dp[0][1])<<endl;

    }
    return 0;
}