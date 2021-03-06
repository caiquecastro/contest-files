#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N;
bool seen[MAXN];

int main(void) {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);

	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int P;
		cin >> P;

		seen[P] = true;
	}

	vector<int> E, L;

	for (int i = 1; i <= 2 * N; i++) {
		if (seen[i]) {
			E.push_back(i);
		} else {
			L.push_back(i);
		}
	}

	int ans = 0;
	int el = N - 1;
	int ll = N - 1;

	while (el >= 0 && ll >= 0)  {
		//cout << el <<"  " << ll <<" \n";
		if (E[el] < L[ll]) {
			ans += 1;
			el -= 1;
			ll -= 1;
		} else {
			el -= 1;
		}
	}

	cout << ans << "\n";
	
	return 0;
}
