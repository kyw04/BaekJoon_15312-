#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numbering[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
//int counting(const vector<int> number, int index, int cnt, int n)
//{
//	if (index + 1 >= n)
//		return cnt;
//	cnt = number[index] + number[index + 1];
//	return (counting(number, index + 1, cnt, n) + cnt) % 10;
//}
int main()
{
	string A, B;
	cin >> A >> B;
	int n = A.length() + B.length(), index = 0;
	vector<int> v(n);
	vector<vector<int>> cnt(n , vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			v[i] = numbering[A[index] - 'A'];
		else 
			v[i] = numbering[B[index++] - 'A'];
	}



	for (int i = 0; i < n - 1; i++)
	{
		cnt[0][i] = v[i] + v[i + 1];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - (i + 1); j++)
		{
			if (n - (i + 1) == 1)
			{
				cout << cnt[i - 1][j] << cnt[i - 1][j + 1];
				return 0;
			}
			cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j + 1];
			cnt[i][j] %= 10;
		}
	}
	return 0;
}