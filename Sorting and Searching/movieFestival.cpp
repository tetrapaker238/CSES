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

    ll n, counter = 1, previousEnding;
    cin >> n;
    
    //buscamos la película que empiece antes. Si se repiten
    //escogemos la que empiece antes porque sí

    vector<vector<ll>> invertedMovies(n, vector<ll>(2));

    for(ll i = 0; i < n; i++) {
        cin >> invertedMovies[i][1];
        cin >> invertedMovies[i][0];
    }

    sort(invertedMovies.begin(), invertedMovies.end());
    previousEnding = invertedMovies[0][0];
    for(ll i = 1; i < n; i++) {
        if (previousEnding <= invertedMovies[i][1]) {
            previousEnding = invertedMovies[i][0];
            counter++;
        }
    }

    cout << counter;

    return 0; 
} 