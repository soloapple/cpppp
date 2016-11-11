/***************************************************************************************
 *   Copyright (C), 2016, X Co., Ltd.
 *   
 *    Filename: sql_login_config.h
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   10/02/16 04:50:43
 *    Revision: none
 *      
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   10/02/16                  build this moudle
 ***************************************************************************************/
#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>


#include <iostream>
#include <map>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <ext/hash_map>


using namespace std;
using namespace __gnu_cxx;

const char sql_login_conf[] = "sql_login.conf";

const char flag_sql_login_load[]	= "load";
const char flag_sql_login_default[] = "default";
const char flag_sql_login_user[] = "user";
const char flag_sql_login_password[] = "password";
const char flag_sql_login_host[] = "host";
const char flag_sql_login_database[] = "database";
const char flag_sql_login_port[] = "port";
const char flag_sql_login_sock[] = "sock";


struct sql_login_info
{
	const char *login_user;	
	const char *login_password;
	const char *login_host;
	const char *login_database;
	const char *login_port;
	const char *login_sock;
};

