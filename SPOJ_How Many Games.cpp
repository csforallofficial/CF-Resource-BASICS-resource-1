/*
GAMES - How Many Games?
no tags 
Problem Statement:

A player has played unknown number of games. We know the average score of the player (sum of scores in all the games / no. of games). Find the minimum number of games the player should have played to achieve that average.

The player can score any non-negative integer score in a game.

Input:

The first line consists of an integer t, the number of test cases. Each test case consists of a single Rational Number which represents the average score of the player.


Output:

For each test case, find the minimum number of matches the player should have played to achieve that average.

Input Constraints:

1 <= t <= 1000
1 <= avg <= 1000000 (maximum 4 digits after the decimal place)

Example:

Sample Input:
3
5
5.5
30.25

Sample Output:
1
2
4
*/



/*
    Miles to go before i sleep, Miles to go before i sleep!
*/
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	if (a < b)
		return gcd(a, b % a);
	else
		return gcd(b, a % b);
}

/*
For example N = 4.50, integral value = 4  and  fractional part = 0.50 
           
Consider precision value to be (109) that is precision value = 1000000000 
           
Calculate GCD(0.50 *  109, 109) = 500000000 
           
Calculate numerator = (0.50 * 10^9) / 500000000 = 1 and denominator = 10^9/ 500000000 = 2 
           
Convert mixed fraction into improper fraction that is fraction = ((4 * 2) + 1) / 2 = 9/2 
*/

void solve(double number)
{
	double intVal = floor(number);
	double fVal = number - intVal;
	const long pVal = 1000000000;
	long long gcdVal
		= gcd(round(fVal * pVal), pVal);
	long long deno = pVal / gcdVal;
	cout << deno << endl;
}

int main()
{
  	int t;
  	cin >> t;
  	while(t--){
      	double N;
      	cin >> N;
		solve(N);
    }
	return 0;
}
