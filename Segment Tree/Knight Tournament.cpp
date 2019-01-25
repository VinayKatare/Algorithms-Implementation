//https://codeforces.com/contest/356/problem/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define all(a)                      a.begin(), a.end()
#define pb                          push_back
#define ll                            long long
#define index(a)                    order_of_key(a)
#define value(a)                    find_by_order(a)
#define count_1                     __builtin_popcount
#define mod(x, m)                    ((((x) % (m)) + (m)) % (m))
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int tr[10000000];
int ans[10000000];
void build(int id, int start, int end) {
	if (start == end) {
		ans[start] = start;
		tr[id] = 1;
		return;
	}


	int mid = (start + end) >> 1;

	build(2 * id, start, mid);
	build(2 * id + 1, mid + 1, end);

	tr[id] = tr[2 * id] + tr[2 * id + 1];
}

void query(int id, int l, int r, int x, int start, int end) {
	if (l > end || r < start)return;
	if (tr[id] == 0)return;
	if (start == end) {
		if (start == x)
			return;
		tr[id] = 0;
		ans[start] = x;
		return;
	}

	int mid = (start + end) >> 1;
	query(2 * id, l, r, x, start, mid);
	query(2 * id + 1, l, r, x, mid + 1, end);

	tr[id] = tr[2 * id] + tr[2 * id + 1];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);
	int n, q, l, r, x;
	cin >> n >> q;
	build(1, 1, n);

	while (q--) {
		// for(int i=1;i<2*n;i++)cout<<tr[i]<<" ";cout<<endl;
		cin >> l >> r >> x;
		query(1, l, r, x, 1, n);
	}

	for (int i = 1; i <= n; i++)cout << (ans[i] == i ? 0 : ans[i]) << " ";
	return 0;
}