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

const int MAXN = 110;
const int INF = INT_MAX / 2;

int T, N;

int dp[MAXN];

int A[MAXN], P[MAXN];

int main(void) {
    T = in();

    int i, j;

    for ( ; T--; ) {
	N = in();

	int cnt[N];

	for (i = 0; i < N; i++) {
	    A[i] = in();
	    P[i] = in();

	    dp[i + 1] = INF;
	    cnt[i + 1] = cnt[i] + A[i];

	    for (j = 0; j < i + 1; j++) {
		int curr = dp[j] + (cnt[i + 1] - cnt[j] + 10) * P[i];

		if (curr < dp[i + 1]) {
		    dp[i + 1] = curr;
		}
	    }
	}
	
	printf("%d\n", dp[N]);
    }
    return 0;
}
