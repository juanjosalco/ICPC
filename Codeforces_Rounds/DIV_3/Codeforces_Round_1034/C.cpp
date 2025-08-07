#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define all(s) begin(s), end(s)
#define pb push_back
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli MOD = 1e9+7;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a % b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli n, m;
        cin >> n >> m;
        vector<vi> mtx(n+1, vi(m+1));
        lli maxi = LLONG_MIN;
        lli cnt = 0;
        fore(i,0,n){
            fore(j,0,m){
                cin >> mtx[i][j];
                if (mtx[i][j] > maxi) {
                    maxi = mtx[i][j], cnt = 1;
                } else if (mtx[i][j] == maxi) {
                    cnt++;
                }
            }
        }
        vi rows(n), cols(m);
        fore(i,0,n){
            fore(j,0,m){
                if(mtx[i][j] == maxi){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        lli flag = 0;
        fore(i,0,n) {
            fore(j,0,m) {
                if (rows[i] + cols[j] - (mtx[i][j] == maxi) == cnt) {
                    flag = 1;
                }
            }
        }
        cout << maxi - flag << '\n';
    }
    return 0;
}