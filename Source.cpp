#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int casttt(char c)
{
	int ret;
	ret = (int)c-48;
	return ret;
}
class anycast
{
public:
	anycast(string);
	string get_raw()const;
	void set_raw(string);
	string to_string()const;
	long int to_integer()const;
	float to_float()const;
	void cast(string);
private:
	string raw;
};
anycast::anycast(string s)
{
	this->raw = s;
}
string anycast::get_raw()const
{
	return raw;
}
void anycast::set_raw(string s)
{
	this->raw = s;
}string anycast::to_string()const
{
	string ret;
	for (int i = 0; i < this->raw.size(); i++)
	{
		if ((raw.at(i) <= 'z'&&raw.at(i) >= 'a') || (raw.at(i) <= 'Z' && raw.at(i) >= 'A'))
			ret += raw.at(i);
	}
	return ret;
}
long int anycast::to_integer()const
{
	string sret;
	int* aret;
	long int ret=0;
	int sharp_count=0;
	int dot_pos;
	int sharp_pos;
	for (int i = 0; i < this->raw.size(); i++)
	{
		if (raw.at(i) == '#')
		{
			sharp_count++;
		}
		if (raw.at(i) == '.')
		{
			dot_pos = i;
			break;
		}
	}

		for (int i = dot_pos; i < raw.size(); i++)
		{
			if (raw.at(i) == '#')
			{
				sharp_pos = i;
				break;
			}
		}
		for (int i = sharp_pos; i < raw.size(); i++)
		{
			if (raw.at(i) <= '9'&&raw.at(i) >= '0')
			{
				sret += raw.at(i);
			}
		}
		aret = new int(sret.size());
		for (int i = 0; i < sret.size(); i++)
		{
			aret[i] = casttt(sret.at(i));
		}
		for (int i = sret.size()-1; i >=0; i--)
		{
			ret += (aret[i] * pow(10, sret.size() - i-1));
		}
	return ret;
}
int main()
{
	string in;
	getline(cin, in);
	anycast a(in);
	cout << a.to_integer();
	return 0;
}

.