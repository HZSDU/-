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
		if (input[i] >= '1' && input[i] <= '9')//��������֣���ô��Ҫ��������������Ӵ�
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
		else if (input[i] >= 'a' && input[i] <= 'z')//�������ĸ���ֽڼӵ�Ҫ���ص��ַ�����
		{
			ans += input[i++];
		}
		else if (input[i] == ']')//����ǡ�]��,��ô���أ�ͬʱ�����ڸ����ú�����iҪ���ӵĸ���
		{
			end = ++i;
			break;
		}
	}
	return ans;
}
string decodeString(string input)
{
	int end = 0;//��¼��ԭ�ַ����е�Ҫ���ӵ�λ��
	return decode(input, end);
}
int main()
{
	string temp = "abc3[a2[b]]df";//��������
	string out = decodeString(temp);
	cout << out << endl;
	return 0;
}