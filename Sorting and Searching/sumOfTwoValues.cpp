#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define ull unsigned long long
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

bool comp (vector<ll> a, vector<ll> b) {
    return a[0] < b[0];
}

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    
    ll n, x;
    cin >> n >> x;
    vector<vector<ll>> vec(n, vector<ll>(2, 0));
    vector<ll> complement(2, 0);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i][0];
        vec[i][1] = i;
    }

    sort(vec.begin(), vec.end());

    for (ll i = 0; i < n; i++) {
        if (vec[i][0] >= x) {
            cout << "IMPOSSIBLE";
            return 0;
        } else {
            complement[0] = x - vec[i][0];
            auto it = equal_range(vec.begin(), vec.end(), complement, comp);
            ll nValues = it.second - it.first;
            ll pos = it.first - vec.begin();
            ll pos2 = it.second - vec.begin();
            if (nValues == 1) {
                if (vec[pos][1] != vec[i][1]){
                    cout << vec[i][1] + 1 << " " << vec[pos][1] + 1;
                    return 0;
                }
            } else if (nValues > 1) {
                if ((vec[pos][1] != vec[i][1])) {
                    cout << vec[i][1] + 1 << " " << vec[pos][1] + 1;
                    return 0;
                } else if (it.second == vec.end()) {
                    cout << vec[i][1] + 1 << " " << vec[pos2 - 1][1] + 1;
                    return 0;
                } else if (it.second != vec.end()) {
                    cout << vec[i][1] + 1 << " " << vec[pos2 - 1][1] + 1;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0; 
} 