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
        
    ll n, maxSA, actualSA;
    cin >> n;
    vector<ll> nums(n);
    for(ll i = 0; i < n; i++) {
        cin >> nums[i];
    }

    maxSA = actualSA = nums[0];
    for(ll i = 1; i < n; i++) {
        actualSA = max(actualSA + nums[i], nums[i]);
        maxSA = max(maxSA, actualSA);
    }

    cout << maxSA;

    return 0; 
} 