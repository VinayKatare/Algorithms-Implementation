https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/the-parking-slot-9fac40d6/

#include <bits/stdc++.h>
using namespace std;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;		use cpp_int instead of int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define all(a)                      a.begin(), a.end()
#define F							first
#define S							second
#define pb                          push_back
#define ll							long long
#define index(a)            		order_of_key(a)
#define value(a)					find_by_order(a)
#define count_1 					__builtin_popcount
#define mod(x, m)					((((x) % (m)) + (m)) % (m))
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pre_trie;
bool vis[1111111];
vector<pair<ll,ll>> v[1111111];
ll cap[1111111],d[1111111];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(12);
	ll n,m,parking_fee,w,x,y,vecls;
	cin>>n>>m>>parking_fee;
	fill(d,d+1111111,100000000000000);
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)cin>>cap[i];
	
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	cin>>vecls;
	
	priority_queue<pair<ll,ll>> q;
	ll src=1;
	d[src]=0;
	q.push({d[src],src});
	
	while(!q.empty()){
		auto u=q.top().S;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		
		for(int i=0;i<min(cap[u],vecls);i++)cout<<parking_fee+d[u]<<" ";
		vecls-=min(cap[u],vecls);
		for(auto x:v[u]){
			ll v=x.F;
			ll w=x.S;
			if(d[u]+w < d[v]){
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
	
	while(vecls--)cout<<-1<<" ";
	return 0;
}
