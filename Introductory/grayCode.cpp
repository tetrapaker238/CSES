#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

string REVERSE_STRING(string s) {
    string reversedString = "";
    per(i, s.le() - 1, 0) {
        reversedString += s[i];
    }
    return reversedString;
}

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    ll n;
    string inverted = "";
    cin >> n;
    vector<string> bits(n);
    rep(i, 0, n - 1) {
        rep(j, 1, pow(2, i)) {
            bits[i] += "0";
        }

        rep(j, 1, pow(2, i)) {
            bits[i] += "1";
        }

        rep(j, 1, n - (i + 1)) {
            bits[i] += REVERSE_STRING(bits[i]);
        }
    }
    rep(i, 0, pow(2, n) - 1) {
        per(j, n - 1, 0) {
            cout << bits[j][i];
        }
        cout << "\n";
    }
    return 0; 
} 