#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  
#define ull unsigned long long

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    
    ull q, k;
    cin >> q;

    for (ull i = 0; i < q; i++) {
        cin >> k;
        ull j1 = 1, j2 = 10, ln = 1, w = 1;
        for(;  !(k >= j1 && k <= j2) ;) {
            ln++;
            w = w*10;
            j1 = j2;
            j2 += ln * (w * 9);
        }

        ull index = (k - j1)%ln;
        ull numBase = ((k - j1) - index)/ln + w;
        string numBaseStr = to_string(numBase);
        cout << numBaseStr[index] << "\n";
    }

    return 0; 
} 