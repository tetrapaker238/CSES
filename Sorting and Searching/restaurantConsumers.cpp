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
    ll n, maxCustomers = 0, counter = 0, ip = 0, op = 0;
    cin >> n;
    vector<ll> in(n);
    vector<ll> out(n);

    for(ll i = 0; i < n; i++) {
        cin >> in[i];
        cin >> out[i];
    }

    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    while (ip < n && op < n) {
        if (in[ip] < out[op]) {
            counter++;
            ip++;
        } else { //in[ip] > out[op]
            if (counter > maxCustomers) {
                maxCustomers = counter;
            }
            op++;
            counter--;
        }
    }

    if (counter > maxCustomers) {
        maxCustomers = counter;
    }

    cout << maxCustomers;

    return 0; 
} 