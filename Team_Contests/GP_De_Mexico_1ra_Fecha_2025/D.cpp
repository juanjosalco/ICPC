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

int main(){ _
    lli n;
    cin >> n;
    vi tot(n);
    fore(i,0,n){
        cin >> tot[i];
    }
    lli m;
    cin >> m;
    vector<vi> mtx(m, vi(n,0));
    vi sums(n);
    fore(i,0,m){
        fore(j,0,n){
            cin >> mtx[i][j];
            sums[j] += mtx[i][j];
        }
    }
    vi res(n);
    fore(i,0,n){
        if(sums[i] != 0) res[i] = tot[i] / sums[i];
        else res[i] = 1e13;
    }
    lli mini = LLONG_MAX;
    fore(i,0,n){
        mini = min(res[i], mini);
    }
    cout << mini+1 << " ";
    fore(i,0,n){
        tot[i] -= mini*sums[i];
    }
    fore(i,0,m){
        fore(j,0,n){
            if(tot[j]-mtx[i][j] < 0){
                cout << i+1 << endl;
                return 0;
            }
            tot[j] -= mtx[i][j];
        }
    }
    return 0;
}