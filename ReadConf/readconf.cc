#include "readconf.h"
#include "SimpleIni.h"

int b_load = 0;

CSimpleIniA login_conf;
sql_login_info *p_login_info;

void 
set_login_info(sql_login_info **p_sql_login_info, const char *login_flag)
{
	*p_sql_login_info = new sql_login_info();

	(*p_sql_login_info)->login_user		= login_conf.GetValue(login_flag, flag_sql_login_user, flag_sql_login_default);
	(*p_sql_login_info)->login_password	= login_conf.GetValue(login_flag, flag_sql_login_password, flag_sql_login_default);
	(*p_sql_login_info)->login_host		= login_conf.GetValue(login_flag, flag_sql_login_host, flag_sql_login_default);
	(*p_sql_login_info)->login_database	= login_conf.GetValue(login_flag, flag_sql_login_database, flag_sql_login_default);
	(*p_sql_login_info)->login_port		= login_conf.GetValue(login_flag, flag_sql_login_port, flag_sql_login_default);
	(*p_sql_login_info)->login_sock		= login_conf.GetValue(login_flag, flag_sql_login_sock, flag_sql_login_default);

	assert((*p_sql_login_info)->login_user != NULL);
	assert((*p_sql_login_info)->login_password != NULL);
	assert((*p_sql_login_info)->login_host != NULL);
	assert((*p_sql_login_info)->login_database != NULL);
	assert((*p_sql_login_info)->login_port != NULL);
	assert((*p_sql_login_info)->login_sock != NULL);
}

int 
load_login_conf()
{
	login_conf.SetUnicode();
	if ( login_conf.LoadFile(sql_login_conf) < 0 )
		return -1;

	list <CSimpleIniA::Entry> m;
	login_conf.GetAllSections(m);

	list <CSimpleIniA::Entry>::iterator g_mi;
	for ( g_mi = m.begin(); g_mi != m.end(); g_mi++ )
	{
		if ( !strncmp((*g_mi).pItem, flag_sql_login_load, strlen(flag_sql_login_load)) )
			b_load = 1;
	}

	if ( b_load )
	{
		set_login_info(&p_login_info, flag_sql_login_load);	
	}

	return 1;
}

int 
main(int argc, char* argv)
{
	if ( load_login_conf() < 0 )
		return 0;
}
