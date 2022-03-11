#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file ""

using namespace std;

const ll oo = 2e18;
const int N = 1000000;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

string tostr(int x)
{
    if (x < 10)
    {
        string s = "0";
        s += char(x + '0');
        return s;
    }
    return "10";
}

ll RAND(ll l, ll h)
{
    assert(l <= h);
    ll ret = (ll)rd() % (ll)1e9 * (ll)(rd() % (ll)1e9);
    ret = ret % (h - l + 1) + l;
    return ret;
}

vector <ll> arr_rand()
{
    vector <ll> ret(N);
    for (int i=0;i<N;++i) ret[i] = RAND(1,1e18);
    return ret;
}

vector <ll> cur;

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int test=1;test<=10;++test)
    {
        string name = "input" + tostr(test) + ".txt";
        ofstream fo (name.c_str());
        cur = arr_rand();
        fo << N << '\n';
        if (test == 1) sort(cur.begin(),cur.end());
        else if (test == 2) sort(cur.begin(),cur.end(),greater<ll>());
        for (auto it : cur) fo << it << " ";
        fo.close();
    }
    return 0;
}
