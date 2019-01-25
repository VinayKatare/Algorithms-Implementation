//https://codeforces.com/contest/339/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define all(a)                      a.begin(), a.end()
#define pb                          push_back
#define ll							long long
#define index(a)            		order_of_key(a)
#define value(a)					find_by_order(a)
#define count_1 					__builtin_popcount
#define mod(x, m)					((((x) % (m)) + (m)) % (m))
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int a[1000000], tr[1000000], n, pos;
void build(int d, int id = 1, int l = 1, int r = n) {
	//	cout<<pos<<" ";
	if (pos < l || pos>r)return;
	if (l == r) {
		tr[id] = a[l];
		return;
	}

	int mid = (l + r) / 2;
	build(d ^ 1, 2 * id, l, mid);
	build(d ^ 1, 2 * id + 1, mid + 1, r);
	if (!(d & 1))
		tr[id] = tr[2 * id] ^ tr[2 * id + 1];
	else
		tr[id] = tr[2 * id] | tr[2 * id + 1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);
	int m, needl, needr, x;
	cin >> n >> m;
	int sign = n % 2;
	n = 1 << n;
	for (int i = 1; i <= n; i++) { cin >> a[i]; pos = i; build(sign); }

	//cout<<endl;	for(int i=1;i<2*n;i++)cout<<tr[i]<<" ";cout<<endl;

	int idx;
	while (m--) {
		cin >> pos >> x;
		a[pos] = x;
		build(sign);
		//	for(int i=1;i<2*n;i++)cout<<tr[i]<<" ";cout<<endl;
		cout << tr[1] << endl;
	}
	return 0;
}