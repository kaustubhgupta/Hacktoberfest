#include<bits/stdc++.h>
#define BATMAN                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define uii unordered_map<int, int>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define forit(it, g) for (auto it = g.begin(); it != g.end(); it++)
#define finder(x, val) return x.find(val) != x.end()

using namespace std;

int t[51][5001];
int sum;

int minsumpart(vector<int> arr, int n, int cursum, set<int> &ret)
{
	if (cursum > sum / 2)
		return 0;
	if (n == 0)
	{
		ret.insert(cursum);
		return 0;
	}
	if (t[n][cursum] != -1)
		return t[n][cursum];
	return t[n][cursum] = minsumpart(arr, n - 1, cursum + arr[n - 1], ret) + minsumpart(arr, n - 1, cursum, ret);
}

int main()
{
	BATMAN
	int T;
	cin >> T;
	while (T--)
	{
		memset(t, -1, sizeof(t));
		sum = 0;
		int N;
		cin >> N;
		vector<int> arr(N);
		FOR(i, N)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		set<int> ret;
		int catcha = minsumpart(arr, N, 0, ret);
		int mini = INT_MAX;
		for (set<int>::iterator it = ret.begin(); it != ret.end(); it++)
			mini = min(mini, sum - 2 * (*it));
		cout << mini << "\n";
	}
	return 0;
} 

// 34
// 37 28 16 44 36 37 43 50 22 13 28 41 10 14 27 41 27 23 37 12 19 18 30 33 31 13 24 18 36 30 3 23 9 20
// Ans:1