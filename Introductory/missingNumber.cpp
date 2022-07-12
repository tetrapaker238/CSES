#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll bbin(vector<ll> v, ll n, ll value) {
	ll l = 0, r = n, m = l + (r-l)/2;

	while (r >= l) {
		cout << m;
		if (value == v[m]) {
			return m;
		}

		else if (value > v[m]) {
			l = m + 1;

		} else {

			r = m - 1;
		}

		m = l + (r-l)/2;
	}
	return -1;
}

int main() {
	ll n;
	ll newNumber;
	cin >> n;
    vector<ll> v(n, 0);
    for(ll i= 0; i < n - 1; i++) {
    	cin >> newNumber;
    	v[newNumber - 1] = 1;
    }

    for(ll i = 0; i < n; i++) {
    	if (v[i] == 0) {
    		cout << i + 1;
    		break;
    	}
    }

    return 0;
}