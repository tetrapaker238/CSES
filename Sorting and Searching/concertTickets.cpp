#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define ull unsigned long long
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++)
#define per(i , j , n) for(ll i = j ; i >= n ; i--)

int main() {
    SPEED;
    cout.precision(8);
    cout << fixed;
    ull n, m, val;
    cin >> n >> m;
    set<vector<ull>> s;
    vector<ull> vtf(2, 0);
    for (ull i = 0; i < n; i++) {
        cin >> val;
        s.insert({val, i});
    }

    for (ull i = 0; i < m; i++) {
        cin >> vtf[0];
        if (s.empty()) {
            cout << -1 << "\n";
            continue;
        }

        auto it = s.upper_bound(vtf);
        if ((it == s.begin())) {
            if ((*it)[0] <= vtf[0]) {
                cout << (*it)[0] << "\n"; 
                s.erase(it);
            } else {
                cout << -1 << "\n";
            }
        } else if (it != s.end()) {
            auto prevIt = prev(it, 1);

            if ((*it)[0] <= vtf[0]) {
                cout << (*it)[0] << "\n"; 
                s.erase(it);
            } else if (((*prevIt)[0] <= vtf[0])) {
                cout << (*prevIt)[0] << "\n"; 
                s.erase(prevIt);
            } else {
                cout << -1 << "\n";
            }
        } else {
            auto prevIt = prev(it, 1);
            if ((*prevIt)[0] <= vtf[0]) {
                cout << (*prevIt)[0] << "\n"; 
                s.erase(prevIt);
            } else {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}