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

const int MAXN = 10009;

int N;
int V[MAXN];

int main(void) {
    int i;

    for ( ; scanf("%d", &N) && N != 0; ) {
        int has_positive = 0;

        for (i = 0; i < N; i++) {
            V[i] = in();
            if (V[i] > 0) has_positive = 1;
        }

        if (!has_positive) {
            puts("Losing streak.");
        } else {
            int max_sum = 0, max_yet = 0;

            for (i = 0; i < N; i++) {
                max_yet += V[i];

                if (max_yet > max_sum) {
                    max_sum = max_yet;
                } else if (max_yet < 0) {
                    max_yet = 0;
                }
            }

            printf("The maximum winning streak is %d.\n", max_sum);
        }
    }
    return 0;
}
