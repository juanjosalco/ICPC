#include <bits/stdc++.h> 

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl "\n"
#define f first
#define s second
#define all(s) begin(s),end(s);
#define pb push_back
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli mcd(lli a, lli b){return b ? mcd(b, a%b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

struct Kid {
    lli ti, zi, yi;
    Kid(lli ti = 0, lli zi = 0, lli yi = 0): ti(ti), zi(zi), yi(yi) {}
};

lli n, m;
vector<Kid> a;
vi b;

bool isOk(lli x){
    lli ans = 0;
    fore(i,0,m){
        lli cicle = ((a[i].ti*a[i].zi)+a[i].yi);
        lli segUsables = min((x % cicle), cicle-a[i].yi);
        lli nCicle = x / cicle;
        lli gTR = segUsables/a[i].ti;
        ans += nCicle*a[i].zi;
        ans += gTR;
        b[i] = nCicle*a[i].zi + gTR;
    }
    return ans >= n;
}

int main(){ _
    cin >> n >> m;
    a.resize(m,0);
    b.resize(m,0);
    fore(i,0,m){
        lli ti,zi,yi;
        cin >> ti >> zi >> yi;
        a[i].ti=ti;
        a[i].zi=zi;
        a[i].yi=yi;
    }
    if(n == 0){
        cout << 0 << endl;
        fore(i,0,m){
            cout << 0 << " ";
        }
    }else{
        lli l = 0;
        lli r = 1;
        while(!isOk(r)){
            r*=2;
        }
        while(l + 1 < r){
            lli mid = (l+r)/2;
            if(isOk(mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout << r << endl;
        isOk(r);
        lli remaining = n;
        fore(i,0,m){
            lli take = min(b[i], remaining);
            cout << take << " ";
            remaining -= take;
        }
        cout << endl;
    }
    return 0;
}