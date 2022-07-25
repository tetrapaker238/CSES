#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long int
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
    vector<ll> sticks(n);
    for(ll i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    ll minCost = 0;

    for(ll i = 0; i < n; i++) {
        minCost += abs(sticks[i] - sticks[n/2]);
    }

    cout << minCost;

    return 0; 
} 