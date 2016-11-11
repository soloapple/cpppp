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

const char sql_fac_conf[] = "/storage/syslog-ng/sql_facility.conf";
const string flag_remote_set("remote=");

int
parse_fac_line(string line)
{
	char *p_fac;

//	if ( line.substr(0, 1) == "#");
//		return 0;

	if ( line.substr(0, flag_remote_set.size()) == flag_remote_set )
	{
		string remote_fac_set = line.substr(flag_remote_set.size(), line.size());

		stringstream ss_remote_fac_set(remote_fac_set);
		string sub_fac;

		while ( getline(ss_remote_fac_set, sub_fac, ',') )
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
	in.open(sql_fac_conf);
	if ( in )
	{
		string line;

		while ( getline(in, line) )
		{
			parse_fac_line(line);	
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
