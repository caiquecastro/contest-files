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

const int MAXN = 1000005;

int N, K;
int P[MAXN];

int main(void) {
	for ( ; cin >> N >> K && !(N == 0 && K == 0); ) {
		for (int i = 0; i < N; i++) {
			P[i] = i + 1;
		}
		reverse(P + K - 1, P + N);
		for (int i = 0; i < N; i++) {
			if (i > 0) cout << " ";
			cout << P[i];
		}
		cout << "\n";
	}
	
    return 0;
}
