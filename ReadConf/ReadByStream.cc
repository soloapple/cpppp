/***************************************************************************************
 *   Copyright (C), 2016, X Co., Ltd.
 *
 *    Filename: ReadByStream.cc
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

const char democonf[] = "ReadByStream.conf";
const string line_head("remote=");

inline string ltrim(string &source,
		string &t = " ")
{
	string str = source;
	return str.erase(0, source.find_first_not_of(t));
}

inline string rtrim(string &source,
		string &t = " ")
{
	string str = source;
	return str.erase(0, source.find_last_not_of(t)+1);
}

inline string trim(string &source,
		string &t = " ")
{
	string str = source;
	return ltrim(rtrim(str, t), t);
}

inline string atrim(string &source,
		string &t = " ")
{
	string str = source;
	return str.replace(source, t, "");
}

struct line_pos
{
	size_t start_pos;
	size_t end_pos;
	size_t equal_pos;
};

/* 
 * Line Style:
 *		remote=local1,local3,local5 (stand style) 
 *		remote = local1, local3, local5 (attach blank) 
 */
int
parse_line(string &line)
{
	char *p_fac;
	struct line_pos pos;

	/* cut empty line */
	line = atrim(&line, );
	if ( line.size() < 1 )
		return 0;

	cout << line << endl;
	return 1;

	/* cut comment line */
	char *p = line.c_str();
	if ( *p == '#' )
	{
		printf ( "find #\n" );
		return 0;
	}

	pos.equal_pos = line.find_first_of("=");
			

	if ( line.substr(0, line_head.size()) == line_head )
	{
		cout << "LINE:" <<line << endl;
		string line_body = line.substr(line_head.size(), line.size());



		stringstream ss_set(line_body);
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
			parse_line(&line);	
		}
	}
	else
	{
		return -1;
	}
}

int
main ( int argc, char *argv[] )
{
	LoadConfByEqual();
	
	return 0;
}				
