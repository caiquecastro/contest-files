#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int>  ar) {
    int N = ar.size();
    int pos = N - 1;
    
    while (pos >= 1 && ar[pos - 1] > ar[pos]) {        
        int tmp = ar[pos];
        ar[pos] = ar[pos - 1];
        for (int i = 0; i < N; i++) {
            cout << ar[i] << " ";
        }
        cout << "\n";
        ar[pos - 1] = tmp;
        pos -= 1;
    }
    for (int i = 0; i < N; i++) {
        cout << ar[i] << " ";
    }
    cout << "\n";
}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

insertionSort(_ar);
   
   return 0;
}
