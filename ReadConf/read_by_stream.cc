/***************************************************************************************
 *   Copyright (C), 2016, X Co., Ltd.
 *
 *    Filename: read_by_stream.cc
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   11/11/16 06:50:01
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   11/11/16                  build this moudle  
 ***************************************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const char democonf[] = "./read_by_stream.conf";
//const char democonf[] = "./get_conf.conf";
const string remote = "remote";

string & ltrim(string &s)
{
    s.erase(0,s.find_first_not_of(" "));  
	return s;
}

string & rtrim(string &s)
{
    s.erase(s.find_last_not_of(" ") + 1);  
	return s;
}

string & trim(string &s)
{
	rtrim(s);
	ltrim(s);

	return s;
}

struct line_pos
{
	size_t start;
	size_t end;

	int n;
};

struct line_pair
{
	string key;
	string value;	
};

/* 
 * Line Style:
 *		remote=local1,local3,local5 (stand style) 
 *		remote = local1, local3, local5 (attach blank) 
 */
int
parse_line(const string & line)
{
	char *p_fac;
	struct line_pos pos;
	struct line_pair pair;

	pos.start = 0;
	pos.end = line.size() - 1;

	if ( (pos.n = line.find('#')) != -1 )	
	{
		if ( pos.n == 0 )
		{
			cout << "comment line:" << line << endl;
			return -1;
		}

		pos.end = pos.n - 1;
	}

	string new_line = line.substr(pos.start, pos.start + 1 - pos.end);

	/* no '=' in line */
    if ( (pos.n = new_line.find('=')) == -1 )  
	{
		cout << "has not find =" << endl;
        return false; 
	}

	pair.key = new_line.substr(0, pos.n);
	pair.value = new_line.substr(pos.n + 1, pos.end - (pos.n + 1) + 1);

//	cout << "key=[" << pair.key << "] value=[" << pair.value << "]" << endl;

	trim(pair.key);
	if ( pair.key.empty() )
	{
		cout << "key is empty" << endl;
		return false;
	}

	trim(pair.value);

//	cout << "key=[" << pair.key << "] value=[" << pair.value << "]" << endl;

	/* single parse flag remote */
	if ( pair.key == remote ) 
	{
		stringstream ss_set(pair.value);
		string sub_fac;

		while ( getline(ss_set, sub_fac, ',') )
		{
			p_fac = strdup(sub_fac.c_str());
			printf ( "fac:%s\n", p_fac );
		}
	}

	return 0;
}		

int
LoadConfByEqual()
{
	ifstream in;
	in.open(democonf);
	if ( in )
	{
		string line;

		while ( getline(in, line) )
		{
			parse_line(line);	
		}
	}
	else
	{
		cout << "open file failed" << endl;
		return -1;
	}

	return 0;
}

int
main ( int argc, char *argv[] )
{
	LoadConfByEqual();
	
	return 0;
}				
