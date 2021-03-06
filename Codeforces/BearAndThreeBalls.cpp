#include <bits/stdc++.h>

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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 55;
int N;
int P[MAXN];
int C[1010];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        C[P[i]] += 1;
    }

    for (int i = 1; i <= 1000; i++) {
        if (i + 2 <= 1000) {
            if (C[i] > 0 && C[i + 1] > 0 && C[i + 2] > 0) {
                cout << "YES\n";
                return 0;
            }
        }         
    }

    cout << "NO\n";
    
    return 0;
}
