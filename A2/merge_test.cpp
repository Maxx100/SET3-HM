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
#include <chrono>
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

struct ArrayGenerator {
    vector <ll> a;

    ArrayGenerator(int mode) {
        a.resize(10010);
        if (mode == 1) for (auto& i : a) i = rand() % 6001;
        else if (mode == 2) {
            ll now = 6000;
            for (auto& i : a) {
                i = now;
                if (now > 0 && rand() % 101 == 77) now--;
            }
        }
        else {
            iota(a.begin(), a.end(), 0);
            for (int i = rand() % 200 + 100; i > 0; i--) {
                swap(a[rand() % a.size()], a[rand() % a.size()]);
            }
        }
    }

    vector <ll> get_array(int size) {
        vector <ll> temp(size);
        int start = rand() % (a.size() - size);
        for (int i = start; i - start < size; i++) temp[i - start] = a[i];
        return temp;
    }
};

void sort(vector <ll>& a, int l, int r) {
    if (r - l < -1) {
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
        if (r - l == 1) return;
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
    ArrayGenerator gen1(1), gen2(2), gen3(3);
    vector <ArrayGenerator> gen = { gen1, gen2, gen3 };

    vector <ll> a;
    vector <vector <ll>> results;
    for (int size = 500; size <= 10000; size += 100) {
        results.push_back({ size });
        ll temp = 0;
        for (auto& i : gen) {
            for (int j = 0; j < 5; j++) {
                a = i.get_array(size);
                auto start = chrono::high_resolution_clock::now();
                sort(a);
                auto elapsed = chrono::high_resolution_clock::now() - start;
                ll msec = chrono::duration_cast<chrono::microseconds>(elapsed).count();
                temp += msec;
            }
            results[results.size() - 1].push_back(temp / 5);
        }
    }

    for (auto& i : results) {
        cout << "Size: " << i[0] << " | Time: " << i[1] << " " << i[2] << " " << i[3] << "\n";
    }

    // ll n; cin >> n;
    // vector <ll> a(n);
    // for (auto& i : a) cin >> i;
    // sort(a);
    // for (auto& i : a) cout << i << " ";
    // cout << "\n";
}

int main() {
    fast_io;
    ll t = 1; // cin >> t; // if each test contains several cases
    while (t--) solve();
    return 0;
}
