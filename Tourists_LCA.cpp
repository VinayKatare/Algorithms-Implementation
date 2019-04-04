//https://open.kattis.com/problems/tourists
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define all(a)                      a.begin(), a.end()
#define pb                          push_back
#define ll                          long long
#define index(a)                    order_of_key(a)
#define value(a)                    find_by_order(a)
#define count_1                     __builtin_popcount
#define mod(x, m)                   ((((x) % (m)) + (m)) % (m))
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int h[1000000];
int l;
int dp[1000000][32];
vector<int> v[1000000];

void dfs(int u,int p){
    dp[u][0]=p;
    h[u]=1+h[p];
    for(auto x:v[u]){
        if(x!=p){
            dfs(x,u);
        }
    }
}

int lca(int x,int y){
    if(h[x] < h[y])swap(x,y);
    
    int jmp;
    for(jmp=0; (1<<jmp) <= h[x]; jmp++);
    
    jmp--;
    
    for(int i=jmp ;i>=0;i--){
        if( h[x] - (1<<i) >= h[y])
        x=dp[x][i];
    }
    
    if(x==y)return x;
    
    for(int i=jmp ;i>=0;i--){
        if(dp[x][i] !=-1 && dp[x][i]!=dp[y][i]){
            x=dp[x][i];
            y=dp[y][i];
        }
    }
    return dp[x][0];
}

int dis(int x,int y){
    int LCA=lca(x,y);
    return h[x]+h[y]-2*h[LCA];
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(12);
    int n,x,y;
    ll ans=0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    
    while((1<<l) < n)l++;

    memset(dp,-1,sizeof(dp));
    
    h[0]=-1;
    
    dfs(1,0);
 
    for(int i=1;i<=l;i++){
        for(int j=1;j<=n;j++){
            if(dp[j][i-1]!=-1)
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            ans+=dis(i,j)+1;
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}
