// TirInterface.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "TirInterface.h"
#include "test_TirInterface.h"

int main()
{
	test_TirBase();
	test_TirParVector();
	test_TirParMatrix();
	test_TirParString();
	test_TirStringPath();
	test_TirProcessor();
	test_TirAlgorithm();
/*
	//Algorithm
	TirAlgorithm al;
	//al.Loadproc("E:\\visual studio 2017\\Projects\\FirstCOM\\x64\\Release\\FirstCOM.dll");
	//al.GetProcByName("addfun");
	//al.Unloadproc();
	//FreeLibrary(hdll);
	//al.GetProcByName("addfun");
*/
	return 0;
}
