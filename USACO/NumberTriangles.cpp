/*
ID: jeferso1
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

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
int P[1010][1010];
int dp[1010][1010];

int func(int i, int j) {
	if (j > i) {
		return 101010101;
	} else if (i == N - 1) {
		return P[i][j];
	} else {
		int& ans = dp[i][j];

		if (ans == -1) {
			ans = P[i][j] + max(func(i + 1, j), func(i + 1, j + 1));
		}

		return ans;
	}
}

int main(void) {
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> P[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	int ans = func(0, 0);

	cout << ans << endl;

    return 0;
}

