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
    ll n;
    cin >> n;

    if (n==2 || n== 3) {
        cout << "NO SOLUTION";
    } else if (n == 4) {
        cout << "2 4 1 3";
    } else {
        ll actualNum = 1;
        rep(i, 1, n - 1) {
            cout << actualNum << " "; 
            actualNum = (actualNum + 2) % n;
            if (actualNum == 0) {
                actualNum = n;
            } else if (actualNum == 1) {
                actualNum = 2;
            }
        }
        cout << actualNum << " "; 
    }

    return 0; 
} 