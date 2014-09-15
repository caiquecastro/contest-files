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

typedef long long Int;
typedef unsigned uint;

int T, N, K;

int main(void) {
	scanf("%d", &T);
	for ( ; T--; ) {
		scanf("%d%d", &N, &K);
		Int ans = 0LL;

		for (int i = 0; i < K; i++) {
			int P, Q;
			Int curr = 1LL;
			scanf("%d", &P);
			for (int j = 0; j < P; j++) {
				scanf("%d", &Q);
				curr = (curr * (Int) Q) % N;
			}
			ans = (ans + curr) % N;
		}

		printf("%lld\n", ans % (Int) N);
	}
    return 0;
}
