#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define all(a)                      a.begin(), a.end()
#define pb                          push_back
#define ll							long long
#define count_1 					__builtin_popcount
#define mod(x, m)					((((x) % (m)) + (m)) % (m))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

struct query {
	int l, r, i,k;
};

indexed_set st;

query q[100010];
ll a[100010], res[100010];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> a[i];

	for (int i = 0; i < m; i++) {
		cin >> q[i].l >> q[i].r>>q[i].k;
		q[i].l--, q[i].r--;	q[i].k--;
		q[i].i = i;
	}
	int BlOCKS = sqrt(n) + 1;
	sort(q, q + m, [=](query x, query y) {
		if (x.l / BlOCKS != y.l / BlOCKS)return x.l / BlOCKS < y.l / BlOCKS;
		return x.r < y.r;
	});

	int currentl = 1, currentr = 0;
	for (int i = 0; i < m; i++) {

	      while (currentl > q[i].l) {
            currentl--;
            st.insert(a[currentl]);
        }
        while (currentr < q[i].r) {
            currentr++;
            st.insert(a[currentr]);
        }
        while (currentl < q[i].l) {
            st.erase(st.find(a[currentl]));
            currentl++;
        }
        while (currentr > q[i].r) {
            st.erase(st.find(a[currentr]));
            currentr--;
        }
		res[q[i].i] = *st.find_by_order(q[i].k);
	}
	for (int i = 0; i < m; i++)cout << res[i] << '\n';
	return 0;
}
