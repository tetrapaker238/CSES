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
    string s;
    cin >> s;
    ll n = s.length(), largoAlfabeto = 'Z' - 'A' + 1;
    vector<ll> letters(largoAlfabeto, 0);
    rep(i, 0, n - 1) {
        letters[s[i] - 'A']+= 1;
    }

    if (n % 2 == 0) { 
        rep(i, 0, largoAlfabeto - 1) {
            if (letters[i] % 2 != 0) {
                cout << "NO SOLUTION";
                return 0;
            }
        }
        string palin1 = "";
        rep(i, 0, largoAlfabeto - 1) {
            ll cantidadLetras = letters[i];
            rep(j, 0, cantidadLetras/2 - 1) {
                palin1 += (char)('A' + i);
            }
        }
        cout << palin1;
        reverse(palin1.begin(), palin1.end());
        cout << palin1;
    } else {
        ll letraImpar = -1;
        rep(i, 0, largoAlfabeto - 1) {
            if (letters[i] % 2 != 0) {
                if (letraImpar == -1) {
                    letraImpar = i;
                } else {
                    cout << "NO SOLUTION";
                    return 0;
                }
            }
        }
        string palin1 = "";
        rep(i, 0, largoAlfabeto - 1) {
            ll cantidadLetras = letters[i];
            if (i == letraImpar) {
                cantidadLetras-= 1;
            }
            rep(j, 0, cantidadLetras/2 - 1) {
                palin1 += (char)('A' + i);
            }
        }
        cout << palin1;
        cout << (char)('A' + letraImpar);
        reverse(palin1.begin(), palin1.end());
        cout << palin1;
    }
    return 0; 
} 