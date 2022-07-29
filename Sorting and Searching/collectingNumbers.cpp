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
    ll n, value, rounds = 1;
    cin >> n;
    vector<ll> numbers(n);
    vector<ll> numPos(n);

    for(ll i = 0; i < n; i++) {
        cin >> value;
        numbers[i] = value - 1;
        numPos[value - 1] = i;
    }

    for(ll i = 0; i < n - 1; i++) {
        if (numPos[i] > numPos[i + 1]) {
            rounds++;
        }
    }

    cout << rounds;

    return 0; 
} 