/******************************************************************************
 *   Copyright (C), 2017, X Co., Ltd.
 *   
 *    Filename: mix_label.h
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   2017年02月23日 01时41分20秒
 *    Revision: none
 *      
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   2017年02月23日                  build this moudle
 *****************************************************************************/
#ifndef  MIX_LABEL_INCLUDE
#define  MIX_LABEL_INCLUDE

#include "headers.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef enum 
{
	SZ_LABEL = 128
} sz_config;				

typedef void (*config_line_handle)(string & line);

typedef struct config_item 
{
	char line_label[SZ_LABEL];
	config_line_handle line_handle;
} config_item_t;			


/* each line position */
typedef struct line_pos
{
	size_t start;
	size_t end;

	int n;
} line_pos_t;

/* for line of key=value */
typedef struct line_pair
{
	string key;
	string value;	
} line_pair_t;

typedef struct conf_mail 
{
	string mail_ip;
	unsigned int mail_port;
} conf_mail_t;			

typedef struct conf_log 
{
	string log_ip;
	unsigned int log_port;
} conf_log_t;			

typedef struct conf_snmp 
{
	string mib_path;		/* path */
	string snmp_ver;		/* version */
	string snmp_ip;			/* ip string, "0.0.0.0" */
	string snmp_host;		/* could be empty */
	string EP_OID;			/* Enterprise OID*/
	string data_OID;		/* data OID */
	string value;			/* data value */
	string user_info;		/* only version 3 have */
} conf_snmp_t;			




#endif   
