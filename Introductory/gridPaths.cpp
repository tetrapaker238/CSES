#include <bits/stdc++.h> 
using namespace std; 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define ll long long 
#define ld long double 
#define le length
#define rep(i , j , n) for(ll i = j ; i <= n ; i++) 
#define per(i , j , n) for(ll i = j ; i >= n ; i--)  

string s;
ll n = 7, solutionsCounter = 0, stepsCounter = 0,
 downCounter = 0, rightCounter = 0, x = 0, y = 0;
vector<vector<ll>> grid(n, vector<ll>(n, 0));

void solveGridPaths() {
    if (stepsCounter == 48) {
        if (x == 0 && y == 6) {
            solutionsCounter++;
        } else {
            return;
        }
    } else { 

        if (((y == 0  || y == 6) || (grid[x][y - 1] && grid[x][y + 1])) && x > 0 && x < 6 && !grid[x - 1][y] && !grid[x + 1][y]) {
            return;
        }

        if (((x == 0 || x == 6) || (grid[x - 1][y] && grid[x + 1][y])) && y > 0 && y < 6 && !grid[x][y - 1] && !grid[x][y + 1]) {
            return;
        }


        if (x == 0 && y == 6) {
            return;
        }

        if (y - 1 >= 0 && !grid[x][y - 1] && (s[stepsCounter] == 'U' || s[stepsCounter] == '?')) {
            y -=1;
            grid[x][y] = 1;
            stepsCounter++;
            solveGridPaths();
            stepsCounter--;
            grid[x][y] = 0;
            y+=1;
        }

        if (y + 1 <= 6 && !grid[x][y + 1] && (s[stepsCounter] == 'D' || s[stepsCounter] == '?')) {
            y +=1;
            grid[x][y] = 1;
            stepsCounter++;
            solveGridPaths();
            stepsCounter--;
            grid[x][y] = 0;
            y-=1;
        }

        if (x - 1 >= 0 && !grid[x - 1][y] && (s[stepsCounter] == 'L' || s[stepsCounter] == '?')) {
            x-=1;
            grid[x][y] = 1;
            stepsCounter++;
            solveGridPaths();
            stepsCounter--;
            grid[x][y] = 0;
            x+=1;
        }

        if (x + 1 <= 6 && !grid[x + 1][y] && (s[stepsCounter] == 'R' || s[stepsCounter] == '?')) {
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