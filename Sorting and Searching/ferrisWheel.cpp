#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ull unsigned long long
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    
    ull n, x, counter = 0;
    cin >> n >> x;
    vector<ull> children(n);
    for (ll i = 0; i < n; i++) {
        cin >> children[i];
    }

    sort(children.begin(), children.end());

    ull l = 0, r = n - 1;

    for(;l<r;) {
        counter++;
        if (children[l] + children[r] > x) { //Caso descartamos el r
            r--;
        } else { //messirve, tomamos ambos extremos
            l++;
            r--;
        }
    }

    if (l == r) {
        counter++;
    }

    cout << counter;

    return 0; 
} 