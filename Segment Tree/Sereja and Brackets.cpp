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
int n, q;
string s;
struct tre {
	int t, o, c;
};

tre tr[10000100];

void build(int id, int start, int end) {
	if (start > end)return;
	if (start == end) {
		//	cout<<id<<" "<<start-1<<" "<<s[start-1]<<endl;
		if (s[start - 1] == '(')tr[id].o = 1;
		else tr[id].c = 1;
		return;
	}
	int mid = (start + end) >> 1;

	build(2 * id, start, mid);
	build(2 * id + 1, mid + 1, end);

	int x = min(tr[2 * id].o, tr[2 * id + 1].c);

	tr[id].t = tr[2 * id].t + tr[2 * id + 1].t + x;
	tr[id].o = tr[2 * id].o + tr[2 * id + 1].o - x;
	tr[id].c = tr[2 * id + 1].c + tr[2 * id].c - x;
}

void query(int id, int l, int r, int start, int end, tre& ans) {

	if (l > end || r < start)return;

	if (start >= l && end <= r) {
		int x = min(ans.o, tr[id].c);
		ans.t = ans.t + tr[id].t + x;
		ans.o = ans.o + tr[id].o - x;
		ans.c = ans.c + tr[id].c - x;
		return;
	}

	int mid = (start + end) >> 1;

	query(2 * id, l, r, start, mid, ans);
	query(2 * id + 1, l, r, mid + 1, end, ans);

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);
	cin >> s >> q;
	n = s.size();
	int l, r;
	build(1, 1, n);
	//	for(int i=1;i<2*n;i++)cout<<tr[i].t<<" ";cout<<endl;
		//exit(0);
	while (q--) {
		cin >> l >> r;
		tre ans = {};
		query(1, l, r, 1, n, ans);
		cout << 2 * ans.t << endl;
	}

	return 0;
}