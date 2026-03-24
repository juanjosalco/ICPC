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

string t, p;
vi a;

bool isOk(lli x){
    set<lli> in;
    fore(i,0,x){
        in.insert(a[i]);
    }
    lli p1=0;
    fore(i,0,t.size()){
        if(!in.count(i+1)){
            if(t[i]==p[p1]){
                p1++;
                if(p1 == p.size()){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){ _
    cin >> t >> p;
    a.resize(t.size());
    fore(i,0,t.size()){
        cin >> a[i];
    }
    lli l = -1;
    lli r = t.size();
    while(l+1 < r){
        lli mid = (l+r)/2;
        if(isOk(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}