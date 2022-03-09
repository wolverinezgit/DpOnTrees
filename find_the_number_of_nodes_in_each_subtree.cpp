



 #include <bits/stdc++.h>
using namespace std;
 #define ll long long
vector<int> dp;
int dfs(int node,int par,vector<int>& cost,vector<vector<int>>&G)
{

for(auto x:G[node])
{
    if(x!=par)
    {
        dp[node]+=dfs(x,node,cost,G);

    }

}

if(cost[node]>=0)
dp[node]++;

return dp[node];
}

int main(){
     
            

int n;
    cin>>n;
    vector<int> par(n+1);
    dp=vector<int> (n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>par[i];
    }
    vector<int> cost(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
    }

int i;
            vector<vector<int>> G(n+1);
            for(i=1;i<=n;i++)
            {
G[par[i]].push_back(i);
            }
            
            dfs(1,0,cost,G);
            int sum=0;
            for(i=1;i<=n;i++)
            {
                sum+=dp[i];
            }
            cout<<sum<<endl;
      return 0;
}

