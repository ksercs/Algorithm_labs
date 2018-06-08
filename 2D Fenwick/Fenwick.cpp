#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>
#include <climits>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 1000 + 15;

int n, m;
int X1, Y1, X2, Y2, w;
int d[4], t[4][MAXN][MAXN], ans;

void inc(int x, int y, long long w)
{
    d[0] = w,
    d[1] = w * (1 - y),
    d[2] = w * (1 - x),
    d[3] = w * (1 - x) * (1 - y);
    for(int i = x; i <= n; i |= i + 1)
       for(int j = y; j <= m; j |= j + 1) {
           t[0][i][j] += d[0];
           t[1][i][j] += d[1];
           t[2][i][j] += d[2];
           t[3][i][j] += d[3];
       }
}

int sum(int x, int y)
{
    d[0] = d[1] = d[2] = d[3] = 0;
    for(int i = x; i > 0; i = (i & (i + 1)) - 1)
       for(int j = y; j > 0; j = (j & (j + 1)) - 1) {
           d[0] += t[0][i][j];
           d[1] += t[1][i][j];
           d[2] += t[2][i][j];
           d[3] += t[3][i][j];
       }
    return d[0] * x * y + d[1] * x + d[2] * y + d[3];
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int q;
    cin >> n >> m;
    cin >> q;
    string s;
    while(q--)
    {
       cin >> s >> X1 >> Y1 >> X2 >> Y2;
       if(s != "sum")
       {
           int w;
           cin >> w;
           inc(X1-1, Y1-1, w);
           inc(X2, Y2, w);
           inc(X2, Y1 - 1, -w);
           inc(X1 - 1, Y2, -w);
       }
       else
           cout << sum(X2, Y2) - sum(X1 - 1, Y2) - sum(X2, Y1 - 1) + sum(X1 - 1, Y1 - 1) << "\n";
    }
    return 0;
}
