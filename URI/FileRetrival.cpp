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

const int MAXN = 100005;

string S[100];
int N;

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

int main(void) {
    while (cin >> N && N != 0) {
        string all = "";
        
        for (int i = 0; i < N; i++) {
            cin >> S[i];

            all += S[i];

            if (i != N - 1) {
                all += "$";
            }
        }        

        map<int, int> belong;
        int L = (int) all.size();
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

        vector<pair<int, int> > vs;
        
        for (int i = 0; i < L; i++) {
            vs.push_back(make_pair(rnk[i], i));              
        }
        
        sort(vs.begin(), vs.end());

        for (int i = N - 1; i < L; i++) {
            cout << lcp[i] << " " << all.substr(vs[i].second, all.size() - vs[i].second) << "\n";
        }

        for (int i = N; i < L; i++) {
            cout << lcp[i] << " ";
        }
        cout << "\n";

        set<Int> seen;
        
        for (int i = N - 1; i < L; i++) {
            vector<Int> masks;
            masks.push_back((1LL << belong[pos[i]]));
            int j = i + 1;
            
            while (j < L && lcp[j] > 0) {
                if (j > i + 1 && lcp[j] > lcp[j - 1]) {
                    masks.push_back((1LL << belong[pos[j]]));
                } else if (lcp[j] < lcp[j - 1]) {
                    if (!masks.empty()) {
                        seen.insert(masks.back());
                        masks.pop_back();
                    }
                }
                if (!masks.empty()) {
                    masks.back() |= (1LL << belong[pos[j]]);
                } else {
                    cout << "ERR " << i - N + 1 << " " << lcp[j] << "\n";
                }
                j += 1;
            }
            for (int k = 0; k < (int) masks.size(); k++) {
                cout << i - N + 1 << " " << masks[k] << "\n";
                seen.insert(masks[k]);
            }
            i = j - 1;
        }

        cout << seen.size() << "\n";
    }
    return 0;
}
