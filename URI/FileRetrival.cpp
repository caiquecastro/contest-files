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

const int MAXN = 1000005;
const int INF = INT_MAX / 5;

string S[100];
int belong[MAXN];
int N, L;

// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm

//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
// That's it!

//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// rnk = The inverse of the suffix array. rnk[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> rnk[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if rnk[i] < rnk[j]

int str[MAXN]; //input
int rnk[MAXN], pos[MAXN]; //output
int cnt[MAXN], nxt[MAXN]; //internal
bool bh[MAXN], b2h[MAXN];

bool smaller_first_char(int a, int b){
    return str[a] < str[b];
}

void SuffixSort(int n){
    //sort suffixes according to their first character
    for (int i=0; i<n; ++i){
        pos[i] = i;
    }
    sort(pos, pos + n, smaller_first_char);
    //{pos contains the list of suffixes sorted by their first character}

    for (int i=0; i<n; ++i){
        bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
        b2h[i] = false;
    }

    for (int h = 1; h < n; h <<= 1){
        //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
        int buckets = 0;
        for (int i=0, j; i < n; i = j){
            j = i + 1;
            while (j < n && !bh[j]) j++;
            nxt[i] = j;
            buckets++;
        }
        if (buckets == n) break; // We are done! Lucky bastards!
        //{suffixes are separted in buckets containing strings starting with the same h characters}

        for (int i = 0; i < n; i = nxt[i]){
            cnt[i] = 0;
            for (int j = i; j < nxt[i]; ++j){
                rnk[pos[j]] = i;
            }
        }

        cnt[rnk[n - h]]++;
        b2h[rnk[n - h]] = true;
        for (int i = 0; i < n; i = nxt[i]){
            for (int j = i; j < nxt[i]; ++j){
                int s = pos[j] - h;
                if (s >= 0){
                    int head = rnk[s];
                    rnk[s] = head + cnt[head]++;
                    b2h[rnk[s]] = true;
                }
            }
            for (int j = i; j < nxt[i]; ++j){
                int s = pos[j] - h;
                if (s >= 0 && b2h[rnk[s]]){
                    for (int k = rnk[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                }
            }
        }
        for (int i=0; i<n; ++i){
            pos[rnk[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i=0; i<n; ++i){
        rnk[pos[i]] = i;
    }
}
// End of suffix array algorithm


// Begin of the O(n) longest common prefix algorithm
int lcp[MAXN];
// lcp[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// lcp[0] = 0
void getLcp(int n){
    for (int i=0; i<n; ++i) rnk[pos[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<n; ++i){
        if (rnk[i] > 0){
            int j = pos[rnk[i]-1];
            while (i + h < n && j + h < n && str[i+h] == str[j+h] && str[i + h] != '$' && str[j + h] != '$') h++;
            lcp[rnk[i]] = h;
            if (h > 0) h--;
        }
    }
}
// End of the longest common prefix algorithm

int tree[MAXN][30];
Int maskTree[MAXN][30];

void build() {
    int pw = 1;
    int base = 2;
 
    for (int i = 0; i < L; i++) {
        tree[i][0] = lcp[i];
        maskTree[i][0] = (1LL << (Int) belong[pos[i]]);
    }
  
    while (base <= L) {
        for (int i = 0; i + base / 2 - 1 < L; i++) {
            int before = base / 2;		
            tree[i][pw] = min(tree[i][pw - 1], tree[i + before][pw - 1]);
            maskTree[i][pw] = maskTree[i][pw - 1] | maskTree[i + before][pw - 1];
        }    
        pw += 1;
        base *= 2;
    }
}

int query(int l, int r) {
    int len = r - l + 1;
 
    if (len == 1) return tree[l][0];
  
    int ps = 1;
    int pw = 0;
	
    while (l + 2 * ps <= r) {
        ps *= 2;
        pw += 1;
    }
 
    int a = tree[l][pw];
    int b = tree[r - ps + 1][pw];
 
    return min(a, b);
}

Int queryMask(int l, int r) {
    int len = r - l + 1;
    
    if (len == 1) return maskTree[l][0];
    
    int ps = 1;
    int pw = 0;
	
    while (l + 2 * ps <= r) {
        ps *= 2;
        pw += 1;
    }
 
    Int a = maskTree[l][pw];
    Int b = maskTree[r - ps + 1][pw];
 
    return a | b;
}

int funcL(int l, int r, int rbound, int val) {
    int ans = rbound;
    
    while (l <= r) {
        int m = l + (r - l) / 2;

        int curr = query(m, rbound);

        if (curr < val) {
            l = m + 1;
        } else {
            ans = m;
            r = m - 1;
        }
    }
    return ans;
}

int funcR(int l, int r, int lbound, int val) {
    int ans = lbound;
    
    while (l <= r) {
        int m = l + (r - l) / 2;

        int curr = query(lbound, m);

        if (curr < val) {
            r = m - 1;
        } else {
            ans = m;
            l = m + 1;
        }
    }
    return ans;
}

int main(void) {
    while (cin >> N && N != 0) {
        string all = "";
        map<string, int> unique;
        
        for (int i = 0; i < N; i++) {
            cin >> S[i];

            unique[S[i]] += 1;

            all += S[i];

            if (i != N - 1) {
                all += "$";
            }
        }        

        L = (int) all.size();
        int ps = 0;
        
        for (int i = 0; i < L; i++) {
            str[i] = all[i];

            if (all[i] == '$') {
                ps += 1;
                continue;
            }

            belong[i] = ps;     
        }

        SuffixSort(L);
        getLcp(L);

        build();        

        set<Int> seen;
        
        for (int i = N - 1; i < L; i++) {
            if (lcp[i] == (int) S[belong[pos[i - 1]]].size()) {
                unique[S[belong[pos[i - 1]]]] = 1000000;
            }
            if (lcp[i] == (int) S[belong[pos[i]]].size()) {
                unique[S[belong[pos[i]]]] = 1000000;
            }            
        }
        /*
          vector<pair<int, int> > vs;
        
          for (int i = 0; i < L; i++) {
          vs.push_back(make_pair(rnk[i], i));              
          }
        
          sort(vs.begin(), vs.end());
          
          for (int i = N - 1; i < L; i++) {
              cout << (1LL << belong[pos[i]]) << " " << queryMask(i, i) <<"\n";
              //cout << i << "    " << lcp[i] << " " << all.substr(vs[i].second, all.size() - vs[i].second) << "\n";
              //cout << lcp[i] << "\n";
          }
          cout << "\n";
          
        */

        
        for (int i = N - 1; i < L; i++) {
            //cout << belong[pos[i]] << " " << (1LL << belong[pos[i]]) << " " << queryMask(1, 0, L - 1, i, i) << "\n";
            if (lcp[i] > 0) {
                int lbound = funcL(N - 1, i, i, lcp[i]) - 1;
                int rbound = funcR(i, L - 1, i, lcp[i]);
                
                //cout << lbound << " " << i << " " << rbound << " => " << queryMask(lbound, rbound) << "\n";
                seen.insert(queryMask(lbound, rbound));
            }              
        }
        
        for (int i = 0; i < N; i++) {
            if (unique[S[i]] == 1) {
                seen.insert(1LL << (Int) i);
            }
        }
        cout << seen.size() << "\n";
    }
    return 0;
}
