#include <bits/stdc++.h>

using namespace std;

const int MAXN = 102;
const int INF = 10101010;

string T, S[MAXN];
int N, A[MAXN], cnt[MAXN];

typedef int Flow;
typedef int Cost;

struct Edge {
	int src, dst;
	Cost cst;
	Flow cap;
	int rev;
};

bool operator<(const Edge a, const Edge b) {
	return a.cst > b.cst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph&G, int u, int v, Flow c, Cost l) {
	G[u].push_back((Edge){ u, v, l, c, int(G[v].size()) });
	G[v].push_back((Edge){ v, u, -l, 0, int(G[u].size()-1) });
}

pair<Flow, Cost> flow(Graph&G, int s, int t, int K) {
	int n = G.size();
	Flow flow = 0;
	Cost cost = 0;
	for ( ; ; ) {
		priority_queue<Edge> Q;
		vector<int> prev(n, -1), prev_num(n, -1);
		vector<Cost> length(n, INF);
		Q.push((Edge){-1,s,0,0,0});
		prev[s]=s;
		for (;!Q.empty();) {
			Edge e=Q.top();
			Q.pop();
			int v = e.dst;
			for (int i=0; i<(int)G[v].size(); i++) {
				if (G[v][i].cap>0 && length[G[v][i].dst]>e.cst+G[v][i].cst) {
					prev[G[v][i].dst]=v;
					Q.push((Edge){v, G[v][i].dst, e.cst+G[v][i].cst,0,0});
					prev_num[G[v][i].dst]=i;
					length[G[v][i].dst]=e.cst+G[v][i].cst;
				}
			}
		}
		if (prev[t]<0) return make_pair(flow, cost);
        
		Flow mi=INF;
		Cost cst=0;
		for (int v=t; v!=s; v=prev[v]) {
			mi=min(mi, G[prev[v]][prev_num[v]].cap);
			cst+=G[prev[v]][prev_num[v]].cst;
		}

		K -= cst*mi;
		cost+=cst*mi;

		for (int v=t; v!=s; v=prev[v]) {
			Edge &e=G[prev[v]][prev_num[v]];
			e.cap-=mi;
			G[e.dst][e.rev].cap+=mi;
		}
		flow += mi;
	}    
}

int main(void) {
	cin >> T >> N;

	for (int i = 0; i < (int) T.size(); i++) {
		cnt[T[i] - 'a' + 1] += 1;
	}

	int s = 0, t = N + 26 + 5;

	Graph G(t + 10);
  
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> A[i];
		
		add_edge(G, s, i + 1, A[i], 0);
		
		for (int j = 0; j < (int) S[i].size(); j++) {
			add_edge(G, i + 1, N + (S[i][j] - 'a') + 1, 1, i + 1);
		}
	}

	for (int i = 1; i <= 26; i++) {
		add_edge(G, N + i, t, cnt[i], 0);
	}
  
	pair<int, int> f = flow(G, s, t, INF);

	if (f.first == (int) T.size()) {
		cout << f.second << "\n";
	} else {
		cout << "-1\n";
	}
  
	return 0;
}
