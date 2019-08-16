#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
//�ݹ���ַ�����
void binaryFind(vector<int> input, int target, int &ans, int begin, int end)
{
	if (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (target > input[mid])
		{
			binaryFind(input, target, ans, mid + 1, end);
		}
		else if (target < input[mid])
		{
			binaryFind(input, target, ans, begin, mid - 1);
		}
		else
			ans = mid;
	}

}
int main()
{
	int N;
	cin >> N;
	vector<int> input(N, 0);
	for (int i = 0; i < N; i++)
		cin >> input[i];
	if (input.empty())
		return 0;
	int target;
	cin >> target;
	//�ݹ�
	int ans = -1;
	binaryFind(input, target, ans, 0, N - 1);
	cout << "�ݹ�����" << endl;
	cout << ans << endl;
	//�ǵݹ�
	int ans1 = -1;
	int begin = 0;
	int end = N - 1;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (target > input[mid])
			begin = mid + 1;
		else if (target < input[mid])
			end = mid - 1;
		else
			ans1 = mid;
	}
	if (input[begin] == target)
		ans1 = begin;
	cout << "�ǵݹ�����" << endl;
	cout << ans1 << endl;
	return 0;
}