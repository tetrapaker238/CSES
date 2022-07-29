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
    ll n, m, value, temp, pos1, pos2, rounds = 1;
    bool b1, b2, b3, b4;
    cin >> n >> m;
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

    //ya tenemos las rondas iniciales
    //hacemos m iteraciones
    for (ll i = 0; i < m; i++) {
        cin >> pos1 >> pos2;
        pos1 -= 1;
        pos2 -= 1;
        //vemos si hay cambios al hacer el swap por cada lado   
        ll numV1 = numbers[pos1]; // pos1 = 1; numV1 = 1;
        ll numV2 = numbers[pos2]; // pos2 = 2; numV2 = 0;

        if (numV1 > numV2) { // 1 > 0
            temp = numV1; // 1
            numV1 = numV2; //numV1 = 0
            numV2 = temp; //numV2 = 1

            temp = pos1; // 1
            pos1 = pos2; // pos1 = 2
            pos2 = temp; // pos2 = 1
        }

        ll posV1 = numPos[numV1]; // numPos[numV1] = 1
        ll posV2 = numPos[numV2]; // numPos[numV2] = 2
        if (numV1 > 0) { // 0 > 0
            b1 = posV1 > numPos[numV1 - 1]; //si 1, orden correcto: 1 > 
            b2 = posV2 > numPos[numV1 - 1];
            if (b1 && !b2) {
                rounds++;
            } else if (!b1 && b2) {
                rounds--;
            }
        }

        if (numV1 < n - 1) { // 0 < 4
            b3 = posV1 < numPos[numV1 + 1]; // false  2 < 1
            b4 = (posV2 == numPos[numV1 + 1]) ? !b3:  posV2 < numPos[numV1 + 1]; 
            if (b3 && !b4) {
                rounds++;
            } else if (!b3 && b4) {
                rounds--;
            }
        }

        if ((numV1 + 1 != numV2) && numV2 > 1) {
            b1 = posV2 > numPos[numV2 - 1]; //si 1, orden correcto
            b2 = posV1 > numPos[numV2 - 1];
            if (b1 && !b2) {
                rounds++;
            } else if (!b1 && b2) {
                rounds--;
            }
        }

        if (numV2 < n - 1) {
            b3 = posV2 < numPos[numV2 + 1];
            b4 = posV1 < numPos[numV2 + 1];
            if (b3 && !b4) {
                rounds++;
            } else if (!b3 && b4) {
                rounds--;
            }
        }
        cout << rounds << "\n";
        //swap de las posiciones de los números
        numbers[pos1] = numV2;
        numbers[pos2] = numV1;
        numPos[numV1] = pos2;
        numPos[numV2] = pos1;
    }

    return 0; 
} 