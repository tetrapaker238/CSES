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
    ll t, x, y;

    cin >> t;
    rep(i, 0, t - 1) {
        cin >> x >> y;
        ll greaterNumber = max(x, y);
        ll maxNumber = greaterNumber*greaterNumber;
        ll finalNumber;
        if (greaterNumber % 2 == 0) {
            finalNumber = maxNumber - (y - 1) - (greaterNumber - x);
        } else {
            finalNumber = maxNumber - (x - 1) - (greaterNumber - y);
        }
        cout << finalNumber << "\n";
    }

    return 0; 
} 