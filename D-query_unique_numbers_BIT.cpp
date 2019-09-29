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
int a[1111111],arr[1111111],l[1111111],ans[1111111],n;

void update(int idx,int val){
	while(idx <=n){
		a[idx]+=val;
		idx+=(idx& -idx);
	}
}

int query(int idx){
	int sum=0;
	while(idx > 0){
		sum+=a[idx];
		idx-=(idx& -idx);
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(12);

	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	int q;
	cin>>q;
	vector<pair<pair<int,int>,int>> v(q);
	for(int i=0;i<q;i++){
		cin>>v[i].F.S>>v[i].F.F;
		v[i].S=i;
	}
	sort(all(v));
	int k=0;
	// for(auto kk:v){
	// 	cout<<kk.F.F<<" "<<kk.F.S<<" "<<kk.S<<endl;
	// }
	bool f;
	for(int i=1;i<=n;i++){
		f=false;
		while(v[k].F.F == i){
			if(l[arr[i]]!=0)
			update(l[arr[i]],-1);
			update(i,1);
			ans[v[k].S]=query(v[k].F.F)-query(v[k].F.S-1);
			l[arr[i]]=i;
			k++;
			f=true;
		}
		if(!f){
			if(l[arr[i]]!=0)
			update(l[arr[i]],-1);
			update(i,1);
			l[arr[i]]=i;
		}
	}
	for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
	return 0;
}
