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

    set<ll> children;

    for (ll i = 1; i <= n; i++) {
        children.insert(i);
    }

    auto it1 = children.begin();
    auto it2 = next(it1, 1);
    if (it2 == children.end()) {
        it2 = it1;
    }
    while (it1 != it2) {
        auto nextIt = next(it2, 1);
        cout << *it2 << " ";
        children.erase(it2);
        if (nextIt == children.end()) {
            it1 = children.begin();
            it2 = next(it1, 1);
            if (it2 == children.end()) {
                it2 = it1;
            }
        } else {
            it1 = nextIt;
            nextIt = next(it1, 1);
            if (nextIt == children.end()) {
                it2 = children.begin();
            } else {
                it2 = nextIt;
            }
        }
    }

    cout << *it1;

    return 0; 
} 