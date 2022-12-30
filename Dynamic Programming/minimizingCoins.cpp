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

    ll n, x;

    cin >> n >> x;

    vector<ll> c(n);

    rep(i, 0, n - 1) {
        cin >> c[i];
    }

    vector<ll> dp(x + 1, 0);

    per(i, n - 1, 0) {
        ll j = c[i];
        ll counter = 1;
        while(j <= x) {
            if (dp[j] == 0) { // Todavía no hay una mejor combinación para esta moneda
                dp[j] = counter;
            } else { // Debemos ver si la combinación actual tiene menos valor que la anterior
                if (dp[j] > counter) {
                    dp[j] = counter;
                }
            }
            counter++;
            j+= c[i];
        }
    }

    //Ahora hay que hacer dp[i] = min(dp[i], dp[i - 1] + dp[1])
    //Pero notar que solo nos interesa dp[x], y por tanto, solo va a interesar cuanto nos falte para ese número y quizás se puede hacer
    //recursivo hacia atrás para obtener los valores que nos interesan (o iterativo) calculando los valores primitivos para luego llegar al pedido
    // bottom up 

    rep(i, 0, x - 1) {
        cout << dp[i] << "\n";
    }

    return 0; 
} 