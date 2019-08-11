#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        vector<int> dp(len,1);
        int ans = 1;
        for(int i = 0;i<len;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
                if(dp[i]>ans) ans = dp[i];
            }
        }
        return ans;
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