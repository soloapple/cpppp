/******************************************************************************
 *   Copyright (C), 2017, X Co., Ltd.
 *   
 *    Filename: GetConfig.h
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   2017��02��21�� 21ʱ39��36��
 *    Revision: none
 *      
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   2017��02��21��                  build this moudle
 *****************************************************************************/

#ifndef _GET_CONFIG_H_  
#define _GET_CONFIG_H_  
#define COMMENT_CHAR '#'  
#include <string>  
#include <map>  
  
using namespace std;  
  
bool read_config(const string & filename, map<string, string> & m);  
void print_config(const map<string, string> & m);  
  
#endif  
