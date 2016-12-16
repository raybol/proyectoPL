#include "MyString.h"

MyString::MyString(const char * s)
{
	(*this) = s;
}

MyString::MyString(char ch)
{
	(*this) = ch;
}

MyString::MyString(const MyString & aString)
{
	(*this) = aString;
}

MyString::~MyString()
{
}

MyString & MyString::operator=(const char * s)
{
	strcpy_s(this->s, MAX + 1, s);
	return(*this);
}

MyString & MyString::operator=(char ch)
{
	(*this) = "";
	(*this) = (*this) + ch;
	return(*this);
}

MyString & MyString::operator=(const MyString & aString)
{
	strcpy_s(this->s, MAX + 1, aString.s);
	return(*this);
}

void MyString::setS(const char * s)
{
	strcpy_s(this->s, MAX + 1, s);
}

const char * MyString::getS() const
{
	return (this->s);
}

MyString MyString::operator+(const char * s) const
{
	MyString r(*this);
	strcat_s(r.s, MAX + 1, s);
	return (r);
}

MyString MyString::operator+(char ch) const
{
	MyString r(*this);
	if ((this->len() + 1) <= MAX) {
		(r.s)[this->len()] = ch;
		(r.s)[this->len()+1] = '0';
	}
	return (r);
}

MyString MyString::operator+(const MyString & aStrin) const
{
	return((*this) + aStrin.s);
}

bool MyString::operator==(const char * s) const
{
	return (strcmp(this->s, s) == 0);
}

bool MyString::operator==(const MyString & aString) const
{
	return (strcmp(this->s, aString.s) == 0);
}

bool MyString::operator!=(const char * s) const
{
	return (strcmp(this->s, s) != 0);
}

bool MyString::operator!=(const MyString & aString) const
{
	return (strcmp(this->s, aString.s) != 0);
}

bool MyString::operator>(const char * s) const
{
	return (strcmp(this->s, s) > 0);
}

bool MyString::operator>(const MyString & aString) const
{
	return (strcmp(this->s, aString.s) > 0);
}

bool MyString::operator<(const char * s) const
{
	return (strcmp(this->s, s) < 0);
}

bool MyString::operator<(const MyString & aString) const
{
	return (strcmp(this->s,aString.s)< 0);
}

const char & MyString::operator[](int index) const
{
	return((this->s)[index]);
}

char & MyString::operator[](int index)
{
	return((this->s)[index]);
}

MyString MyString::trimLead() const
{
	MyString r;
	int i;
	for (i = 0; (this->s)[i] == 't' || (this->s)[i] == ' '; i++);
	for (; i < this->len(); i++)
		r = r + (this->s)[i];
	return(r);

}

MyString MyString::trimEnd() const
{
	MyString r;
	int i;
	for (i = this->len() - 1; (this->s)[i] == 't' || (this->s)[i] == ' '; i--);
	for (; i >= 0; i--)
		r = (this->s)[i] + r;
	return(r);
}

MyString MyString::trimAll() const
{
	MyString r;
	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] != 't' && (this->s)[i] != ' ')
			r = r + (this->s)[i];
	return(r);
}

MyString MyString::toUpper() const
{
	MyString r(*this);
	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] >= 'a' && (this->s)[i] <= 'z')
			(r.s)[i] = (this->s[i] - 32);
	return(r);
}

MyString MyString::toLower() const
{
	return MyString(); MyString r(*this);
	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] >= 'A' && (this->s)[i] <= 'Z')
			(r.s)[i] = (this->s[i] + 32);
	return(r);
}

MyString MyString::createSub(int from, int to) const
{
	MyString r;
	if (from >= 0 && to < this->len())
		for (int i = from; i <= to; i++)
			r = r + (this->s)[i];
	return(r);
}

int MyString::len() const
{
	return (strlen(this->s));
}

bool MyString::isEmpty() const
{
	return(this->len() == 0);
}

MyString MyString::reverse() const
{
	MyString r(*this);
	char ch;
	for (int i=0, j = this->len() - 1; i < j; i++, j--) {
		ch = (r.s)[i];
		(r.s)[i] = (r.s)[j];
		(r.s)[i] = ch;
	}
	return(r);
}

int MyString::indexOf(char ch) const
{
	int index = -1;
	for (int i = 0; (i < this->len()) && (index == -1); i++)
		if ((this->s)[i] == ch)
			index = i;
	return(index);
}

int MyString::indexOfLast(char ch) const
{
	int index = -1;
	for (int i = this->len() - 1; (i >= 0) && (index == -1); i++)
		if ((this->s)[i] == ch)
			index = i;
	return(index);
}

bool MyString::include(char ch) const
{
	bool found = false;
	for (int i = 0; i < this->len() && !found; i++)
		if ((this->s)[i] == ch)
			found = true;
	return(found);
}

int MyString::frequency(char ch) const
{
	int f = 0;
	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] == ch)
			++f;
	return(f);
}

bool MyString::representAnUnsignInteger() const
{
	bool represent = true;
	for (int i = 0; i < this->len() && represent; i++)
		if ((this->s)[i]<'0' || (this->s)[i]>'9')
			represent = false;
	return (represent && this->len()>0);
}

bool MyString::representAnInteger() const
{
	MyString r(*this);
	if ((this->s)[0] == '+' || (this->s)[0] == '-')
		r = this->createSub(1, this->len() - 1);		
	return(r.representAnUnsignInteger());
}

bool MyString::representAReal() const
{
	int point = this->indexOf('.');
	MyString prefix, sufix;
	bool valid;
	if (point != -1)
	{
		prefix = this->createSub(0, point - 1);
		sufix = this->createSub(point + 1, this->len() - 1);
		valid = prefix.representAnInteger() && sufix.representAnUnsignInteger();
	}
	else
		valid = this->representAnInteger();
	return(valid);
}

int MyString::MaxLen()
{
	return (MAX);
}

MyString & MyString::operator+=(const MyString & aString)
{
	return((*this) = (*this) + aString);
}

MyString & MyString::operator+=(const char * s)
{
	return((*this) = (*this) + s);
}

MyString & MyString::operator+=(char ch)
{
	return((*this) = (*this) + ch);
}

MyString & MyString::operator++()
{
	return((*this) = this->toUpper());
}

MyString MyString::operator++(int)
{
	MyString r(*this);
	(*this) = this->toUpper();
	return(r);
}

MyString & MyString::operator--()
{
	return((*this) = this->toLower());
}

MyString MyString::operator--(int)
{
	MyString r(*this);
	(*this) = this->toLower();
	return(r);
}
	
MyString operator+(const char * s, const MyString & aStrin)
{
	return (MyString(s)+aStrin);
}

MyString operator+(char ch, const MyString & aStrin)
{
	return (MyString(ch) + aStrin);
}

bool operator==(const char * s, const MyString & aString)
{
	return (strcmp(s,aString.s) == 0);
}

bool operator!=(const char * s, const MyString & aString)
{
	return (strcmp(s,aString.s) != 0);
}

bool operator>(const char * s, const MyString & aString)
{
	return (strcmp(s,aString.s) > 0);
}

bool operator<(const char * s, const MyString & aString)
{
	return (strcmp(s,aString.s) < 0);
}

istream & operator>>(istream & in, MyString & aString)
{
	char ch;
	aString = "";
	ch = in.get();
	while (ch == '\n')
		ch = in.get();
	while (ch != '\n')
	{
		aString = aString + ch;
		ch = in.get();
	}
	return(in);
}

ostream & operator<<(ostream & out, const MyString & aString)
{
	out << aString.s;
	return(out);
}
