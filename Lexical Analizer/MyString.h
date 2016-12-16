#pragma once
#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 80;
class MyString
{
private:
	char s[MAX + 1];
public:
	MyString(const char *s = "");
	MyString(char ch);
	MyString(const MyString & aString);
	~MyString();
	MyString & operator =(const char *s);
	MyString & operator =(char ch);
	MyString & operator =(const MyString & aString);
	void setS(const char*s);
	const char * getS()const;
	MyString operator +(const char * s)const;
	MyString operator +(char ch)const;
	MyString operator +(const MyString & aStrin)const;
	friend MyString operator +(const char *s, const MyString & aString);
	friend MyString operator +(char ch, const MyString & aString);
	bool operator ==(const char*s)const;
	bool operator ==(const MyString & aString)const;
	friend bool operator ==(const char *s,const MyString & aString);
	bool operator !=(const char*s)const;
	bool operator !=(const MyString & aString)const;
	friend bool operator !=(const char *s, const MyString & aString);
	bool operator >(const char*s)const;
	bool operator >(const MyString & aString)const;
	friend bool operator >(const char *s, const MyString & aString);
	bool operator <(const char*s)const;
	bool operator <(const MyString & aString)const;
	friend bool operator <(const char *s, const MyString & aString);
	const char & operator[](int index)const;
	char & operator [](int index);
	friend istream & operator >> (istream &in, MyString & aString);
	friend ostream & operator << (ostream &out, const MyString & aString);
	MyString trimLead()const;
	MyString trimEnd()const;
	MyString trimAll()const;
	MyString toUpper()const;
	MyString toLower()const;
	MyString createSub(int from, int to)const;
	int len()const;
	bool isEmpty()const;
	MyString reverse()const;
	int indexOf(char ch)const;
	int indexOfLast(char ch)const;
	bool include(char ch)const;
	int frequency(char ch)const;
	bool representAnUnsignInteger()const;
	bool representAnInteger()const;
	bool representAReal()const;
	static int MaxLen();
	MyString & operator +=(const MyString & aString);
	MyString & operator +=(const char * s);
	MyString & operator +=(char ch);
	MyString & operator ++();
	MyString operator ++(int);
	MyString & operator --();
	MyString operator --(int);
};

