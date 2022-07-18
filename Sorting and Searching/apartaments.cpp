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
    ll n, m, k, ai=0, bi=0;
    cin >> n >> m >> k;
    vector<ll> appliers(n);
    vector<ll> apartments(m);

    for(ll i = 0; i < n; i++) {
        cin >> appliers[i];
    }

    for(ll i = 0; i < m; i++) {
        cin >> apartments[i];
    }

    sort(appliers.begin(), appliers.end());
    sort(apartments.begin(), apartments.end());

    ll appliedCounter = 0;
    while(ai < n && bi < m) {
        if (appliers[ai] - k > apartments[bi]) {
            bi++;
        } else if ((appliers[ai] - k <= apartments[bi]) && (appliers[ai] + k >= apartments[bi])) {
            ai++;
            bi++;
            appliedCounter++;
        } else {
            ai++;
        }
    }
    cout << appliedCounter;
    return 0; 
} 