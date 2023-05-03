#include<bits/stdc++.h>
#define ll long long
#define lg2 std::__lg
using namespace std;
const int N = 1<<18;
const int mod = 998244353;
int input_n, ans, Th[N], nTh, Rh[N], nRh, temp1[N], temp1n, temp2[N], temp2n;

int add(int x, int y){int z = (x+y)%mod; if (z < 0) z += mod; return z;}
int mul(int x, int y){int z = 1ll*x*y%mod; if (z < 0) z += mod; return z;}
int MyMin(int x, int y){return x < y ? x : y;}
int MyMax(int x, int y){return x > y ? x : y;}

int Pow(int x, int y)
{
	int ret = 1;
	while (y){if (y&1) ret = mul(ret, x); x = mul(x, x); y >>= 1;}
	return ret;
}

void ntt(int *a, int *r, int *g, int n)
{
	for (int i = 0; i < n; ++ i) if (r[i] < i) swap(a[i], a[r[i]]);
	for (int i = 1, t = n>>1; i < n; i <<= 1, t >>= 1)
		for (int j = 0; j < n; j += (i<<1))
			for (int k = 0; k < i; ++ k){
				int x = a[j+k], y = mul(g[t*k], a[i+j+k]);
				a[j+k] = add(x, y); a[i+j+k] = add(x, -y);
			}
}

void poly_mul(int *a, int na, int *b, int nb, int *c, int &nc){ // c = a * b
    static int n, l, r[N], g[N];
    nc = MyMin(na+nb-1, N);
    nc = MyMin(nc, input_n+1);
	for (n = 1, l = 0; n < MyMin(na+nb-1, N); n <<= 1, ++ l);
    g[0] = 1; g[1] = Pow(3, (mod-1)/n); // mod 998244353 g=3, g^(p-1)=wn^n=1, wn=g^((p-1)/n)
	for (int i = 2; i < n; ++ i) g[i] = mul(g[i-1], g[1]);
	r[0] = 0; 
	for (int i = 0; i < n; ++ i) r[i] = (r[i>>1]>>1)^((i&1)<<(l-1));
    ntt(a, r, g, n); ntt(b, r, g, n);
	for (int i = 0; i < n; ++ i) c[i] = mul(a[i], b[i]);
	g[0] = 1; g[1] = Pow(g[1], mod-2);
	for (int i = 2; i < n; ++ i) g[i] = mul(g[i-1], g[1]);
	ntt(c, r, g, n);
    int invn = Pow(n, mod-2);
	for (int i = 0; i < n; ++ i) c[i] = mul(c[i], invn);
    for (int i = nc; i < n; ++ i) c[i] = 0;
}

void poly_left_shift(int *a, int & na){ // a = a << 1
	na = MyMin(na+1, N);
	for (int i = na-1; i >= 1; -- i) a[i] = a[i-1];
	a[0] = 0;
}

void poly_add(int *a, int &na, int *b, int nb){ // a = a + b
	na = MyMax(na, nb);
	for (int i = 0; i < na; ++ i)
		a[i] = add(a[i], b[i]);
}

void poly_copy(int *a, int &na, int *b, int nb){ // a = b
	na = nb;
	for (int i = 0; i < na; ++ i)
		a[i] = b[i];
	for (int i = na; i < N; ++ i)
		a[i] = 0;
}

void poly_output(int *a, int na){
	cout << na << endl;
	for (int i = 0; i < na; ++ i)
		cout << a[i] << ", ";
	cout << endl << "==========================================" << endl;
}

int main()
{
	cin >> input_n;
	ans = 0;
	memset(Th, 0, sizeof(Th));
	Th[0] = 0;
	Th[1] = 1;
	Th[2] = 2;
	Th[3] = 1;
	nTh = 4;
	ans = add(ans, Th[input_n]);
	for (int i = 0, ub = lg2(input_n+1); i < ub; ++ i){
		poly_copy(temp1, temp1n, Th, nTh);
		poly_copy(temp2, temp2n, Th, nTh);
		poly_mul(temp1, temp1n, temp2, temp2n, Rh, nRh);
		poly_left_shift(Rh, nRh);
		poly_add(Rh, nRh, Th, nTh);
		poly_copy(temp1, temp1n, Rh, nRh);
		poly_copy(temp2, temp2n, Rh, nRh);
		poly_mul(temp1, temp1n, temp2, temp2n, Th, nTh);
		poly_left_shift(Th, nTh);
		ans = add(ans, Th[input_n]);
	}
	cout << ans << endl;
	return 0;
}
