// only if necessary
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma warning(disable:4996)*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
// for int**_max/min, only for yandex contests
// #include <cstdint>

#define ll long long
#define ull unsigned long long
#define INF INT64_MAX
#define EPS 0.00000001
#define m1 1000000007
#define m2 1000000009
#define p 27
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define prec cout.precision(15)

using namespace std;

void sort(vector <ll>& a, int l, int r) {
    if (r - l < 15) {
        for (int i = l; i < r; i++) {
            int j = i;
            while (j > l && a[j - 1] > a[j]) {
                a[j] ^= a[j - 1];
                a[j - 1] ^= a[j];
                a[j] ^= a[j - 1];
                j--;
            }
        }
    }
    else {
        int mid = (l + r) / 2;
        sort(a, l, mid);
        sort(a, mid, r);
        vector <ll> b(r - l);
        int i1 = l, i2 = mid;
        while (i1 < mid && i2 < r) {
            b[i1 - l + i2 - mid] = min(a[i1], a[i2]);
            if (a[i1] < a[i2]) i1++;
            else i2++;
        }
        while (i1 < mid) b[i1 - l + i2 - mid - 1] = a[i1++];
        while (i2 < r) b[i1 - l + i2 - mid - 1] = a[i2++];
        for (int i = l; i < r; i++) a[i] = b[i - l];
    }
}

void sort(vector <ll>& a) {
    sort(a, 0, a.size());
}

void solve() {
    ll n; cin >> n;
    vector <ll> a(n);
    for (auto& i : a) cin >> i;
    sort(a);
    for (auto& i : a) cout << i << " ";
    cout << "\n";
}

int main() {
    fast_io;
    ll t = 1; // cin >> t; // if each test contains several cases
    while (t--) solve();
    return 0;
}
