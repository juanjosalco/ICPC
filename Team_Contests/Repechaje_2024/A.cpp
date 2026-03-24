#include <bits/stdc++.h> 

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first 
#define s second
#define pb push_back()
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}

int main(){ _
    lli N, M, O;
    cin >> N >> M >> O;

    vi stock(N);
    fore(i,0,N) cin >> stock[i];

    vector<map<lli,lli>> dish(M);
    fore(d,0,M){
        lli k; cin >> k;
        fore(j,0,k){
            lli ing, q; cin >> ing >> q;
            --ing;                    
            dish[d][ing] += q;   
        }
    }

    lli fulfilled = 0;
    fore(t,0,O){
        lli cnt; cin >> cnt;

        map<lli,lli> dishCount;
        fore(j,0,cnt){
            lli d; cin >> d; --d;
            dishCount[d]++;
        }

        vi need(N, 0);
        bool possible = true;

        for (auto &dc : dishCount){
            lli d = dc.first, times = dc.second;
            for (auto &req : dish[d]){
                lli ing = req.first, per = req.second;
                need[ing] += times * per;
                if (need[ing] > stock[ing]) possible = false; 
            }
            if (!possible) break;
        }

        if (!possible) break; 

        fore(i,0,N) stock[i] -= need[i];
        fulfilled++;
    }

    cout << fulfilled << endl;
    return 0;
}
