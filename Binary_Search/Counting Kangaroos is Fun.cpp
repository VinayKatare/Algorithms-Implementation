//https://codeforces.com/contest/372/problem/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
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
int a[1111111];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(12);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=0,r=n/2+1;
	
	while(l+1!=r){
		int mid=(l+r)/2;
    
		bool ok=true;
		
		for(int i=0;i<mid;i++){
			if(2*a[i] > a[n-mid+i]){
				ok=false;
				break;
			}
		}

		if(ok)l=mid;
		else r=mid;
	}
	
	cout<<n-l;
	return 0;
}
