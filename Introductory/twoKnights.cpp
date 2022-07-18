#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

ll calculateKnights(ll k) {
    ll n = k*k;
    ll combCaballos = n*(n - 1)/2;
    ll ataquesEntreSi =4*(k - 1)*(k - 2);
    ll sol = combCaballos - ataquesEntreSi;
    return sol;
}

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cout << calculateKnights(i) << "\n";
    }
    return 0; 
} 