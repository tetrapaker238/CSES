#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define fileio freopen("http://in.in", "r", stdin),freopen("out.out", "w", stdout); 
#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define eb emplace_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll > 
#define sd(x) scanf("%d",&x) 
#define sld(x) scanf("%lld",&x) 
#define INF 1e18 
#define eps 0.00001 
#define le length 
#define debug(n1) cout << n1 << endl 
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--) 
const ll N = 3e5 + 5; 
const ll MAX = 3e5 + 5; 
const ll M = 1e6 + 5; 
const int mod = 1e18 + 7; 
vector<string> tablero;
vector<ll> queens; 
ll validCounter;
ll n;
ll MODULAR_POWER(ll a , ll b , ll MOD) { 
    if(b == 0) return 1LL; 
    ll d = MODULAR_POWER(a , b / 2 , MOD); 
    d *= d; 
    d %= MOD; 
    if(b % 2) d *= a; 
    d %= MOD; 
    return d; 
} 
ll BINARY_SEARCH(ll dp[] , ll n , ll key) { 
    ll s = 1; 
    ll e = n; 
    while(s <= e) { 
        ll mid = (s + e) / 2; 
        if(dp[mid] == key) return mid; 
        else if (dp[mid] > key) e = mid - 1; 
        else s = mid + 1; 
    } 
    return -1; 
} 
string CONVERT_TO_BINARY(ll s) { 
    string res = ""; 
    while(s != 0) { 
        res += (char)('0' + s % 2); 
        s /= 2; 
    } 
    reverse(res.begin() , res.end()); 
    return res; 
} 
bool PALIN(string s) { 
    ll i = 0; 
    ll j = s.le() - 1; 
    while(i <= j) { 
        if(s[i] != s[j]) return false; 
        j-- , i++; 
    } 
    return true; 
} 
ll STOI(string s) { 
    ll num = 0; 
    ll po = 1; 
    per(i , s.le() - 1 , 0) { 
        num += po * (s[i] - '0'); 
        po *= 10; 
    } 
    return num; 
}

void countConfigurations() {
    ll qs = queens.size();
    if (qs == n) { // pointer->size() sugar syntax de (*pointer).size()
        ++validCounter;
    } else { //Todavía tenemos que agregar reinas para la configuración actual
        //insertar la reina en el lugar
        for (ll i = 0; i < n; i++) { //Probar que pasaría si colocamos la reina en la posición (qs, i)
            //i es la columna donde se insertaría la reina
            if (tablero[qs][i] == '*') {
                continue;
            }
            bool valid = 1;
            for (ll j = 0; j < qs; j++) {
                //Checkear si podemos agregar la reina en tal posición
                if ((i == queens[j]) || (abs(j - qs) == abs(queens[j] - i))) { //Caso nos come una reina => no valid sol
                    valid = !valid;
                    break;
                }
            }
            if (valid) {
                queens.pb(i);
                countConfigurations();
                queens.pop_back();
            }
        }
    }

}

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    n = 8;
    validCounter = 0;
    tablero = vector<string> (n);
    for(ll i = 0; i < n; i++) {
        cin >> tablero[i];
    }
    countConfigurations();
    cout << validCounter;
    return 0; 
} 