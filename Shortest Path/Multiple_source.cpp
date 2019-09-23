//Instead of pushing single src in priority_queue. Push all the srcs with distance 0. Remaining dijkstra is same as usual.

//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/booze-first-76e979dd/

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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(12);
	ll n,m,b,x,y,w;
	cin>>n>>m;
	vector<pair<ll,ll>> v[n+1];
	ll d[n+1]={};
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	cin>>b;
	priority_queue<pair<ll,ll>> q;
	fill(d,d+n+1,INT_MAX);
	while(b--){
		cin>>x;
		d[x]=0;
		q.push({d[x],x});
	}
	
	while(!q.empty()){
		auto u=q.top().S;
		q.pop();
		for(auto x:v[u]){
			ll v=x.F;
			ll w=x.S;
			if(d[u]+w < d[v]){
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<d[i]<<"\n";
	return 0;
}
