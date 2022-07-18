#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;

    ll n, prev, actual, counter = 0;
    cin >> n;
    cin >> prev;
    rep(i, 0, n - 2) {
        cin >> actual;
        if (prev > actual) {
            ll diferencia = prev - actual;
            counter += diferencia;
            actual = prev;
        }
        prev = actual;
    }
    cout << counter;
    return 0; 
} 