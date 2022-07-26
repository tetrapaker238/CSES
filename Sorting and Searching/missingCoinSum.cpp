#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define ull unsigned long long
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    ll n;
    cin >> n;

    vector<ll> coins(n);
    for(ll i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    if (coins[0] > 1) {
        cout << 1;
    } else {
        ll lastPS = 1;
        ll minPS = lastPS + 1;
        ll complement;
        for(ll i = 1; i < n; i++) {
            if (coins[i] == minPS) {
                lastPS += coins[i];
                minPS = lastPS + 1;
            } else {
                complement = minPS - coins[i];
                if (complement < 0) {
                    cout << minPS;
                    return 0;
                } else {
                    lastPS += coins[i];
                    minPS = lastPS + 1;
                }
            }
        }
        cout << minPS;
    }
    return 0;
} 