#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define ll           long long int
#define pb           push_back
#define F            first
#define S            second
#define mk           make_pair
using namespace std;
template<typename T>istream & operator >> (istream &in, vector<T> &a){for(auto &x:a)in>>x;return in;}
template<typename T>ostream & operator << (ostream &out, vector<T> &a){for(auto &x:a)out<<x<<" ";return out;}
template<typename T,typename K>istream & operator >> (istream &in,  pair<T,K> &a){in>>a.F>>a.S;return in;}
template<typename T,typename K>ostream & operator << (ostream &out, pair<T,K> &a){out<<a.F<<" "<<a.S;return out;}

typedef long long i64;
typedef complex<double> im;

const int o = 20, len = 1 << o, mod = 1e9 + 7;
const double pi = acos(-1.0);

namespace poly {
int r[len], up, l;
im w[len], iw[len], I(0, 1);

void init() {
  w[1] = iw[1] = im(1, 0);
  for (int l = 2; l != len; l <<= 1) {
    double x = cos(pi / l), y = sin(pi / l);
    im p(x, y), ip(x, -y);
    for (int i = 0; i != l; i += 2) {
      w[l + i] = w[(l + i) >> 1], iw[l + i] = iw[(l + i) >> 1];
      w[l + i + 1] = w[l + i] * p, iw[l + i + 1] = iw[l + i] * ip;
    }
  }
  for (int i = (len >> 1) - 1; i; i--)
    w[i] = w[i << 1], iw[i] = iw[i << 1];
  for (int i = 0; i != len; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (o - 1));
}

int pre(int n) {
  l = 32 - __builtin_clz(n), up = 1 << l;
  return up;
}

void fft(im *a, int n, bool op, im *w) {
  for (int i = 0; i != n; i++) {
    int t = r[i] >> (o - l);
    if (i < t)
      swap(a[i], a[t]);
  }
  for (int l = 1; l != n; l <<= 1) {
    im *k = w + l;
    for (im *f = a; f != a + n; f += l)
      for (im *j = k; j != k + l; j++, f++) {
        im x = *f, y = f[l] * *j;
        f[l] = x - y, *f += y;
      }
  }
  if (op)
    for (int i = 0; i != n; i++)
      a[i] /= n;
}

vector<int> mul(vector<int> &f, vector<int> &g) {
    int n = f.size()-1,m = g.size()-1;
  static im a[len], b[len], c[len], d[len];
  pre(n + m);
  int mm = sqrt(mod);
  for (int i = 0; i <= n; i++)
    a[i] = im(f[i] % mm, f[i] / mm);
  for (int i = 0; i <= m; i++)
    b[i] = im(g[i] % mm, g[i] / mm);
  fft(a, up, 0, w), fft(b, up, 0, w);
  for (int i = 0; i != up; i++) {
    a[i] /= 2, b[i] /= 2;
    c[i] = im(a[i].real(), -a[i].imag()), d[i] = im(b[i].real(), -b[i].imag());
  }
  reverse(c + 1, c + up), reverse(d + 1, d + up);
  for (int i = 0; i != up; i++) {
    im a0 = a[i] + c[i], a1 = (c[i] - a[i]) * I;
    im b0 = b[i] + d[i], b1 = (d[i] - b[i]) * I;
    a[i] = a0 * b0 + I * a1 * b1, b[i] = a0 * b1 + I * a1 * b0;
  }
  fft(a, up, 1, iw), fft(b, up, 1, iw);
  auto num = [](double x) { return (i64)round(x) % mod; };
  vector<int> h(n+m+1);
  for (int i = 0; i <= n + m; i++)
    h[i] = (num(a[i].real()) + num(a[i].imag()) * mm * mm + (num(b[i].real()) + num(b[i].imag())) * mm) % mod;
  for (int i = 0; i != up; i++)a[i] = b[i] = c[i] = d[i] = 0;
  return h;
}
} // namespace poly please call poly::init() and set o,len,mod accordingly


const int N = 2e3+1;
const int M = 1e5;

vector<int> powmod(vector<int> a,int p){
    vector<int> res(a.size());res[0]=1;
    while(p){
        if(p&1)res = poly::mul(res,a);
        p>>=1;
        a = poly::mul(a,a);
    }
    return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 3e3;
    cout<<t<<"\n";
    while(t--){
        cout<<"2000 2000 1500\n";
    }
	return 0;
}
