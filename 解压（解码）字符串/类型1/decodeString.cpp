#include<iostream>
#include<string>
using namespace std;

string decode(string input, int &end)
{
	if (input.size() == 0)
		return "";
	int i = 0;
	string ans = "";
	while (i < input.size())
	{
		if (input[i] >= '1' && input[i] <= '9')//如果是数字，那么需要继续深挖里面的子串
		{
			string numStr = "";
			while (input[i] != '[')
			{
				numStr += input[i++];
			}
			int repeatNum = stoi(numStr);
			int e = 0;
			string temp = decode(input.substr(++i), e);
			while (repeatNum)
			{
				ans += temp;
				repeatNum--;
			}
			i += e;
		}
		else if (input[i] >= 'a' && input[i] <= 'z')//如果是字母，字节加到要返回的字符串中
		{
			ans += input[i++];
		}
		else if (input[i] == ']')//如果是‘]’,那么返回，同时更新在父调用函数中i要增加的个数
		{
			end = ++i;
			break;
		}
	}
	return ans;
}
string decodeString(string input)
{
	int end = 0;//记录在原字符串中的要增加的位置
	return decode(input, end);
}
int main()
{
	string temp = "abc3[a2[b]]df";//测试用例
	string out = decodeString(temp);
	cout << out << endl;
	return 0;
}