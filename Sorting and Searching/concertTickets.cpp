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
    ll n = 0, m = 0, maxPrice = 0, pos = 0;
    vector<ll>::iterator low;
    cin >> n >> m;
    vector<vector<ll>> tickets(n, vector<ll>(2, 0));
    for (ll i = 0; i < n; i++) {
        cin >> tickets[i][0];
    }

    sort(tickets.begin(), tickets.end());

    for (ll i = 0; i < m; i++) {
        cin >> maxPrice;
        low = lower_bound(tickets.begin(), tickets.end(), maxPrice);
        pos = low - tickets.begin();
        if (pos >= 0 && (tickets[pos] <= maxPrice)) {
            cout << tickets[pos] << "\n";
        } else if (pos > 0 && (tickets[pos - 1] <= maxPrice)){
            cout << tickets[pos - 1] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0; 
} 