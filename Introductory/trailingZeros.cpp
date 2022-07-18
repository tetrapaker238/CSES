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
    ll n;
    cin >> n;
    
    ll zeroCounter = 0;
    ll i = 5;
    while (n/i >= 1) {
        zeroCounter += n/i;
        i *= 5;
    }

    cout << zeroCounter;
    return 0; 
} 