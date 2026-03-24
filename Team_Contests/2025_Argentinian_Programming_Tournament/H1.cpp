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

    if(n==2) {
        lli raiz = sqrt(a[1]);
        if(raiz * raiz == a[1]){
            cout << raiz <<endl;
        }
        else cout << a[1] * a[1] <<endl;
        return 0;
    }
    
    
    bool ld = true;
    fore(i,0,n-1) {
        if (a[n-1] % a[i] != 0) {ld=false;break;}
    }

        
    if (!ld){
        cout << a[1]*a[n-1] << " " << a[1]*a[n-1];
        return 0;
    }

    lli invalid = 0;
    lli m = n-2;
    fore(i, 0, (m-1)/2 + 1){
        if(a[i+1] * a[n - i - 2] != a[n-1] )invalid++;
    }

    set<lli> s(a.begin(), a.end());

    if(invalid = 1){
        
        fore(i,1,n){
        lli h =a[n-1]/a[i];
        if (s.count(h)==0){
            cout << a[n-1] << " " << h;
            return 0;
        }
    }

    }
    else{
        cout <<a[1]*a[n-1] << " " << a[1]*a[n-1];
    }


}