#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli n;
vi currSet;

void rotate(vector<vi>& mtx){
    fore(i,0,n){
        fore(j,i,n){
            swap(mtx[i][j], mtx[j][i]);
        }
    }
    fore(i,0,n){
        fore(j,0,n/2){
            swap(mtx[i][j], mtx[i][n-j-1]);
        }
    }
}

void spiralTLD(vector<vi>& mtx, lli i, lli j) {
    lli up = 0, down = n - 1, left = 0, right = n - 1;
    while(currSet.size() < n * n) {
        for(lli row = up; row <= down; row++) currSet.pb(mtx[row][left]);          // ↓
        for(lli col = left + 1; col <= right; col++) currSet.pb(mtx[down][col]);   // →
        if(left != right) for(lli row = down - 1; row >= up; row--) currSet.pb(mtx[row][right]); // ↑
        if(up != down) for(lli col = right - 1; col > left; col--) currSet.pb(mtx[up][col]);     // ←
        left++; right--; up++; down--;
    }
}


void spiralTLR(vector<vi>& mtx, lli i, lli j){
    lli up = 0, down = n - 1, left = 0, right = n - 1;
    while(currSet.size() < n * n){
        for(lli col = left; col <= right; col++) currSet.pb(mtx[up][col]);         // →
        for(lli row = up + 1; row <= down; row++) currSet.pb(mtx[row][right]);     // ↓
        if(up != down) for(lli col = right - 1; col >= left; col--) currSet.pb(mtx[down][col]); // ←
        if(left != right) for(lli row = down - 1; row > up; row--) currSet.pb(mtx[row][left]);  // ↑
        left++; right--; up++; down--;
    }
}


lli getMax(vi nums){
    fore(i,1,nums.size()){
        nums[i] = nums[i-1]+nums[i];
        if(nums[i] < 0) nums[i] = 0;
    }
    lli maxi = 0;
    fore(i,0,nums.size()){
        maxi = max(nums[i], maxi);
    }
    return maxi;
}



int main(){ _
    cin >> n;
    vector<vi> g(n, vi(n, 0));
    fore(i,0,n){
        fore(j,0,n){
            cin >> g[i][j]; 
        }
    }
    lli maxi = 0;
    lli x = 0;

    vector<vi> g1 = g;
    vector<vi> g2 = g;
    

    spiralTLR(g1,0,0);
    x = getMax(currSet);
    maxi = max(x, maxi);
    currSet.clear();

    spiralTLD(g2,0,0);
    x = getMax(currSet);
    maxi = max(x, maxi);
    currSet.clear();

    rotate(g);

    vector<vi> g3 = g;
    vector<vi> g4 = g;

    spiralTLR(g3,0,n-1);
    x = getMax(currSet);
    maxi = max(x, maxi);
    currSet.clear();

    spiralTLD(g4,0,n-1);
    x = getMax(currSet);
    maxi = max(x, maxi);
    currSet.clear();

    rotate(g);

    vector<vi> g5 = g;
    vector<vi> g6 = g;

    spiralTLR(g5,n-1,n-1);
    x = getMax(currSet);
    maxi = max(x, maxi);
    currSet.clear();

    spiralTLD(g6,n-1,n-1);
    x = getMax(currSet);
    maxi = max(x, maxi);
    currSet.clear();

    rotate(g);

    vector<vi> g7 = g;
    vector<vi> g8 = g;

    spiralTLR(g7,n-1,0);
    x = getMax(currSet);
    maxi = max(x, maxi);
    currSet.clear();

    spiralTLD(g8,n-1,0);
    x = getMax(currSet);
    maxi = max(x, maxi);
    currSet.clear();

    cout << maxi << endl;
    
    return 0;
}