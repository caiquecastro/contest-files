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

const int MAXN = 2020;
const Int INF = 1001010100100101000LL;

int N;
Int M[MAXN][MAXN], Q[MAXN][MAXN];

vector<int> G[MAXN];
Int dist[MAXN];

struct UnionFind {
    int N, *id, *sz;

    UnionFind(int _N) {
        id = new int[_N];
        sz = new int[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        N = _N;
    }
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

struct edge {
    int from, to;
	Int cost;
    edge() {}
    edge(int from, int to, Int cost): from(from), to(to), cost(cost) {};

    bool operator<(const edge& e) const {
		return cost < e.cost;
    }
};

void bfs(int s) {
	fill(dist, dist + N, INF);
	queue<int> q;
	q.push(s);
	
	dist[s] = 0LL;

	Int ans = 0LL;
	int v = -1;

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();

		Q[s][now] = dist[now];

		if (dist[now] > ans) {
			ans = dist[now];
			v = now;
		}

		for (int i = 0; i < G[now].size(); i++) {
			int next = G[now][i];

			if (dist[next] > M[now][next] + dist[now]) {
				dist[next] = M[now][next] + dist[now];
				q.push(next);				
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;

	vector<edge> edges;

	UnionFind u(N);

	bool ok = true;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> M[i][j];

			if (i == j && M[i][j] != 0) {
				ok = false;
			} else if (i > j && M[i][j] != M[j][i]) {
				ok = false;
			}
			if (i != j) {
				if (M[i][j] != 0) {
					edges.push_back(edge(i, j, M[i][j]));
				} else {
					ok = false;
				}
			}
		}
	}

	if (N == 1) {
		if (M[0][0] == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	} else {
		if (edges.size() == 0) {
			cout << "NO\n";
		} else {
			sort(edges.begin(), edges.end());

			int as = 0;
			
			for (int i = 0; as != N - 1 && i < (int) edges.size(); i++) {
				if(!u.find(edges[i].from, edges[i].to)) {
					u.unite(edges[i].from, edges[i].to);
					G[edges[i].from].push_back(edges[i].to);
					G[edges[i].to].push_back(edges[i].from);
					as += 1;
				}
			}
			
			
			for (int i = 0; i < N; i++) {
				bfs(i);
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (M[i][j] != Q[i][j]) {
						ok = false;
					}
				}
			}
			if (ok) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

    return 0;
}
