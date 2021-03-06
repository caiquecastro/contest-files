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

double N;

int main(void) {
    cout << fixed << setprecision(2);

	for ( ; cin >> N; ) {
		if (N <= 2000.00) {
			cout << "Isento" << "\n";
		} else {
			double ans = 0.0;

			double a = 0.0;
			double b = 0.0;
			double c = 0.0;


			a = min(1000.0, N - 2000.0);
			b = min(1500.0, N - 3000.0);
			c = max(0.0, N - 4500.0);

			a = max(a, 0.0);
			b = max(b, 0.0);
			
			ans += a * 0.08;
			ans += b * 0.18;
			ans += c * 0.28;

			cout << "R$ " << ans << "\n";
		}
	}
	
    return 0;
}
