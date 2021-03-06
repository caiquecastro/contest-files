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

const int MAXN = 10007;
const int INF = 10010010;

int T, L, N, D;
int X[MAXN], H[MAXN];
int dp[MAXN];


int main(void) {
    T = in();

    int i, j;

    for ( ; T--; ) {
        L = in(), N = in(); D = in();

        for (i = 0; i < MAXN; i++) dp[i] = INF;

        int ans = 0;

        for (i = 1; i <= N; i++) {
            X[i] = in(), H[i] = in();
            dp[i] = H[i];

            for (j = 1; j < i && X[i] - X[j] > D; j++) {
                chmax(dp[i], dp[j] + H[i]);

                chmax(ans, dp[i]);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
