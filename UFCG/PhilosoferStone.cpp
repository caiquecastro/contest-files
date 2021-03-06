#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int i, j, n, m, x, mz[110][110], dp[110][110];

int main(void) {
    scanf("%d", &x);
    for( ; x > 0; x--) {
        scanf("%d%d", &n, &m);
        REP(i, n) REP(j, m) scanf("%d", &mz[i][j]);
        REP(i, n+1) REP(j, m+1) dp[i][j] = 0;
        REP(i, m) dp[0][i] = mz[0][i];

        FOR(i, 1, n) {
            REP(j, m) {
                dp[i][j] = dp[i-1][j]+mz[i][j];
                if(j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+mz[i][j]);
                if(j + 1 <  m) dp[i][j] = max(dp[i][j], dp[i-1][j+1]+mz[i][j]);
            }
        }
        int ans = 0;
        REP(j, m) ans = max(ans, dp[n-1][j]);
        printf("%d\n", ans);
    }
    return 0;
}

