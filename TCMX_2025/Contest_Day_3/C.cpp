#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli, lli> ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i, a, b) for (lli i = a; i < (b); i++)
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

set<lli> pot = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

int main()
{
    _
        lli t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        if (n & (n - 1))
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        vi cicle1 = {3, 2, 1, 2};
        vi cicle2 = {1, 2, 3, 2};
        vi a;
        vi b;
        lli i = 1;
        lli ptr = 0;
        lli counter = 0;
        while (counter < n)
        {
            a.pb(i);
            i += cicle1[ptr % 4];
            ptr++;
            counter++;
        }
        i = 2;
        ptr = 0;
        counter = 0;
        while (counter < n)
        {
            b.pb(i);
            i += cicle2[ptr % 4];
            ptr++;
            counter++;
        }
        fore(i, 0, a.size())
        {
            cout << a[i] << " ";
        }
        cout << endl;
        fore(i, 0, b.size())
        {
            cout << b[i] << " ";
        }
    }
    return 0;
}