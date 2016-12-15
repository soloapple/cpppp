/******************************************************************************
 *   Copyright (C), 2016, X Co., Ltd.
 *
 *    Filename: test_friend.cc
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   12/13/16 17:43:35
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   12/13/16                  build this moudle  
 *****************************************************************************/
#include <iostream> 

template<typename T>
class Foo 
{ 
	public:    
		Foo(const T& val) : data(val) {} 

	private:    
		T data;     

	friend std::ostream& operator<<(std::ostream& os, const Foo& obj)    
	{        
		return os << obj.data;    
	}
}; 

int main()
{    
	Foo<double> obj(1.23);    
	std::cout << obj << '\n';

	return 0;
}
