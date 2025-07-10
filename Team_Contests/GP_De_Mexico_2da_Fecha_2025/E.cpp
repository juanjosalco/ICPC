#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){ _
    lli n;
    cin >> n;
    string st;
    cin >> st;

    string leftS = st.substr(0, st.size() - 1);
    char rightS = st.back();
    lli totalMB;
    switch(rightS){
        case 'G':
            totalMB = stoll(leftS) * 1000;
            break;
        case 'T':
            totalMB = stoll(leftS) * 1000000;
            break;
        default:
            totalMB = stoll(st);
    }

    vi a(n);
    fore(i, 0, n) {
        cin >> a[i];
    }

    lli l = 0, sum = 0, mini = LLONG_MAX;
    lli startIdx = -1, endIdx = -1;

    for (lli r = 0; r < n; ++r) {
        sum += a[r];

        while (sum > totalMB && l <= r) {
            sum -= a[l++];
        }

        if (sum <= totalMB && (r - l + 1) < mini) {
            mini = r - l + 1;
            startIdx = l;
            endIdx = r;
        }
    }

    if (startIdx != -1) {
        cout << "Minimum window size: " << mini << endl;
        cout << "Start index: " << startIdx << ", End index: " << endIdx << endl;
    } else {
        cout << "No valid window found." << endl;
    }

    return 0;
}
