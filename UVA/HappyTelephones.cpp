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

using namespace std;

typedef long long ll;
typedef long double ld;

int N, M, a, b, ans;

int main(void) {
    //freopen("i.in", "r", stdin);
    while(2 == scanf("%d%d", &N, &M) && !(N+M == 0)) {
        vector<pair<int, int> > pi(N);
        REP(i, N) {
            scanf("%*d%*d%d%d", &pi[i].first, &pi[i].second); pi[i].second = pi[i].first + pi[i].second - 1;
        }
        REP(i, M) {
            ans = 0;
            scanf("%d%d", &a, &b); b = a + b - 1;
            REP(j, N) {
                if((pi[j].first <= a && pi[j].second >= a) || (pi[j].first >= a && pi[j].second <= b) || (pi[j].first <= b && pi[j].second >= b)) {
                    ans += 1;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
