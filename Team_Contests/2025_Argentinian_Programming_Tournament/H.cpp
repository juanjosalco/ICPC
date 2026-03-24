#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef long double ld;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){ _
    lli n;
    cin >> n;
    vi a(n);
    fore(i,0,n) cin >> a[i];
    
    sort(a.begin(), a.end());

    if (a[0] != 1) {
        cout << a[n-1]  << " " << 1;
        return 0;
    }

    if (n==1){cout << '*';return 0;}
    
    bool ld = true;
    fore(i,0,n-1) {
        if (a[n-1] % a[i] != 0) {ld=false;break;}
    }

    set<lli> s(a.begin(), a.end());

    bool pw = sqrt(a[1])*sqrt(a[1]) != a[1];
    if (pw){
    lli inv=a[1];
    fore(i,1,n){
        if (s.count(a[n-1]/a[i]) == 0){
            pw=false;
            break;
        }
    }
    }

    if (!ld || pw){
        cout << a[1]*a[n-1] << " " << a[1]*a[n-1];
        return 0;
    }

    fore(i,1,n){
        lli h =a[n-1]/a[i];
        if (s.count(h)==0){
            cout << a[n-1] << " " << h;
            return 0;
        }
    }

    lli l = 1,r = 1e9 + 1 , x = a[n-1];

    // while(l<r-1){
    //     lli m = (l+r)/2;
    //     if (m*m <= x){
    //         l = m;
    //     }
    //     else{
    //         r = m;
    //     }
    // }
    cout << x << " "  << (lli)sqrt(x);
    return 0;
}