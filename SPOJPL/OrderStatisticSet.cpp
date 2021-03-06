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

struct Node {
	Node* L;
	Node* R;
	
	int value;
	int priority;
	int size;

	Node(int v) {
		value = v;
		size = 1;
		priority = rand() % MAXN;
	}
	
	void update_size() {
		size = 1;
		
		if (L) {
			size += L->size;
		}
		if (R) {
			size += R->size;
		}
	}
};

void printP(Node* root) {
	if (root == NULL) {
		return;
	} else {
		printP(root->L);
		cout << root->value << " ";
		printP(root->R);
	}
}
void printI(Node* root) {
	if (root == NULL) {
		return;
	} else {
		cout << root->value << " ";
		printI(root->L);
		printI(root->R);
	}
}


void split(Node* root, Node*& l, Node*& r, int val) {
	if (!root) {
		l = NULL;
		r = NULL;
	} else {
		if (root->value <= val) {
			split(root->R, root->R, r, val);
			l = root;
		} else {
			split(root->L, l, root->L, val);
			r = root;
		}
	}
	if (root) {
		root->update_size();
	}
}

void merge(Node*& root, Node*& l, Node*& r) {	
	if (l == NULL || r == NULL) {
		if (l != NULL) {
			root = l;
		} else {
			root = r;
		}
	} else {
		if (l->priority > r->priority) {
			merge(l->R, l->R, r);
			root = l;
		} else {
			merge(r->L, l, r->L);
			root = r;
		}
	}
	if (root) {
		root->update_size();
	}
}

void insert(Node*& root, Node*& inserted) {
	if (root == NULL) {
		root = inserted;
	} else {
		if (root->priority < inserted->priority) {			
			split(root, inserted->L, inserted->R, inserted->value);
			root = inserted;
		} else {
			if (root->value <= inserted->value) {
				insert(root->R, inserted);
			} else {
				insert(root->L, inserted);
			}
		}
	}
	if (root) {
		root->update_size();
	}
}

void remove(Node*& root, int value) {
	if (root == NULL) {
		return;
	} else {
		if (root->value == value) {
			merge(root, root->L, root->R);
		} else {
			if (root->value < value) {
				remove(root->R, value);
			} else {
				remove(root->L, value);
			}
		}
	}
	if (root) {
		root->update_size();
	}
}

bool find(Node* root, int value) {
	if (root == NULL) {
		return false;
	} else if (root->value == value) {
		return true;
	} else {
		if (root->value <= value) {
			return find(root->R, value);
		} else {
			return find(root->L, value);
		}
	}
}

Node* kth(Node* root, int pos) {
	if (!root) {
		return NULL;
	} else {		
		int curr_pos = 1;
		
		if (root->L) {
			curr_pos += root->L->size;
		}

		if (curr_pos == pos) {
			return root;
		} else if (root->L && curr_pos > pos) {
			return kth(root->L, pos);
		} else if (root->R) {
			return kth(root->R, pos - 1 - (root->L ? root->L->size : 0));
		} else {
			return NULL;
		}
	}
}

int query(Node* root, int value) {
	if (root == NULL) {
		return 0;
	} else {
		if (root->value < value) {
			int ans = 1;
			
			if (root->L != NULL) {
				ans += root->L->size;
			} 
			
			return ans + query(root->R, value);
		} else {
			return query(root->L, value);
		}
	}
}

int main(void) {
	srand(time(NULL));

	int  Q, V;
	char K;
	
	Node* root = NULL;
	
	scanf("%d", &Q);
	
	while (Q--) {
		scanf(" %c%d", &K, &V);
		/*	
		  cout << "In ";
		printI(root);
		cout << endl;
		cout << "Po ";
		printP(root);
		cout << endl;
		cout << endl;
		*/
		if (K == 'I') {
			if (!find(root, V)) {
				Node* novo = new Node(V);
				
				insert(root, novo);
			}
		} else if (K == 'D') {
			if (find(root, V)) {
				remove(root, V);
			}
		} else if (K == 'K') {
			Node* q = kth(root, V);
			
			if (q == NULL) {
				printf("invalid\n");
			} else {
				printf("%d\n", q->value);
			}
		} else {
			int ans = query(root, V);
			
			printf("%d\n", ans);
		}
	}
	return 0;
}
