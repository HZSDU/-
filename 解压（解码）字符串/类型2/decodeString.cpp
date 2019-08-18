#include<iostream>
#include<vector>
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
		if (input[i] == '[')
		{
			i++;
			string numStr = "";
			while (input[i] != '|')
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
		else if (input[i] >= 'A' && input[i] <= 'Z')
		{
			ans += input[i++];
		}
		else if (input[i] == ']')
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
	string temp = "HG[3|B[2|CA]]F";
	string out = decodeString(temp);
	cout << out << endl;
	return 0;
}