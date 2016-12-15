/******************************************************************************
 *   Copyright (C), 2016, X Co., Ltd.
 *
 *    Filename: test_override.cc
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   12/13/16 17:07:30
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   12/13/16                  build this moudle  
 *****************************************************************************/
#include "headers.h"

class complex 
{
private:
	int Dollar;
	int Cents;

public:
	complex()
	{
		Dollar = 0;
		Cents = 0;
	}

	complex(int d, int c)
	{
		Dollar = d;
		Cents = c;
	}

	/* type one */
//	friend std::ostream &operator<<(std::ostream &out,const complex &c)
//	{
//		out << "The dollar = " << c.Dollar << " and The Cents = " << c.Cents<<endl;
//		return out;
//	}

	/* type two */
	friend std::ostream &operator<<(std::ostream &out,const complex &c);

	complex& operator =(const complex &c);
	complex& operator -(const complex &c);

	complex operator +(const complex &c);
	complex operator *(const complex &c);
	complex operator /(const complex &c);
};

/* type two */
std::ostream& operator<<(std::ostream &out,const complex &c)
{
	out << "The dollar = " << c.Dollar << " and The Cents = " << c.Cents<<endl;
	return out;
}

complex& complex::operator=(const complex& c)
{
	Dollar = c.Dollar;
	Cents = c.Cents;
	return *this;
}

complex& complex::operator-(const complex& c)
{
	Dollar = Dollar - c.Dollar;
	Cents = Cents - c.Cents;
	return *this;
}

inline complex complex::operator +(const complex &c)
{
	return complex(Dollar + c.Dollar, Cents + c.Cents);
}

inline complex complex::operator *(const complex& c)
{
	return complex(Dollar * c.Dollar, Cents * c.Cents);
}

inline complex complex::operator/(const complex& c)
{
	return complex((int)(Dollar / c.Dollar), (int)(Cents / c.Cents));
}

template <typename T>
void Displayc(T c)
{
	cout << c << endl;
}

int 
main()
{
	complex c1(10, 5);
	Displayc(c1);

	complex c2(2, 2);
	complex c3;
//	c2 = c1;
	c3 = (c1 + c2);
	Displayc(c3);

	return 0;
}
