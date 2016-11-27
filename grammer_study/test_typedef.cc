/******************************************************************************
 *   Copyright (C), 2016, X Co., Ltd.
 *
 *    Filename: test_typedef.cc
 * Description: 
 *     Version: 1.0
 *     Created: soloapple   11/27/16 00:03:31
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              soloapple   11/27/16                  build this moudle  
 *****************************************************************************/
#include "headers.h"

/* 
 * usage one: replace function point 
 */
typedef int *(*pFun)(int, char*);

int *
redo(int a, char* pa)
{
	cout << "a: " << a << " pa: " << pa << endl;
	
	return NULL;
}

/* 
 * one_variant 1 
 * prototype: void(*b[10])(void(*)());
 */
typedef void(*pFunParam)();
typedef void(*pFunx)(pFunParam);

/* you can set this as interface. */
void
setParam()
{
	cout << "set param" << endl;

	return;
}

void
runFunc(pFunParam)
{
	pFunParam();
	cout << "run func" << endl;

	return;
}


/* 
 * one_variant 2
 * prototype: double(*)() (*e)[9] 
 */


int main()
{

	/* 
	 * usage one 
	 */
	pFun a[5];
	a[0] = redo;
	a[0](12, "23");


	/* 
	 * one_variant 1 
	 */
	pFunx b[10];
	b[0] = runFunc;
	b[0](setParam);

	return 0;
}
