#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

void torresHanoi(ll n, ll inicio, ll intermedio, ll destino) {
    if (n == 1) {
        cout << inicio << " " << destino << "\n";
    } else {
        torresHanoi(n - 1, inicio, destino, intermedio);
        cout << inicio << " " << destino << "\n";
        torresHanoi(n - 1, intermedio, inicio, destino);
    }
}

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    ll n;
    cin >> n;
    cout << (ll)pow(2, n) - 1 << "\n";
    torresHanoi(n, 1, 2, 3);
    return 0; 
} 