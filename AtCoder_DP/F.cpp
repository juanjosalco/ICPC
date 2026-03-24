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
#define fore(i,a,b) for(lli i = a; i <(b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli MOD = 1e9;
const lli INF = 1e9;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a*b /mcd(a,b);}

vector<vector<lli>> dp(3001, vector<lli>(3001, 0));
vector<vector<bool>> vis(3001, vector<bool>(3001, false));

string a, b;

lli fun(lli i, lli j){
    if(i >= (lli)a.size() || j >= (lli)b.size()) return 0;
    if(vis[i][j]) return dp[i][j];

    if(a[i] == b[j]){
        dp[i][j] = fun(i+1, j+1) + 1;
    }else{
        dp[i][j] = max(fun(i+1,j), fun(i, j+1));
    }

    vis[i][j] = true;
    return dp[i][j];
}

string reconstruct(){
    fun(0,0);
    string res = "";

    lli i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] == b[j]){
            res+=a[i];
            ++i; ++j;
        } else {
            lli down  = fun(i+1, j);   
            lli right = fun(i, j+1);
            if(down >= right) ++i;
            else ++j;
        }
    }
    return res;
}

int main(){ _
    cin >> a >> b;
    cout << reconstruct() << endl;
    return 0;
}