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

lli MOD = 998244353;

lli fastPow(lli a, lli b){
    lli res = 1;
    while(b){
        if(b%2)res *= a;
        res = res%MOD;
        a = a*a;
        a = a%MOD;
        b = b/2;
    }
    return res;
}
int main(){ _
    lli n,k;
    cin >>n >> k;

    lli mn = 1e9+10;
    fore(i,0,n){
        lli num;
        cin >>num;
        mn = min(mn,num);
    }

    lli numerador = 1;
    fore(i,mn +1, mn + k ){
        numerador *= i;
    }
    //cout <<numerador<<endl;

    lli denominador = 1;

    fore(i,1, k ){
        denominador *= i;
    }
    //cout << denominador <<endl;
    lli fast = fastPow(denominador,MOD-2);
    lli result = numerador*fast;
    result = result%MOD;
    cout << result<<endl;
}