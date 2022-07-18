#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	ll n, counter = 0, newNumber;
	cin >> n;
    for(ll i= 0; i < n - 1; i++) {
    	cin >> newNumber;
    	counter+= newNumber;
    }

    cout << n*(n+1)/2 - counter;

    return 0;
}