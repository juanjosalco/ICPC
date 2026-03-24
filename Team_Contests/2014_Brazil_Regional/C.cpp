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

int n;
vi age,mage;
vector<pair<int,int>> g;

void cons(){
    mage = vi(n+1,101);
    for(auto &[x,y] : g){
        mage[y]=min(mage[y],min(mage[x],age[x]));
    }
}

int main(){ _
    int m,i;
    cin>>n>>m>>i;
    age = vi(n+1);
    g = vector<pair<int,int>>(m);
    fore(i,0,n){
        cin>>age[i+1];
    }
    fore(i,0,m){
        int x,y;
        cin>>x>>y;
        g[i]={x,y};
    }
    bool c = true;
    while(i--){
        char I;
        int x,y;
        cin>>I;
        if (I == 'P'){
            if (c){
                cons();
                c=false;
            }
            cin >> x;
            int r = mage[x];
            if (r == 101)
                cout << "*" <<endl;
            else
                cout << r <<endl;
        }else{
            cin>>x>>y;
            c=true;
            for(auto &[a,b] : g){
                if (a == y) a = x;
                else if (a == x) a = y;
                if (b == y) b = x;
                else if (b == x) b = y;
            }
        }
    }
    return 0;
}