/******************************************************************************
 *   Copyright (C), 2017, X Co., Ltd.
 *
 *    Filename: GetConfig.cc
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   2017年02月21日 21时39分52秒
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   2017年02月21日                  build this moudle  
 *****************************************************************************/
#include "get_conf.h"  
#include <fstream>  
#include <iostream>  
  
using namespace std;  
  
bool 
is_space(char c)  
{  
    if ( (c == ' ') || (c == '\t') )  
        return true;  

    return false;  
}  
  
void 
trim(string & str)  
{  
	unsigned int i;
	int start_pos;
	int end_pos;

    if ( str.empty() ) 
	{  
        return;  
    }  

	/* find first not blank char */
    for ( i = 0; i < str.size(); ++i ) 
	{  
        if ( !is_space(str[i]) ) 
		{  
            break;  
        }  
    }  

    if ( i == str.size() ) 
	{ 
		/* all blank, has got to last of the str. */
        str = "";  
        return;  
    }  
    start_pos = i;  

	/* find last not blank char */
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
  
bool 
analyse_line(const string & line, string & key, string & value)  
{  
	int start_pos = 0;
	int end_pos = line.size() - 1;
	int pos;

    if ( line.empty() )  
        return false;  

    if ( (pos = line.find(COMMENT_CHAR)) != -1) 
	{  
        if ( 0 == pos ) 
		{ 
			/* first char is '#'. */
            return false;  
        }  

		/* '#' is in the middle. */
        end_pos = pos - 1;  
    }  

	/* cut comments from middle of the line */
    string new_line = line.substr(start_pos, start_pos + 1 - end_pos);

	cout << "new line:" << new_line << endl;
  
	/* no '=' in line */
    if ( (pos = new_line.find('=')) == -1 )  
	{
		cout << "has not find =" << endl;
        return false; 
	}
  
	/* get key, value, and trim it. */
    key = new_line.substr(0, pos);  
    value = new_line.substr(pos + 1, end_pos + 1 - (pos + 1));  

  
    trim(key);  
    if ( key.empty() ) 
	{  
        return false;  
    }  

    trim(value);  

	cout << key << ":" << value << endl;

    return true;  
}  
  
bool 
read_config(const string & filename, map<string, string> & m)  
{  
    m.clear();  
    ifstream infile(filename.c_str());  
    if ( !infile ) 
	{  
        cout << "file open error" << endl;  
        return false;  
    }  

    string line, key, value;  
    while ( getline(infile, line) ) 
	{  
        if ( analyse_line(line, key, value) ) 
		{  
            m[key] = value;  
        }  
    }  

    infile.close();  
    return true;  
}  
  
  
void 
print_config(const map<string, string> & m)  
{  
    map<string, string>::const_iterator mite = m.begin();  
    for ( ; mite != m.end(); ++mite ) 
	{  
        cout << mite->first << "=" << mite->second << endl;  
    }  
}  
  
int 
main(int argc, char **argv)  
{  
	if ( argc != 2 )
	{
		cout << "Usage: " << argv[0] << " config_file" << endl;
		return -1;
	}

	string m_sPath = argv[1];
//    string m_sPath = "./LandClient.conf";  
    map<string,string> m_mapConfig;  
    read_config(m_sPath,m_mapConfig);  
//    print_config(m_mapConfig);  
    return 0;  
}  


