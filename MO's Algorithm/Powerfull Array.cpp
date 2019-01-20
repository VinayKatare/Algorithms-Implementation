//https://codeforces.com/problemset/problem/86/D

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
	int L, R, i;
};
query q[200010];
ll a[200010], cnt[1000010], res[200010], ans;

void add(int idx) {
	ans += (2 * cnt[a[idx]] + 1)*a[idx];
	cnt[a[idx]]++;
}
void remove(int idx) {

	ans -= (2 * cnt[a[idx]] - 1)*a[idx];
	cnt[a[idx]]--;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> a[i];

	for (int i = 0; i < m; i++) {
		cin >> q[i].L >> q[i].R;
		q[i].L--, q[i].R--;
		q[i].i = i;
	}
	int BLOCKS = sqrt(n) + 1;
	sort(q, q + m, [=](query x, query y) {
		if (x.L / BLOCKS != y.L / BLOCKS)return x.L / BLOCKS < y.L / BLOCKS;
		return x.R < y.R;
	});

	int currentL = 1, currentR = 0;
	for (int i = 0; i < m; i++) {

		while (currentL < q[i].L) {
			remove(currentL);
			currentL++;
		}

		while (currentL > q[i].L) {
			currentL--;
			add(currentL);
		}

		while (currentR < q[i].R) {
			currentR++;
			add(currentR);
		}

		while (currentR > q[i].R) {
			remove(currentR);
			currentR--;
		}
		res[q[i].i] = ans;
	}

	for (int i = 0; i < m; i++)cout << res[i] << '\n';
	return 0;
}