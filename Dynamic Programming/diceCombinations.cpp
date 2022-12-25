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

    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    
    for(ll i = 7; i <= n; i++) {
        ll actualSum = 0;
        for (ll j = i - 6; j <= i - 1; j++) {
            actualSum = (actualSum % 1000000007 + dp[j] % 1000000007) % 1000000007;
        }
        dp[i] = actualSum;
    }

    cout << dp[n];

    return 0; 
} 