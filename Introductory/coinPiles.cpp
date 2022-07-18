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
    ll a, b, t;
    cin >> t;
    rep(i, 1, t) {
        cin >> a >> b;
        ll res1 = (2*a - b);
        ll res2 = (2*b - a);
        if ((res1 >= 0 && res2 >= 0) && (res1 % 3 == 0 && res2 % 3 == 0)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0; 
} 