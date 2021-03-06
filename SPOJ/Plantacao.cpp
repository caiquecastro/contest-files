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

int N, K;

int main(void) {
	scanf("%d%d", &N, &K);

	Int sum = 0LL;
	map<int, int> P;

	for (int i = 0; i < K; i++) {
		int c;
		scanf("%d", &c);
		sum += (Int) c;
		P[c] += 1;
	}

	int hs = 0, alive = K;
	Int ans = 0LL;

	for (int i = 0; i < N && alive > 0; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'C') {
			hs += 1;
			sum = sum + alive;
		} else {
			hs -= 1;
			sum -= alive;
			if (hs < 0 && P[-hs] > 0) {				
				alive -= P[-hs];
				P[-hs] = 0;
			}
		}		
		ans += sum;			
	}

	printf("%lld\n", ans);

    return 0;
}
