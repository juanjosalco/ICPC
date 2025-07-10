#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli k;

vi applyPerm(vi seq, vi perm){
    vi newSeq(seq.size());
    fore(i,0,seq.size()){
        newSeq[i] = seq[perm[i]];
    }
    return newSeq;
}

vi binpow(vi seq, vi perm){
    while(k > 0){
        if(k & 1){
            seq = applyPerm(seq, perm);
        }
        perm = applyPerm(perm, perm);
        k >>= 1;
    }
    return seq;
}

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n >> k;

        // ------ Permutation Described ------
        vi per(n);
        lli j = 0;
        fore(i,0,n/2){
            per[i] = j;
            j += 2;
        }
        j = 1;
        fore(i,n/2,n){
            per[i] = j;
            j += 2;
        }

        // ----- Sequence Given --------
        vi seq(n);
        fore(i,0,n){
            seq[i] = i+1;
        }

        vi result = binpow(seq, per);

        fore(i,0,n){
            cout << result[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
