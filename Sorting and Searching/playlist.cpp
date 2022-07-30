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

    ll n, p1 = 0, p2 = 0, maxCounter = 0;
    cin >> n;
    vector<ll> numbers(n);
    set<ll> numbersSet;
    for (ll i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    if (n == 1) {
        maxCounter++;
    } else {
        while(p1 < n && p2 < n) {
            auto it = numbersSet.find(numbers[p2]);
            if (it == numbersSet.end()) {
                numbersSet.insert(numbers[p2]);
                maxCounter = max(p2 - p1 + 1, maxCounter);
                p2++;
            } else {
                numbersSet.erase(it);
                while(numbers[p1] != numbers[p2]) { 
                    numbersSet.erase(numbers[p1]);
                    p1++;
                }
                p1++;
            }
        }
    }

    cout << maxCounter;
    return 0;
}