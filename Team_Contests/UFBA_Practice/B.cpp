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
    string str,str2;
    cin >> str >>str2;

    lli n, m;
    n = str.size();
    m = str2.size();

    vi poss(n,0);
    vi ceros;
    vi unos;

    fore(i,0,m){
        if(str2[i] == '1')unos.pb(i);
        else ceros.pb(i);
    }

    fore(j,0,n-m + 1){
        bool valid = true;
        fore(a,1,ceros.size()){
            if(str[j+ceros[a]] != str[j+ceros[a-1]]){
                valid =false;
                break;
            }
        }
        fore(a,1,unos.size()){
            if(str[j+unos[a]] != str[j+unos[a-1]]){
                valid =false;
                break;
            }
        }
        if(valid) poss[j] = 1;  
    }
    reverse(all(str));

    fore(j,0,n-m +1){
        bool valid = true;
        fore(a,1,unos.size() ){
            if(str[j+unos[a]] != str[j+unos[a-1]]){
                valid = false;
                break;
            }
        }

        fore(a,1,ceros.size()){
            if(str[j+ceros[a]] != str[j+ceros[a-1]]){
                valid = false;
                break;
            }
        }
        if(valid) poss[n-j - m] = 1;  
    }

    lli cont = 0;
    //cout <<poss[0]<<endl;
    fore(i,0,n)cont += poss[i];

    cout<<cont<<endl;

    return 0;
}