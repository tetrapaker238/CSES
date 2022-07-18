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
    ll sumaTotal = n * (n + 1) / 2;
    if (sumaTotal % 2 == 0) {
        cout << "YES" << "\n";
        ll sumaConjuntos = sumaTotal/2;
        ll numsConsecutivos = ceil(n/2.); 
        ll numInicio = (sumaConjuntos + (1 - numsConsecutivos) * numsConsecutivos / 2) / numsConsecutivos;
        cout << numsConsecutivos << "\n";
        cout << numInicio;
        for (ll i = numInicio + 1; i < numInicio + numsConsecutivos; i++) {
            cout << " " << i; 
        }
        cout << "\n";
        ll numsRestantes = n - numsConsecutivos;
        cout << numsRestantes << "\n";
        for (ll i = 1; i < numInicio; i++) {
            cout << i << " ";
        }
        cout << numInicio + numsConsecutivos;
        for (ll i = numInicio + numsConsecutivos + 1; i <= n; i++) {
            cout << " " << i;
        }
    } else {
        cout << "NO" << "\n";
    }
    return 0; 
} 