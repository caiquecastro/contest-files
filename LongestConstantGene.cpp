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
typedef unsigned long long uInt;

const uInt MOD = 1000000009;
const int MAXN = 10007;

int T;
int N, N_N;

char str[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    T = in();

    int i, j, k;

    for ( ; T--; ) {
        N = in();

        map<uInt, int> mp;
        int ans_cnt = 0, ans_len;

        for (i = 0; i < N; i++) {
            scanf("%s", str); N_N = strlen(str);

            for (j = 0; j < N_N; j++) {
                uInt hash = 0LL;
                for (k = j; k < N_N; k++) {
                    hash = ((hash * 31) ^ (str[k] - 'A')) % MOD;
                    mp[hash] += 1;

                    if (mp[hash] > ans_cnt) {
                        ans_cnt = mp[hash], ans_len = k - j + 1;
                    }
                }
            }
        }

        printf("%d\n", ans_len);

    }
    return 0;
}
