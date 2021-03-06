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

const int MAXN = 1010;

int T;
int N, P[MAXN], A[MAXN];

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        sort(P, P + N);

        int pl = 0;
        int pr = N - 1;
        
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                A[pl++] = P[i];
            } else {
                A[pr--] = P[i];
            }
        }
        int ans = abs(A[0] - A[N - 1]);

        for (int i = 1; i < N; i++) {
            chmax(ans, abs(A[i] - A[i - 1]));
        }

        cout << ans << "\n";
    }
    return 0;
}
