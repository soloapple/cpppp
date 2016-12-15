/******************************************************************************
 *   Copyright (C), 2016, X Co., Ltd.
 *
 *    Filename: a.cc
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   12/15/16 15:39:27
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   12/15/16                  build this moudle  
 *****************************************************************************/
#include "headers.h"

class callwitch
{
	string name ;
	static int objcount;

public :

	callwitch(const string& na = "") : name(na) { 
		objcount ++;
		print("callwitch(const string&)"); 
	};

	~callwitch(){
		objcount --;
		print("~callwitch()");    
	} 

	callwitch(const callwitch& obj):name(obj.name) { 
		name = "copy of " + name;
		objcount ++;
		print("copy constructor"); 
	};

	callwitch& operator=(callwitch& obj){
		print("copy assignment"); 
	}

	void print(const string& msg = "")const {
		if ( msg.size() !=0 )
			cout << msg << endl ;
		cout << '\t' << name << ": " << "objcount = " << objcount << endl;
	}
};

int callwitch::objcount = 0;
callwitch f(callwitch obj) 
{ 
	cout << "returning from f()" << endl;
	return obj ;
}

int main(int argc, char *argv[])
{
	callwitch c1("c1");
puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  1");
	callwitch c2 = c1; //copy constructor called。因为此时c2还未被初始化成为对象(即还未构造出来)，无法调用copy assignment函数！
puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  2");
	callwitch c4;
puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  3");
	c4 = c1;               //copy assignment called
puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  4");
	c2.print("call f()");
puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  5");
	callwitch c3 = f(c1);
puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  6");
	cout << "call f(),no need return value" << endl;
puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  7");
	f(c1);
//	system("PAUSE");
	return EXIT_SUCCESS;
}
