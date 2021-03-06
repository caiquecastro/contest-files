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

int T, N, M;
Int P[MAXN];
vector<int> B[35];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> P[i];

			for (int j = 0; j <= 32; i++) {
				if (P[i] & (1 << j)) {
					B[j].push_back(i);
				}
			}
		}

		for (int q = 0; q < M; q++) {
			int X;
			cin >> X;
		}
	}
	return 0;
}
