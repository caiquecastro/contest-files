#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

const int MAXN = 400;
const int INF = 1010000;

int T;
int N, M;
string S[MAXN];

struct edge {
    int to,rev;
    Int cap;
    edge(int to, Int cap, int rev): to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAXN];
Int level[MAXN];
int iter[MAXN];

void init(int N) {
    for (int i = 0; i < N; i++) {
        G[i].clear();
    }
}

void add_edge(int from,int to,Int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            edge& e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

Int dfs(int v, int t, Int f) {
    if(v == t) return f;
    for(int& i = iter[v]; i < (int) G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            Int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    Int flow = 0;
    for( ; ; ) {
        bfs(s);
        if (level[t] < 0) {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f=dfs(s,t,INF)) > 0) {
            flow += f;
        }
    }
}



int main(void) {
	cin >> T;

	for (int test = 1; test <= T; test++) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}


		int s = 0;
		int t = N + M + 2;

		init(t + 1);

		for (int i = 0; i < N; i++) {
			add_edge(s, i + 1, 1);
			for (int j = 0; j < M; j++) {
				if (S[i][j] == '1') {
					add_edge(i + 1, N + j + 1, 1);
				}
			}
		}
		for (int j = 0; j < M; j++) {
			add_edge(N + j + 1, t, 1);
		}

		int f = max_flow(s, t);

		cout << "Case #" << test << ": " << f << "\n";
	}
	return 0;
}
