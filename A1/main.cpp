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

struct Round {
    double x, y, r;
};

struct Square {
    double x1, y1, x2, y2;
};

struct Dot {
    double x, y;
};

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    srand(1337 + 707);
    Round a, b, c;
    cin >> a.x >> a.y >> a.r;
    cin >> b.x >> b.y >> b.r;
    cin >> c.x >> c.y >> c.r;

    Square area;
    area.x1 = max(a.x - a.r, max(b.x - b.r, c.x - c.r));
    area.x2 = min(a.x + a.r, min(b.x + b.r, c.x + c.r));

    area.y1 = max(a.y - a.r, max(b.y - b.r, c.y - c.r));
    area.y2 = min(a.y + a.r, min(b.y + b.r, c.y + c.r));

    Dot dot;
    ll all_dots = 0, true_dots = 0;
    clock_t timelimit = clock() + 0.9 * CLOCKS_PER_SEC;
    while (clock() < timelimit) {
        dot.x = area.x1 + (area.x2 - area.x1) * (double)rand() / RAND_MAX;
        dot.y = area.y1 + (area.y2 - area.y1) * (double)rand() / RAND_MAX;
        all_dots++;
        if (dist(dot.x, dot.y, a.x, a.y) > a.r) continue;
        if (dist(dot.x, dot.y, b.x, b.y) > b.r) continue;
        if (dist(dot.x, dot.y, c.x, c.y) > c.r) continue;
        true_dots++;
    }
    cout << (area.x2 - area.x1) * (area.y2 - area.y1) / all_dots * true_dots;
}

int main() {
    fast_io;
    ll t = 1; // cin >> t; // if each test contains several cases
    while (t--) solve();
    return 0;
}
