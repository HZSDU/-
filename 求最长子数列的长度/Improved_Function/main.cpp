#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//二分查找：寻找排好序的sortVector数组中第一个大于等于target的索引，若有等于的，isEqual为真
int binarySearch(vector<int> sortedVector, int target, bool &isEqual)
{
	isEqual = false;
	int begin = 0, end = sortedVector.size();
	while (begin != end)
	{
		int mid = begin + (end - begin) / 2;
		if (target > sortedVector[mid])
			begin = mid + 1;
		else if (target == sortedVector[mid])
		{
			isEqual = true;
			return mid;
		}
		else
			end = mid;
	}
	return begin;
}
//找最大长度，时间复杂度O(nlogn)
//参考文章：https://blog.csdn.net/lw_power/article/details/80758674
int lengthOfLIS(vector<int>& inputArray) 
{
	vector<int> temp;
	if (inputArray.empty())
		return 0;
	temp.push_back(inputArray[0]);
	for (int i = 1; i < inputArray.size(); i++)
	{

		if (inputArray[i] > temp[temp.size() - 1])
			temp.push_back(inputArray[i]);
		else if (inputArray[i] < temp[0])
			temp[0] = inputArray[i];
		else if (inputArray[i] > temp[0] && inputArray[i] < temp[temp.size() - 1])
		{
			bool isEqual = false;
			int index = binarySearch(temp, inputArray[i], isEqual);
			if (isEqual)
				continue;
			else
				temp[index] = inputArray[i];
		}
	}
	return temp.size();
}

int main()
{
	vector<int> input;
	int temp;
	//输入一行整数 回车结束输入
	while (cin >> temp)
	{
		input.push_back(temp);
		char a;
		a = getchar();
		if (a == '\n')
			break;
	}
	int ans = lengthOfLIS(input);
	cout << ans << endl;
	return 0;
}