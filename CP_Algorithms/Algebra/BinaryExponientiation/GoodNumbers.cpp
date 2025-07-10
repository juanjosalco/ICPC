class Solution {
public:
    typedef long long int lli;

    const lli MOD = 1e9+7;

    lli binpow(lli a, lli b){
        a %= MOD;
        lli res = 1;
        while(b > 0){
            if(b & 1){
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        if(n % 2 == 0){
            lli ans = binpow(5, n/2) * binpow(4,n/2) % MOD;
            return ans;
        }else{
            lli ans = binpow(5, (n/2)+1) * binpow(4,n/2) % MOD;
            return ans;
        }
        return 0;
    }
};