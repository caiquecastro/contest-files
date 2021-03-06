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

double pc[5];

int main(void) {
	for (int i = 0; i < 5; i++) {
		scanf("%lf", &pc[i]);
	}
	sort(pc, pc + 5);
	double d = 0.0;
	for (int i = 1; i < 4; i++) {
		d += pc[i];
	}
	printf("%.1lf\n", d);
    return 0;
}
