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

typedef long long Int;
typedef unsigned uint;

const int INF = INT_MAX / 3;

int X[5], Y[5];
char D[5];
int msk[5];

int can(int x1, int y1, int x2, int y2) {
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	
	return min(dx, dy) + ceil(abs(dx - dy) / 2.0);
}

int func(void) {
  int ans = 0;
  
  int px = X[0], py = Y[0];
  int buff = 0;
  
  for (int i = 0; i < 3; i++) {
	  int pos = msk[i];

	  int l = 0, h = INF, m;
	  int best = 10000;
	  
	  for ( ; l <= h; ) {
		  m = (l + h) / 2;
      
		  int nx = X[pos], ny = Y[pos];
		  
		  if (D[pos] == 'D') {
			  nx += m + buff;
		  } else {
			  ny += m + buff;
		  }      
		  
		  if (can(px, py, nx, ny) <= m)  {
			  best = min(best, m);
			  h = m - 1;
		  } else {
			  l = m + 1;
		  }
	  }       
	  int nx = X[pos], ny = Y[pos];
	  if (D[pos] == 'D') {
		  nx += best + buff;
	  } else {
		  ny += best + buff;
	  }      
	  
	  ans += best;
	  buff += best;
	  px = nx;
	  py = ny;
  }
  return ans;
}

int main(void) {
	for ( ; scanf("%d%d", &X[0], &Y[0]); ) {
		if (X[0] == 0 && Y[0] == 0) {
			break;
		}
		for (int i = 1; i <= 3; i++) {
			scanf("%d%d %c", &X[i], &Y[i], &D[i]);
			msk[i - 1] = i;
		}
		int ans = INF;
		do {
			ans = min(ans, func());
		} while (next_permutation(msk, msk + 3));
		printf("%d\n", ans);
	}
	return 0;
}
