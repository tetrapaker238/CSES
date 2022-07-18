#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  
ll minDiference;
vector<ll> applesSet;
 
void findMinSum(ll actualSum, ll totalSum, ll n, vector<ll> *applesP , ll k) {
    if (k == n) {
        ll newSetC = totalSum - actualSum;
        ll newDiff = abs(newSetC - actualSum);
        if (newDiff < minDiference) {
            minDiference = newDiff;
        }
    } else {
        ll apple = (*applesP)[k];
        findMinSum(actualSum, totalSum, n, applesP, k + 1);
        applesSet.push_back(apple);
        findMinSum(actualSum + apple, totalSum, n, applesP, k + 1);
        applesSet.pop_back();
    }
}
 
int main() {
    SPEED;
    cout.precision(8); 
    cout << fixed;
 
    ll n, appleCounter = 0;
    cin >> n;
    vector<ll> apples(n), applesSet = vector<ll>(n);
    rep(i, 0, n - 1) { //Guardamos las manzanas en un vector
        cin >> apples[i];
        appleCounter += apples[i];
    }
 
    minDiference = appleCounter;
    //Vamos a crear todas las combinaciones pero cortar las que empiezan a generar una diferencia mayor
    //backtracking
    findMinSum(0, appleCounter, n, &apples, 0);
    cout << minDiference << "\n";
 
    return 0; 
} 