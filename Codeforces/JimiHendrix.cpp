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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 500005;
const int INF = INT_MAX / 5;

int N, M;
string S;
int subSize[MAXN];
set<int> tree[MAXN];
int treeSize;
int centroidParent[MAXN];
map<int, char> mapChar[MAXN];
char nodeChar[MAXN];
vector<pair<int, int> > pref[MAXN];
vector<pair<int, int> > suff[MAXN];

void dfsCounting(int node, int p) {
    subSize[node] = 1;
    treeSize += 1;
       
    for (auto& next : tree[node]) {
        if (next == p) continue;
        dfsCounting(next, node);

        subSize[node] += subSize[next];
    } 
}

int dfsCentroid(int node, int p) {
    for (auto& next : tree[node]) {
        if (next == p) continue;

        if (2 * subSize[next] >= treeSize) {
            return dfsCentroid(next, node);
        }
    }
    
    return node;
}

void centroid(int node, int last_centroid) {
    treeSize = 0;
    dfsCounting(node, node);

    int curr_centroid = dfsCentroid(node, node);

    if (node == last_centroid) {
        centroidParent[curr_centroid] = curr_centroid;
    } else {
        centroidParent[curr_centroid] = last_centroid;
        cout << last_centroid << " " << curr_centroid <<" \n";
        nodeChar[curr_centroid] = mapChar[last_centroid][curr_centroid];
    }

    for (auto& next : tree[curr_centroid]) {
        tree[next].erase(curr_centroid);
        centroid(next, curr_centroid);
    }

    tree[curr_centroid].clear();
}

void update(int node) {
    int base = node;
    int pr = 0;
    int su = M - 1;
    
    while (1) {
        if (pr < M && S[pr] == nodeChar[node]) pr += 1;
        if (su >-1 && S[su] == nodeChar[node]) su -= 1;
        
        if (node == centroidParent[node]) {
            break;
        }
        node = centroidParent[node];
        
        pref[node].push_back(make_pair(pr, base));
        suff[node].push_back(make_pair(su, base));
        
        //cout << node << " " << pr << " " << su << "\n";
    }
    cout << "\n";
}

int main(void) {
    cin >> N >> M;

    for (int i = 1; i < N; i++) {
        int a, b;
        char c;

        cin >> a >> b >> c;

        tree[a].insert(b);
        tree[b].insert(a);

        mapChar[a][b] = c;
        mapChar[b][a] = c;
    }

    cin >> S;

    centroid(1, 1);

    for (int i = 1; i <= N; i++) {
        update(i);
    }

    int l = -1;
    int r = -1;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < (int) pref[i].size(); j++) {
            for (int k = 0; k < (int) suff[i].size(); k++) {
                if (pref[i][j].second == suff[i][k].second) continue;
                
                if (pref[i][j].first < suff[i][k].first) {
                    l = pref[i][j].second;
                    r = suff[i][k].second;
                    break;
                    //cout << l << " " << r << " " << " => " << pref[i][j].first << " " << suff[i][k].first << "\n";
                }
            }
        }
    }

    cout << l << " " << r << "\n";
    return 0;
}
