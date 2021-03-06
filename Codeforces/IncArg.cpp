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

int N;
string S, P;

int main(void) {
	cin >> N >> S;

	P = S;

	int ans = 0, tr = 1;

	for (int i = 0; i < N; i++) {
		int p = S[i] - '0';
		
		p += tr;
		if (p <= 1) {
			P[i] = '0' + p;
			if (P[i] != S[i]) ans += 1;
			break;
		} else {
			ans += 1;
			P[i] = '0';
		}
	}

	cout << ans << "\n";

    return 0;
}
