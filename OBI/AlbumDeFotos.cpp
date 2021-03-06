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

using namespace std;

typedef long long ll;
typedef long double ld;

int N, M, N1, M1, N2, M2;

int main(void) {
    scanf("%d%d", &N, &M);

    scanf("%d%d%d%d", &N1, &M1, &N2, &M2);

    int ok = 0;

    REP(i, 2) {
        swap(N1, M1);
        REP(j, 2) {
            swap(N2, M2);
            if(N1 <= N && N2 <= N && M1 <= M && M2 <= M && (N1 + N2 <= N || M1 + M2 <= M)) ok = 1;
        }
    }

    printf("%c\n", ok ? 'S' : 'N');

    return 0;
}
