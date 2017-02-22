/******************************************************************************
 *   Copyright (C), 2017, X Co., Ltd.
 *
 *    Filename: trim.cc
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   2017年02月21日 21时32分36秒
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   2017年02月21日                  build this moudle  
 *****************************************************************************/
#include <iostream>

using namespace std;

bool is_space(char c)
{
	if ( (c == ' ') || (c == '\t') )
		return true;

	return false;
}

void 
Trim(string & str)  
{  
	int i;
	int start_pos;
	int end_pos;  

	if ( str.empty() ) 
	{  
		return;  
	}  

	/* find first not blank */
	for ( i = 0; i < str.size(); ++i ) 
	{  
		if ( !is_space(str[i]) ) 
		{  
			break;  
		}  
	}  

	if ( i == str.size() ) 
	{ 
		// all blank, has got last place.
		str = "";  
		return;  
	}  
	start_pos = i;  

	/* find last not blank */
	for ( i = str.size() - 1; i >= 0; --i ) 
	{  
		if ( !is_space(str[i]) ) 
		{  
			break;  
		}  
	}  
	end_pos = i;  

	str = str.substr(start_pos, end_pos - start_pos + 1);  
}  

int
main()
{
	string ss = " 123 45=  6 7 78 ";
	Trim(ss);

	cout << "ss:[" << ss << "]" << endl;

	return 0;
}
