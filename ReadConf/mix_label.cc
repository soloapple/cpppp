/******************************************************************************
 *   Copyright (C), 2017, X Co., Ltd.
 *
 *    Filename: mix_label.cc
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   2017年02月23日 01时41分44秒
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   2017年02月23日                  build this moudle  
 *****************************************************************************/
#include "mix_label.h"

const char democonf[] = "./mix_label.conf";

string key_mail[] = 
{
	"mail_ip",
	"mail_port"
};

string key_log[] = 
{
	"log_ip",
	"log_port"
};

string key_snmp[] =
{
	"mib_path",
	"snmp_ver", 
	"snmp_ip",	 
	"snmp_host",
	"EP_OID",	 
	"data_OID", 
	"value",	 
	"user_info"
};

vector<conf_log_t*>conf_log_vec;
vector<conf_mail_t*>conf_mail_vec;
map<string, string>c_snmp;

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

void
conf_destroy()
{
	vector<conf_mail_t*>::iterator iter_mail;  
	for ( iter_mail=conf_mail_vec.begin(); iter_mail!=conf_mail_vec.end(); iter_mail++ )  
	{  
		delete *iter_mail;
	}  
	
	vector<conf_log_t*>::iterator iter_log;  
	for ( iter_log=conf_log_vec.begin(); iter_log!=conf_log_vec.end(); iter_log++ )  
	{  
		delete *iter_log;
	}  
	
	c_snmp.clear();

	return;
}

void
conf_mail_display()
{
	vector<conf_mail_t*>::iterator iter;  
	for ( iter=conf_mail_vec.begin(); iter!=conf_mail_vec.end(); iter++ )  
	{  
		cout << "----- mail display -----" << endl;
		cout << "mail_ip:" << (*iter)->mail_ip << endl;  
		cout << "mail_port:" << (*iter)->mail_port << endl;  
		cout << "------------------------" << endl;
	}  
}

void
conf_log_display()
{
	vector<conf_log_t*>::iterator iter;  
	for ( iter=conf_log_vec.begin(); iter!=conf_log_vec.end(); iter++ )  
	{  
		cout << "----- log display -----" << endl;
		cout << "log_ip:" << (*iter)->log_ip << endl;  
		cout << "log_port:" << (*iter)->log_port << endl;  
		cout << "------------------------" << endl;
	}  
}

void
conf_snmp_display()
{
	cout << "----- snmp display -----" << endl;
	cout << "mib_path: " << c_snmp["mib_path"]  << endl;    
	cout << "snmp_ver: " << c_snmp["snmp_ver"] << endl;
	cout << "snmp_ip: " << c_snmp["snmp_ip"] << endl;
	cout << "snmp_host: " << c_snmp["snmp_host"] << endl;
	cout << "EP_OID: " << c_snmp["EP_OID"] << endl;
	cout << "data_OID: " << c_snmp["data_OID"] << endl;
	cout << "value: " << c_snmp["value"] << endl;
	cout << "user_info: " << c_snmp["user_info"] << endl;
	cout << "------------------------" << endl;
}

/* line style: mail_ip = 0.0.0.0, mail_port = 1000 */
void
line_mail_handle(string & line)
{
	line_pair_t pair;
	line_pos_t pos;

	stringstream ss_set(line);
	string sub;

	conf_mail_t *c_mail = new conf_mail_t;

	while ( getline(ss_set, sub, ',') )
	{
		if ( (pos.n = sub.find('=')) == -1 )
			continue;

		pair.key = sub.substr(0, pos.n);
		pair.value = sub.substr(pos.n + 1, pos.end - (pos.n + 1) + 1);

		trim(pair.key);
		trim(pair.value);

		if ( pair.key == "mail_ip" )
			c_mail->mail_ip = pair.value;

		if ( pair.key == "mail_port" )
			c_mail->mail_port = atoi(pair.value.c_str());
	}	

	conf_mail_vec.push_back(c_mail);

	return;
}

/* line style: log_ip = 0.0.0.0, log_port = 1000 */
void
line_log_handle(string & line)
{
	line_pair_t pair;
	line_pos_t pos;

	stringstream ss_set(line);
	string sub;

	conf_log_t *c_log = new conf_log_t;

	while ( getline(ss_set, sub, ',') )
	{
		if ( (pos.n = sub.find('=')) == -1 )
			continue;

		pair.key = sub.substr(0, pos.n);
		pair.value = sub.substr(pos.n + 1, pos.end - (pos.n + 1) + 1);

		trim(pair.key);
		trim(pair.value);

		if ( pair.key == "log_ip" )
			c_log->log_ip = pair.value;

		if ( pair.key == "log_port" )
			c_log->log_port = atoi(pair.value.c_str());
	}	

	conf_log_vec.push_back(c_log);

	return;
}

/* line style:
 * [ snmp ]
 *		mib_path = $mib_path 
 *		data_OID = "$data_OID"
 *		...
 *		EP_OID = $EP_OID
 */
void
line_snmp_handle(string & line)
{
	line_pair_t pair;
	line_pos_t pos;

	if ( (pos.n = line.find('=')) == -1 )
		return;

	pair.key = line.substr(0, pos.n);
	pair.value = line.substr(pos.n + 1, pos.end - (pos.n + 1) + 1);

	trim(pair.key);
	trim(pair.value);

	c_snmp.insert(make_pair(pair.key, pair.value));

	return;
}

config_item_t item[] = 
{
	{
		line_label:"mail",
		line_handle:line_mail_handle,
	},
	{
		line_label:"log",
		line_handle:line_log_handle,	
	},
	{
		line_label:"snmp",
		line_handle:line_snmp_handle,
	}
};

int
load_config()
{
	string line;
	ifstream in;

	int fi;

	int i;
	int got_label;
	int nmemb = (int)(sizeof(item)/sizeof(config_item_t));

	struct line_pos pos;

	in.open(democonf);
	if ( !in )
	{
		cout << "open file failed!" << endl;
		return -1;
	}
	
	while ( getline(in, line) )
	{
		trim(line);
		if ( line.length() == 0 )
			continue;

		pos.start = 0;
		pos.end = line.length(); 

		if ( (pos.n = line.find('#')) != -1 )	
		{
			if ( pos.n == 0 )
			{
				cout << "comment line:" << line << endl;
				continue;
			}

			pos.end = pos.n - 1;
		}

		string new_line = line.substr(pos.start, pos.start + 1 - pos.end);
		trim(new_line);

		if ( line.find('[') != line.npos )
		{
			got_label = 0;

			for ( i=0; i<nmemb; i++ )	
			{
				fi = line.find(item[i].line_label, 0);
				if ( fi != -1 ) 
				{
					got_label = 1;
					break;
				}
			}

			continue;
		}

		if ( got_label )
		{
			if ( item[i].line_handle )	
				item[i].line_handle(line);
		}
	}

	in.close();

	return 0;
}

int
main()
{
	load_config();

	conf_mail_display();
	conf_log_display();
	conf_snmp_display();

	conf_destroy();

	return 0;
}
