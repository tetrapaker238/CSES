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
    ll n, tows = 1;
    cin >> n;
    vector<ll> cubes(n);
    for (ll i = 0; i < n; i++) {
        cin >> cubes[i];
    }

    multiset<ll> towers;
    towers.insert(cubes[0]);
    ll cube;
    for (ll i = 1; i < n; i++) {
        cube = cubes[i];
        auto it = towers.upper_bound(cube);
        if (it == towers.end()) {
            tows++;
        } else {
            towers.erase(it);
        }
        towers.insert(cube);
    }

    cout << tows;

    return 0; 
} 