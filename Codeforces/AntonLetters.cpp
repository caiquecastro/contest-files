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

string S;

int main(void) {
	getline(cin, S);

	set<char> c;

	for (int i = 0; i < (int) S.size(); i++) {
		if (S[i] >= 'a' && S[i] <= 'z') {
			c.insert(S[i]);
		}
	}
	cout << c.size() << "\n";
    return 0;
}
