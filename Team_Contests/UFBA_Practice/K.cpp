#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef long double ld;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

int main(){ _
    lli n;
    cin >> n;
    vi a(n);
    fore(i,0,n){
        cin >> a[i];
    }
    vi pref(n+1, 0);
    fore(i,1,n+1){
        pref[i] = a[i-1]+pref[i-1];
    }
    vi dif(n+1, 0);
    dif[0] = 0;
    dif[1] = 0;
    dif[2] = 0;
    fore(i,3,n+1){
        dif[i] = pref[i]-pref[i-3];
        dif[i] = max(dif[i], 0LL);
    }
    vi difPref(n+1,0);
    vector<bool> vis(n+1,false);
    lli i = 3;
    while(vis[i] == false){
        for(lli j = i; j < n+1; j+=3){
            difPref[j] += dif[j];
            vis[j]=true;
        }
        i++;
    }
    vi fi;
    for(lli i = 0; i < n; i+=3){
        fi.pb(i);
        if(i == 0) i--;
    }
    vi se;
    for(lli i = 1; i < n; i+=3){
        se.pb(i);
        if(i == 1) i--;
    }
    vi th;
    for(lli i = 2; i < n; i+=3){
        th.pb(i);
        if(i == 2) i--;
    }
    vi ans(n+1);
    fore(i,0,fi.size()){
        if(i == 0) ans[fi[i]] = difPref[fi[fi.size()-1]];
        else{
            ans[fi[i]] = difPref[fi[fi.size()-1]] - difPref[fi[i-1]];
        }
    }
    fore(i,0,se.size()){
        if(i == 0) ans[se[i]] = difPref[se[se.size()-1]] ;
        else{
            ans[se[i]] = difPref[se[se.size()-1]] - difPref[se[i-1]];
        }
    }
    fore(i,0,th.size()){
        if(i == 0) ans[th[i]] = difPref[th[th.size()-1]];
        else{
            ans[th[i]] = difPref[th[th.size()-1]] - difPref[th[i-1]];
        }
    }
    fore(i,0,n){
        cout << ans[i] << " ";
    }
    return 0;
}