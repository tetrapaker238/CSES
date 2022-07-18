#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

vector<string> tablero;
vector<ll> queens; 
ll validCounter;
ll n;

void countConfigurations() {
    ll qs = queens.size();
    if (qs == n) {
        ++validCounter;
    } else {
        for (ll i = 0; i < n; i++) {
            if (tablero[qs][i] == '*') {
                continue;
            }
            bool valid = 1;
            for (ll j = 0; j < qs; j++) {
                if ((i == queens[j]) || (abs(j - qs) == abs(queens[j] - i))) { //Caso nos come una reina => no valid sol
                    valid = !valid;
                    break;
                }
            }
            if (valid) {
                queens.push_back(i);
                countConfigurations();
                queens.pop_back();
            }
        }
    }
}

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    n = 8;
    validCounter = 0;
    tablero = vector<string> (n);
    for(ll i = 0; i < n; i++) {
        cin >> tablero[i];
    }
    countConfigurations();
    cout << validCounter;
    return 0; 
} 