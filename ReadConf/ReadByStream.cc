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

int
parse_line(string line)
{
	char *p_fac;

	const char *p =  line.c_str();
	if ( *p == '#' )
	{
		printf ( "find #\n" );
		return 0;
	}

	if ( line.substr(0, line_head.size()) == line_head )
	{
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
			parse_line(line);	
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
