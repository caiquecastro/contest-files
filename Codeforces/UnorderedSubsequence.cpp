#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

typedef long long ll;

int main(void) {
    int n;
    ll v[100100];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    if(n <= 2) goto end;

    for(int i = 1; i < n - 1; i++) {
        if((v[i + 1] - v[i]) * (ll) (v[i] - v[0]) < 0L) {
            printf("3\n%d %d %d\n", 1, i + 1, i + 2); goto end2;
        }
    }
    end:;printf("0"); end2:;
    return 0;
}
