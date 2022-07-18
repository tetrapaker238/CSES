#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

ll factorial(ll n) {
    if (n == 0) {
        return 1;
    }

    ll result = n;
    per(i, n - 1, 1) {
        result*= i;
    }
    return result;
}

void crearString(ll actual, string s, ll n, vector<ll> used, string res) {
    if (actual == n) {
        cout << res << "\n";
    } else {
        vector<ll> letters(27, 0); 
        rep(i, 0, n - 1) {
            if (!(used[i]) && letters[s[i] - 'a'] == 0) {
                used[i] = 1;
                letters[s[i] - 'a'] += 1;
                crearString(actual + 1, s, n, used, res + s[i]);
                used[i] = 0;
            }
        }
    }
}


int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;

    string s;
    cin >> s;
    ll n = s.le();
    vector<ll> letters(27, 0);
    rep(i, 0, n -1) {
        letters[s[i] - 'a'] += 1;
    }
    ll denom = 1;
    string sr = "";
    rep(i, 0, 26) {
        ll letter = letters[i];
        rep(j, 1, letter) {
            sr += (char)(i + 'a');
        }
        if (letter == 0) {
            continue;
        } else {
            denom *= factorial(letter);
        }
    }
    ll perms = factorial(n)/denom;
    cout << perms << "\n";
    crearString(0, sr, n, vector<ll>(n, 0), "");
    return 0; 
} 