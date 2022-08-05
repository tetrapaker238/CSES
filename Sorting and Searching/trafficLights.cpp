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
    cin >> x >> n;
    ll trafficLight;
    set<ll> trafficLights;
    trafficLights.insert(0);
    trafficLights.insert(x);
    multiset<ll> pathLengths;
    pathLengths.insert(x);

    for (ll i = 0; i < n - 1; i++) {
        cin >> trafficLight;
        auto it = trafficLights.insert(trafficLight);
        auto prevIt = prev(it.first, 1);
        auto nextIt = next(it.first, 1);
        ll nextVal = *nextIt;
        ll prevVal = *prevIt;
        ll originalLenght = nextVal - prevVal;
        pathLengths.erase(pathLengths.find(originalLenght));
        pathLengths.insert(nextVal - trafficLight);
        pathLengths.insert(trafficLight - prevVal);
        auto lastPath = prev(pathLengths.end(), 1);
        cout << (*lastPath) << " ";
    }

    cin >> trafficLight;
    auto it = trafficLights.insert(trafficLight);
    auto prevIt = prev(it.first, 1);
    auto nextIt = next(it.first, 1);
    ll nextVal = *nextIt;
    ll prevVal = *prevIt;
    ll originalLenght = nextVal - prevVal;
    pathLengths.erase(pathLengths.find(originalLenght));
    pathLengths.insert(nextVal - trafficLight);
    pathLengths.insert(trafficLight - prevVal);
    auto lastPath = prev(pathLengths.end(), 1);
    cout << (*lastPath);

    return 0; 
} 