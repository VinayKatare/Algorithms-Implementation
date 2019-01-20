//https://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>
using namespace std;

#define all(a)                      a.begin(), a.end()
#define pb                          push_back
#define ll							long long
#define index(a)            		order_of_key(a)
#define value(a)					find_by_order(a)
#define count_1 					__builtin_popcount
#define mod(x, m)					((((x) % (m)) + (m)) % (m))

struct query {
	int l, r, i;
};

query q[200010];

int n, m;
int a[300010], cnt[1000010], ans[300010], unq;

void add(int idx) {
	cnt[a[idx]]++;
	if (cnt[a[idx]] == 1)unq++;
}

void remove(int idx) {
	cnt[a[idx]]--;
	if (cnt[a[idx]] == 0)unq--;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);

	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].l--, q[i].r--;
		q[i].i = i;
	}

	int BLOCKS = sqrt(n) + 1;

	sort(q, q + m, [=](query x, query y) {
		if (x.l / BLOCKS != y.l / BLOCKS) return x.l / BLOCKS < y.l / BLOCKS;
		return x.r < y.r;
	}
	);

	int currentL = 1, currentR = 0;

	for (int i = 0; i < m; i++) {

		while (currentL < q[i].l) {
			remove(currentL);
			currentL++;
		}

		while (currentL > q[i].l) {
			currentL--;
			add(currentL);
		}

		while (currentR < q[i].r) {
			currentR++;
			add(currentR);
		}

		while (currentR > q[i].r) {
			remove(currentR);
			currentR--;
		}

		ans[q[i].i] = unq;
	}

	for (int i = 0; i < m; i++) cout << ans[i] << "\n";
	return 0;
}