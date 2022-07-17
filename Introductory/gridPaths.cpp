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
string s;
ll n = 7, solutionsCounter = 0, stepsCounter = 0, downCounter = 0, rightCounter = 0, x = 0, y = 0; // x e y son la posición en la que nos encontramos en la matriz
vector<vector<ll>> grid(n, vector<ll>(n, 0)); //Inicializamos la grilla de 7x7
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

void solveGridPaths() {
    if (stepsCounter == 48) { //Hemos encontrado una solución válida
        if (x == 0 && y == 6) {
            solutionsCounter++;
        } else {
            return;
        }
    } else { //Para cada posición, debemos ver las cuatro posibilidades, es decir, arriba, abajo, izquierda y derecha

        if (((y == 0  || y == 6) || (grid[x][y - 1] && grid[x][y + 1])) && x > 0 && x < 6 && !grid[x - 1][y] && !grid[x + 1][y]) { // en el techo o suelo hay una muralla y hay casillas libres a los lados
            return;
        }

        if (((x == 0 || x == 6) || (grid[x - 1][y] && grid[x + 1][y])) && y > 0 && y < 6 && !grid[x][y - 1] && !grid[x][y + 1]) { // en los lados hay una muralla y hay casillas libres a los lados
            return;
        }


        if (x == 0 && y == 6) { //Llegamos de alguna manera a donde deberíamos haber llegado
            return;
        }

        if (y - 1 >= 0 && !grid[x][y - 1] && (s[stepsCounter] == 'U' || s[stepsCounter] == '?')) { //Podemos ir hacia arriba y no habíamos ocupado esa casilla.
            y -=1;
            grid[x][y] = 1;
            stepsCounter++;
            solveGridPaths();
            stepsCounter--;
            grid[x][y] = 0;
            y+=1;
        }

        if (y + 1 <= 6 && !grid[x][y + 1] && (s[stepsCounter] == 'D' || s[stepsCounter] == '?')) { //abajo
            y +=1;
            grid[x][y] = 1;
            stepsCounter++;
            solveGridPaths();
            stepsCounter--;
            grid[x][y] = 0;
            y-=1;
        }

        if (x - 1 >= 0 && !grid[x - 1][y] && (s[stepsCounter] == 'L' || s[stepsCounter] == '?')) { //izquierda
            x-=1;
            grid[x][y] = 1;
            stepsCounter++;
            solveGridPaths();
            stepsCounter--;
            grid[x][y] = 0;
            x+=1;
        }

        if (x + 1 <= 6 && !grid[x + 1][y] && (s[stepsCounter] == 'R' || s[stepsCounter] == '?')) { //derecha
            x+=1;
            grid[x][y] = 1;
            stepsCounter++;
            solveGridPaths();
            stepsCounter--;
            grid[x][y] = 0;
            x-=1;
        }
    }
}

int main() { 
    SPEED; 
    cout.precision(8); 
    cout << fixed;
    cin >> s;
    grid[0][0] = 1;
    solveGridPaths();
    cout << solutionsCounter;
    return 0; 
} 