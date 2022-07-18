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
    string s;
    cin >> s;
    ll n = s.length();
    ll accumulative = 1;
    ll maxAccumulative = 1;
    char lastChar = s[0];
    rep(i, 1, n - 1) {
        if (s[i] == lastChar) {
            accumulative++;
        } else {
            lastChar = s[i];
            if (maxAccumulative < accumulative) {
                maxAccumulative = accumulative;
            }
            accumulative = 1;
        }
    }

    if (accumulative > maxAccumulative) {
        maxAccumulative = accumulative;
    }
    cout << maxAccumulative;
 
    return 0; 
} 