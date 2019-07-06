/*
* (C) Copyright 1999-2019 by amir mohseninia All Rights Reserved.
*	github page : github.com/amircloner
*	website : www.jimzy.ir
*/

#include "BigInteger.h"

/*---------------------------------constructors------------------------------*/

BigInteger::BigInteger(string number) :
	_numberString(number)
{
}

BigInteger::BigInteger(long long number) : _numberString(to_string(number))
{
}

BigInteger::BigInteger()
{
	_numberString = "0";
}

BigInteger::~BigInteger() {

}

/*-----------------------------set-get functions----------------------------- */

string BigInteger::get_BigInteger() {
	return this->_numberString;
}

BigInteger BigInteger::set_BigInteger(const string &new_string) {
	this->_numberString = new_string;
	return *this;
}

/*------------------------------digits-odd-even------------------------------ */

unsigned long long int BigInteger::digits() {
	return this->_numberString.length();
}

bool BigInteger::isEven() {
	BigInteger temp = this->_numberString;

	if (temp._numberString[temp._numberString.length() - 1] % 2 == 0)
		// array start from x[0] to ...
		return true;
	else
		return false;

}

bool BigInteger::isOdd() {
	BigInteger temp = this->_numberString;

	if (temp._numberString[temp._numberString.length() - 1] % 2 != 0)
		// array start from x[0] to ...
		return true;
	else
		return false;
}

/*---------------------------------sum------------------------------*/

BigInteger BigInteger::sum(BigInteger that) {

	BigInteger b1("0");
	BigInteger b2("0");

	if (that > *this)
		b1 = that;
	else
		b1 = *this;

	if (that > *this)
		b2 = *this;
	else
		b2 = that;

	/*
	string a = "-22";
	string b = "-44";

	if (a > b)
	cout << a << endl;
	else
	cout << b << endl;

	output : -44
	kocheck ya bozorg bodan ra bedon alamat manfi hesab mikonad
	*/

	/*
	for example 5 , 10 first change to 05 ,10
	then sum=5+0; then result=sum;
	then sum=1+0; then insert sum to first of result;
	*/
	string result;

	int carry = 0;
	int diffrent_size_of_numbers = int(b1._numberString.size() - b2._numberString.size());

	for (int i = 0; i < diffrent_size_of_numbers; ++i) {
		b2._numberString.insert(b2._numberString.begin(), '0');
	}

	for (int i = int(b1._numberString.size() - 1); i >= 0; --i) { //>= we set size-1
																  //XXXXXXXX -> tabdil az akhar be aval
		int sum = (b1._numberString[i] - '0') + (b2._numberString[i] - '0') + carry;
		// to care that not sum ascii code;
		//'9' - '0' // 9
		carry = 0;
		if (sum <= 9 || i == 0) {
			result.insert(0, to_string(sum));
		}
		else {
			result.insert(0, to_string(sum % 10));
			carry = 1;
		}
	}

	return BigInteger(result);
}

/*-----------------------------sum operators--------------------------*/

BigInteger operator+(BigInteger b1, const BigInteger &b2) {
	return b1.sum(b2);
}

BigInteger operator+(BigInteger b1, const string &b2) {
	return b1.sum(BigInteger(b2));
}

BigInteger& BigInteger::operator+=(const BigInteger &that) {
	*this = *this + that;
	return *this;
}

BigInteger& BigInteger::operator+=(const string &that) {
	*this = *this + that;
	return *this;
}


/*---------------------------------subtract------------------------------*/

BigInteger BigInteger::subtract(BigInteger that) {
	BigInteger b1 = *this, b2 = that;

	string result;

	int n = 0, p = 0;

	bool SumDigitWithTen = false;

	int diffrent_size_of_numbers = b1._numberString.size() - b2._numberString.size();

	if (diffrent_size_of_numbers > 0) {
		for (unsigned long i = 0; i < diffrent_size_of_numbers; ++i) {
			b2._numberString.insert(b2._numberString.begin(), '0');
		}
	}

	int i = int(b1._numberString.size() - 1);

	for (int j = int(b2._numberString.size() - 1); j >= 0; --j) {
		if (((b1._numberString[i] - '0') < (b2._numberString[j] - '0')) && i > 0) {

			//n = char((b1._numberString[i] - '0') + 10);
			n = int((b1._numberString[i] - '0') + 10);
			if (j > 0 || b1._numberString[i - 1] != '0') {
				p = int((b1._numberString[i - 1] - '0') - 1);
				//p = char((b1._numberString[i - 1] - '0') - 1);
				if (p == -1) {
					p = 9;
					SumDigitWithTen = true;
				}
			}
			if (SumDigitWithTen) {
				int index = i - 1;
				for (int a = i - 1; (b1._numberString[a] - '0') == 0; --a) {
					b1._numberString[a] = (char)(p + '0');//to change int to char
					--index;
				}
				int t = (b1._numberString[index] - '0') - 1;
				b1._numberString[index] = (char)(t + '0');
			}
			b1._numberString[i - 1] = (char)(p + '0');
			SumDigitWithTen = false;
		}

		string TempString;

		if (((b1._numberString[i] - '0') == (b2._numberString[j] - '0'))) {

			TempString = "0";
		}
		else {
			if (n <= 0) {
				TempString = to_string((b1._numberString[i] - '0') - (b2._numberString[j] - '0'));
			}
			else {
				TempString = to_string(n - (b2._numberString[j] - '0'));
			}
		}

		result.insert(0, TempString);
		--i;
		n = 0;
	}

	//In the case of all 0's, we only want to return one of them
	if (result.find_first_not_of('0') != string::npos) {
		result = result.erase(0, result.find_first_not_of('0'));
	}
	else {
		result = "0";
	}
	return BigInteger(result);
}

/*-------------------------subtract operators-------------------------*/

BigInteger operator-(BigInteger b1, const BigInteger &b2) {
	return b1.subtract(b2);
}

BigInteger operator-(BigInteger b1, const string &b2) {
	return b1.subtract(BigInteger(b2));
}
BigInteger& BigInteger::operator-=(const BigInteger &that) {
	*this = *this - that;
	return *this;
}

BigInteger& BigInteger::operator-=(const string &that) {
	*this = *this - that;
	return *this;
}

/*---------------------------------multiply------------------------------*/

BigInteger BigInteger::multiply(BigInteger that) {


	BigInteger b1("0");
	BigInteger b2("0");

	if (that > *this)
		b1 = that;
	else
		b1 = *this;

	if (that > *this)
		b2 = *this;
	else
		b2 = that;

	if (b1 == "0" || b2 == "0")
		return "0";

	int carry = 0;
	int zeroCounter = 0;
	BigInteger result = "0";

	int diffrent_size_of_numbers = b1._numberString.size() - b2._numberString.size();

	for (unsigned int i = 0; i < diffrent_size_of_numbers; ++i) {
		b2._numberString.insert(b2._numberString.begin(), '0');
	}

	for (long long int i = (b2._numberString.size() - 1); i >= 0; --i) {

		string temp_mul;

		for (long long int j = int(b1._numberString.size() - 1); j >= 0; --j) {
			int val = ((b2._numberString[i] - '0') * (b1._numberString[j] - '0')) + carry;
			carry = 0;
			if (val > 9 && j != 0) {
				carry = val / 10;
				temp_mul.insert(0, to_string(val % 10));
			}
			else {
				temp_mul.insert(0, to_string(val));
			}
		}
		/* dahgan va sadgan ra dar jam moshakhas mikonad
		1 2
		*1 2
		------
		2 4
		1 2 0
		*/
		if (zeroCounter > 0) {
			for (int x = 0; x < zeroCounter; ++x) {
				temp_mul.push_back('0');
			}
		}

		++zeroCounter;

		result += BigInteger(temp_mul);
	}
	/*
	1 2
	* 0 2
	------
	0 2 4
	0 0 0
	--------
	0 2 4
	*/
	if (result._numberString.find_first_not_of('0') != string::npos) {
		result.set_BigInteger(result._numberString.erase(0, result._numberString.find_first_not_of('0')));
	}
	else {
		//In the case of all 0's, we only want to return one of them
		result.set_BigInteger("0");
	}

	return result;
}

/*--------------------------multiply operators-------------------------*/

BigInteger operator*(BigInteger b1, const BigInteger &b2) {
	return b1.multiply(b2);
}

BigInteger operator*(BigInteger b1, const string &b2) {
	return b1.multiply(BigInteger(b2));
}

BigInteger& BigInteger::operator*=(const BigInteger &that) {
	*this = *this * that;
	return *this;
}

BigInteger& BigInteger::operator*=(const string &that) {
	*this = *this * that;
	return *this;
}

/*---------------------------------divide------------------------------*/

BigInteger BigInteger::divide(BigInteger that) {

	if (that == "0") {
		cout << "You cannot divide by 0!" << endl;
	}

	BigInteger b1 = *this, b2 = that;

	BigInteger quotient = "0";
	while (b1 >= b2) {
		b1 = b1 - b2;
		++quotient;
	}

	return quotient;
}

/*---------------------------divide operators------------------------*/

BigInteger operator/(BigInteger b1, const BigInteger &b2) {
	return b1.divide(b2);
}

BigInteger operator/(BigInteger b1, const string &b2) {
	return b1.divide(BigInteger(b2));
}
BigInteger& BigInteger::operator/=(const BigInteger &that) {
	*this = *this / that;
	return *this;
}

BigInteger& BigInteger::operator/=(const string &that) {
	*this = *this / that;
	return *this;
}

/*---------------------------------reminder------------------------------*/

BigInteger BigInteger::remainder(BigInteger that)
{
	if (that == "0") {
		cout << "You cannot compute remainder by 0!" << endl;
	}

	BigInteger b1 = *this, b2 = that;

	while (b1 >= b2) {
		b1 = b1 - b2;
	}

	return b1;
}

/*--------------------------reminder operators----------------------*/

BigInteger operator%(BigInteger b1, const BigInteger & b2)
{
	return b1.remainder(b2);
}

BigInteger operator%(BigInteger b1, const string & b2)
{
	return b1.remainder(BigInteger(b2));
}
BigInteger & BigInteger::operator%=(const BigInteger & that)
{
	*this = *this % that;
	return *this;
}

BigInteger & BigInteger::operator%=(const string & that)
{
	*this = *this % that;
	return *this;
}


/*--------------------------conditional functions----------------------*/

bool BigInteger::equals(const BigInteger &that) {
	if (this->_numberString == that._numberString)
		return true;
	else
		return false;
}

bool BigInteger::equals(const string &that) {
	if (this->_numberString == that)
		return true;
	else
		return false;
	//return this->_numberString == that;	//best
}

bool BigInteger::NOTequals(const BigInteger & that)
{
	if (this->_numberString == that._numberString)
		return false;
	else
		return true;
}

bool BigInteger::NOTequals(const string & that)
{
	if (this->_numberString == that)
		return false;
	else
		return true;
}

/*--------------------------conditional operators----------------------*/

bool operator==(BigInteger b1, const BigInteger &b2) {
	return b1.equals(b2);
}

bool operator==(BigInteger b1, const string &b2) {
	return b1.equals(b2);
}

bool operator!=(BigInteger b1, const BigInteger & b2)
{
	return b1.NOTequals(b2);
}

bool operator!=(BigInteger b1, const string & b2)
{
	return b1.NOTequals(b2);
}

bool operator>(BigInteger b1, const BigInteger &b2) {

	auto c = BigInteger(b2);

	if (b1 == c) {
		return false;
	}
	if (b1._numberString.size() > c._numberString.size()) {
		return true;
	}
	else if (c._numberString.size() > b1._numberString.size()) {
		return false;
	}
	else {
		for (unsigned int i = 0; i < b1._numberString.size(); ++i) {
			if (b1[i] == (unsigned int)(c._numberString[i] - '0')) {
				continue;
			}
			return b1[i] >(unsigned int)(c._numberString[i] - '0');
		}
	}
	return false;
}

bool operator<(BigInteger b1, const BigInteger &b2) {
	if (!(b1 == b2) && !(b1 > b2))
		return true;
	else
		return false;
}

bool operator>=(BigInteger b1, const BigInteger &b2) {
	if (b1 > b2 || b1 == b2)
		return true;
	else
		return false;
}

bool operator<=(BigInteger b1, const BigInteger &b2) {
	if (b1 < b2 || b1 == b2)
		return true;
	else
		return false;
}

/*--------------------------index operators----------------------*/

unsigned int BigInteger::operator[](int index) {
	if (this->_numberString[index] == '-') {
		cout << "You cannot get the negative sign from the number" << endl;
	}
	return (unsigned int)(this->_numberString[index] - '0');
}

/*------------------------------set operators--------------------- */

BigInteger& BigInteger::operator=(const BigInteger &that) {
	this->_numberString = that._numberString;
	return *this;
}

BigInteger& BigInteger::operator=(const string &that) {
	this->_numberString = that;
	return *this;
}

/*------------------------------ostream operator--------------------- */

ostream &operator<<(ostream &OutputStream, const BigInteger &Number) {
	OutputStream << Number._numberString;
	return OutputStream;
}

/*----------------------------Postfix & Prefix----------------------- */

BigInteger& BigInteger::operator++() {
	*this += BigInteger("1");
	return *this;
}

BigInteger& BigInteger::operator--() {
	*this -= BigInteger("1");
	return *this;
}

BigInteger BigInteger::operator++(int) {
	BigInteger tmp(this->_numberString);
	++(*this);
	return tmp;
}

BigInteger BigInteger::operator--(int) {
	BigInteger tmp(this->_numberString);
	--(*this);
	return tmp;
}


/*----------------------------main----------------------- */

int main()
{

	/*sum*/
	cout << BigInteger("50") + BigInteger("20") << endl;
	cout << BigInteger(50) + BigInteger(20) << endl;
	cout << BigInteger(50) + "20" << endl;
	cout << BigInteger("50") + "20" << endl;

	/*subtract*/

	cout << BigInteger("50") - BigInteger("20") << endl;
	cout << BigInteger(50) - BigInteger(20) << endl;
	cout << BigInteger(50) - "20" << endl;
	cout << BigInteger("50") - "20" << endl;

	/*multiply*/

	cout << BigInteger("50") * BigInteger("20") << endl;
	cout << BigInteger(50) * BigInteger(20) << endl;
	cout << BigInteger(50) * "20" << endl;
	cout << BigInteger("50") * "20" << endl;

	/*divide*/

	cout << BigInteger("50") / BigInteger("20") << endl;
	cout << BigInteger(50) / BigInteger(20) << endl;
	cout << BigInteger(50) / "20" << endl;
	cout << BigInteger("50") / "20" << endl;

	/*remainder*/

	cout << BigInteger("50") / BigInteger("20") << endl;
	cout << BigInteger(50) / BigInteger(20) << endl;
	cout << BigInteger(50) / "20" << endl;
	cout << BigInteger("50") / "20" << endl;

	/*digits*/

	BigInteger tmp("123456");
	cout << tmp.digits() << endl;

	/*isEven*/

	BigInteger temp1("123456");
	if (temp1.isEven())
		cout << "even" << endl;
	else
		cout << "odd" << endl;

	/*isOdd*/

	BigInteger temp2("123457");
	if (temp2.isOdd())
		cout << "odd" << endl;
	else
		cout << "even" << endl;

	/*index*/

	cout << BigInteger("123456")[3] << endl;

	/*conditional operator*/

	BigInteger tmp1("123456");
	BigInteger tmp2("654321");

	if (tmp1 > tmp2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (tmp1 >= tmp2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (tmp1 < tmp2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (tmp1 <= tmp2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (tmp1 == tmp2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (tmp1 != tmp2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	/*Prefix*/

	cout << ++BigInteger("85") << endl;
	cout << --BigInteger("85") << endl;

	/*Postfix*/

	cout << BigInteger("85")++ << endl;
	cout << BigInteger("85")++ << endl;

	/*set*/

	BigInteger b("85");
	BigInteger c = b;
	cout << c << endl;

	BigInteger temp3("5");
	BigInteger temp4("2");
	BigInteger temp5  = temp3 /= temp4;
	cout << temp5 << endl;

	return 0;
}