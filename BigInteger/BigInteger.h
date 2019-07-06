/*
* (C) Copyright 1999-2019 by amir mohseninia All Rights Reserved.
* visit my github page : github.com/amircloner
* website : www.jimzy.ir
*/

#pragma once

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BigInteger {
public:

	/*---------------------------------constructors------------------------------*/

	BigInteger(string number);
	BigInteger(long long number);
	BigInteger();
	~BigInteger();

	/*-----------------------------------functions--------------------------------*/

	BigInteger sum(BigInteger that);
	BigInteger subtract(BigInteger that);
	BigInteger multiply(BigInteger that);
	BigInteger divide(BigInteger that);
	BigInteger remainder(BigInteger that);

	string get_BigInteger();
	BigInteger set_BigInteger(const string &new_string);

	unsigned long long int digits();

	/*----------------------boolean functions-----------------*/

	bool equals(const BigInteger &that);
	bool equals(const string &that);

	bool NOTequals(const BigInteger &that);
	bool NOTequals(const string &that);

	bool isEven();
	bool isOdd();

	/*-----------------------operators-------------------------*/

	friend ostream &operator<<(ostream &OutputStream, const BigInteger &Number);

	friend BigInteger operator+(BigInteger b1, const BigInteger &b2);
	friend BigInteger operator+(BigInteger b1, const string &b2);

	friend BigInteger operator-(BigInteger b1, const BigInteger &b2);
	friend BigInteger operator-(BigInteger b1, const string &b2);

	friend BigInteger operator*(BigInteger b1, const BigInteger &b2);
	friend BigInteger operator*(BigInteger b1, const string &b2);

	friend BigInteger operator/(BigInteger b1, const BigInteger &b2);
	friend BigInteger operator/(BigInteger b1, const string &b2);

	friend BigInteger operator%(BigInteger b1, const BigInteger &b2);
	friend BigInteger operator%(BigInteger b1, const string &b2);

	/*--------------------boolean operators---------------------*/

	friend bool operator==(BigInteger b1, const BigInteger &b2);
	friend bool operator==(BigInteger b1, const string &b2);

	friend bool operator!=(BigInteger b1, const BigInteger &b2);
	friend bool operator!=(BigInteger b1, const string &b2);

	friend bool operator>(BigInteger b1, const BigInteger &b2);

	friend bool operator<(BigInteger b1, const BigInteger &b2);

	friend bool operator>=(BigInteger b1, const BigInteger &b2);

	friend bool operator<=(BigInteger b1, const BigInteger &b2);

	BigInteger& operator=(const BigInteger &that);
	BigInteger& operator=(const string &that);

	BigInteger& operator+=(const BigInteger &that);
	BigInteger& operator+=(const string &that);

	BigInteger& operator-=(const BigInteger &that);
	BigInteger& operator-=(const string &that);

	BigInteger& operator*=(const BigInteger &that);
	BigInteger& operator*=(const string &that);

	BigInteger& operator/=(const BigInteger &that);
	BigInteger& operator/=(const string &that);

	//a %= b;
	//a = a % b;
	BigInteger& operator%=(const BigInteger &that);
	BigInteger& operator%=(const string &that);

	BigInteger& operator++();

	BigInteger& operator--();
	/*
	BigInteger operator++(int);

	BigInteger operator--(int);
	*/
	BigInteger operator++(int);

	BigInteger operator--(int);

	unsigned int operator[](int index);

private:

	string _numberString;

};

#endif