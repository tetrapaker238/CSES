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
    ll n, x;
    cin >> x >> n;
    vector<ll> street(n, 0);
    ll trafficLight, longestPath;
    for (ll i = 0; i < n; i++) {
        cin >> trafficLight;
        //process traffic Light
        cout << longestPath << "\n";
    }

    return 0; 
} 