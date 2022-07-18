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
    
    ll n, x;
    cin >> n >> x;
    vector<vector<ll>> children(n, vector<ll>(2, 0));
    for (ll i = 0; i < n; i++) {
        cin >> children[i][0];
    }

    sort(children.begin(), children.end());

    for (ll i = 0; i < n; i++) {
        
    }

    return 0; 
} 