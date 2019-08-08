#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Number
{
private:
	string num;
	bool isDec;
public:
	Number() {}
	Number(string a) :num(a), isDec(false){}
	vector<string> seg();
	string sumMySelf(Number inputA, Number inputB);
	string sumInt(string inputA, string inputB);
	string sumDec(string intpuA, string inputB);
	~Number() {}
};

vector<string> Number::seg()
{
	vector<string> ans;
	this->isDec = false;
	string intM, decM;//小数和整数部分的字串
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == '.')//是小数
		{
			this->isDec = true;
			intM = num.substr(0, i);
			decM = num.substr(i + 1, num.size() - i - 1);
			ans.push_back(intM);
			ans.push_back(decM);
		}
	}
	if (this->isDec == false)//是整数
		ans.push_back(num);
	return ans;
}

string Number::sumMySelf(Number inputA, Number inputB)
{
	string ans = "";
	//小数整数部分分割
	vector<string> segA = inputA.seg();
	vector<string> segB = inputB.seg();
	//分类计算
	string sum1 = sumInt(segA[0], segB[0]);
	//A 整数 B 小数
	if (inputA.isDec == false && inputB.isDec == true)
	{
		if (sum1[0] == '0')
			sum1 = sum1.substr(1, sum1.size() - 1);
		ans += sum1;
		ans += ".";
		ans += segB[1];
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			if (ans[i] == '0')
				continue;
			else if (ans[i] == '.')
			{
				ans = ans.substr(0, i);
				break;
			}
			else
			{
				ans = ans.substr(0, i + 1);
				break;
			}
		}
	}
	//B 整数 A 小数
	else if (inputA.isDec == true && inputB.isDec == false)
	{
		if (sum1[0] == '0')
			sum1 = sum1.substr(1, sum1.size() - 1);
		ans += sum1;
		ans += ".";
		ans += segA[1];
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			if (ans[i] == '0')
				continue;
			else if (ans[i] == '.')
			{
				ans = ans.substr(0, i);
				break;
			}
			else
			{
				ans = ans.substr(0, i + 1);
				break;
			}
		}
	}
	//A 整数 B 整数
	else if (inputA.isDec == false && inputB.isDec == false)
	{
		if (sum1[0] == '0')
			sum1 = sum1.substr(1, sum1.size() - 1);
		ans += sum1;
	}
	//A 小数 B 小数
	else
	{
		if (sum1[0] == '0')
			sum1 = sum1.substr(1, sum1.size() - 1);
		string sum2 = sumDec(segA[1], segB[1]);
		bool flag = false;
		if (sum2[0] == '1')
		{
			sum1 = sumInt(sum1, "1");
			flag = true;
		}
		if (sum1[0] == '0')
			sum1 = sum1.substr(1, sum1.size() - 1);
		ans += sum1;
		ans += ".";
		if (flag)
			ans += sum2.substr(1, sum2.size() - 1);
		else
			ans += sum2;
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			if (ans[i] == '0')
				continue;
			else if(ans[i] == '.')
			{
				ans = ans.substr(0, i);
				break;
			}
			else
			{
				ans = ans.substr(0, i + 1);
				break;
			}
		}
	}
	return ans;
}

string Number::sumInt(string inputA, string inputB)
{
	string longer = inputA.size() >= inputB.size() ? inputA : inputB;
	string shorter = inputA.size() < inputB.size() ? inputA : inputB;
	if (inputA.size() == inputB.size())
	{
		longer = inputA;
		shorter = inputB;
	}
	int longer_size = longer.size();
	int shorter_size = shorter.size();
	int zero_num = longer_size - shorter_size;
	if (zero_num != 0)
	{
		string zero(zero_num, '0');
		shorter = zero + shorter;
	}
	int temp = 0;
	string ans(longer_size + 1, '0');
	for (int i = longer_size - 1; i >= 0; i--)
	{
		ans[i+1] = (longer[i] - '0' + shorter[i] - '0' + temp) % 10 + '0';
		if ((longer[i] - '0' + shorter[i] - '0' + temp) / 10 == 1)
			temp = 1;
		else
			temp = 0;
	}
	if (temp == 1)
		ans[0] = 1 + '0';
	return ans;
}

string Number::sumDec(string inputA, string inputB)
{
	string longer = inputA.size() >= inputB.size() ? inputA : inputB;
	string shorter = inputA.size() < inputB.size() ? inputA : inputB;
	if (inputA.size() == inputB.size())
	{
		longer = inputA;
		shorter = inputB;
	}
	int longer_size = longer.size();
	int shorter_size = shorter.size();
	int zero_num = longer_size - shorter_size;
	if (zero_num != 0)
	{
		string zero(zero_num, '0');
		shorter = shorter + zero;
	}
	int temp = 0;
	string ans(longer_size + 1, '0');
	for (int i = longer_size - 1; i >= 0; i--)
	{
		ans[i + 1] = (longer[i] - '0' + shorter[i] - '0' + temp) % 10 + '0';
		if ((longer[i] - '0' + shorter[i] - '0' + temp) / 10 == 1)
			temp = 1;
		else
			temp = 0;
	}
	if (temp == 1)
		ans[0] = 1 + '0';
	else
		ans = ans.substr(1, longer_size);
	return ans;
}

int main()
{
	string A, B;
	cin >> A >> B;
	Number str1(A);
	Number str2(B);
	Number fun;
	string output = fun.sumMySelf(str1, str2);
	cout << output << endl;
	return 0;
}
