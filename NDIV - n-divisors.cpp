/*

NDIV - n-divisors
#number-theory #sieve
We all know about prime numbers, prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

We can Classify the numbers by its number of divisors, as n-divisors-numbers, for example number 1 is 1-divisor number, number 4 is 3-divisors-number... etc.

Note: All prime numbers are 2-divisors numbers.

Example:
8 is a 4-divisors-number [1, 2, 4, 8].

Input
Three integers a, b, n.

Output
Print single line the number of n-divisors numbers between a and b inclusive.

Example
Input:
1 7 2

Output:
4

*/


/*
    Miles to go before I sleep, Miles to go before I sleep!
*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

void sieve(bool primes[], int x)
{
    primes[1] = false;
 
    // if a number is prime mark all its multiples
    // as non prime
    for (int i=2; i*i <= x; i++)
    {
        if (primes[i] == true)
        {
            for (int j=2; j*i <= x; j++)
                primes[i*j] = false;
        }
    }
}
 
int nDivisors(bool primes[], int x, int a, int b, int n)
{
    int result = 0;
    vector <int> v;
    for (int i = 2; i <= x; i++)
        if (primes[i] == true)
            v.push_back (i);
    for (int i=a; i<=b; i++)
    {
        int temp = i;
        int total = 1;
        int j = 0;
        for (int k = v[j]; k*k <= temp; k = v[++j])
        {
            int count = 0;
            while (temp%k == 0)
            {
                count++;
                temp = temp/k;
            }
            total = total*(count+1);
        }
        if (temp != 1)
            total = total*2;
        if (total == n)
            result++;
    }
    return result;
}
 
int countNDivisors(int a, int b, int n)
{
    int x = sqrt(b) + 1;
    bool primes[x];
    memset(primes, true, sizeof(primes));
    sieve(primes, x);
    return nDivisors(primes, x, a, b, n);
}

void solve() {
	int a,b,n;
	cin >> a >> b >> n;
	int ans = countNDivisors(a,b,n);
	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();

	int t = 1;
	// cin >> t;
	while (t--) solve();

	//cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}
