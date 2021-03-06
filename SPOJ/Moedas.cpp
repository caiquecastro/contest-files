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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (1 << 20);
int M, N, coins[110], dp[50010];

int main(void) {
    while(cin >> M && M > 0) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> coins[i];
        }
        for(int i = 0; i <= M; i++) dp[i] = INF;
        dp[0] = 0;
        for(int i = 1; i <= M; i++) {
            for(int j = 0; j < N; j++) {
                if(coins[j] <= i && dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        if(dp[M] == INF) {
            cout << "Impossivel" << endl;
        } else {
            cout << dp[M] << endl;
        }
    }
    return 0;
}

