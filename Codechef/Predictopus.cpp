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

using namespace std;

typedef long long ll;
typedef unsigned uint;

int in(void) { int x; scanf("%d", &x); return x; }

int T;
double PA, PB;

double outcomeA(int M) {
    return 2.0 * (1.0 - PA) * (double) M;
}

double outcomeB(int M) {
    return 2.0 * (1.0 - PB) * (double) M;
}

int main(void) {
    T = in();

    PA = 0.510;
    PB = 1.0 - PA;

    printf("%lf\n", 1000 + outcomeA(6000) - outcomeB(4000));

    for ( ; T--; ) {
        scanf("%lf", &PA); PB = 1.0 - PA;
    }
    return 0;
}

