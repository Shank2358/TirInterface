#include "stdafx.h"
#include "TirInterface.h"

TirAlgorithm::TirAlgorithm()
{
}

TirAlgorithm::~TirAlgorithm()
{
}

void TirAlgorithm::Loadproc(string path)
{
	/*size_t pathsize = path.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(path.length() - 1));//string转LPCWSTR
	mbstowcs_s(&convertedChars, wcstring, pathsize, path.c_str(), _TRUNCATE);
	cout << hdll << endl;
	hdll = LoadLibrary(wcstring);//LPCWSTR类型的path
	cout << hdll << endl;
	if (hdll != NULL)
	{
		cout << "Load successfully." << endl;
	}
	else
	{
		cout << "Load faild." << endl;
	}*/
}

void TirAlgorithm::Unloadproc()
{
	//FreeLibrary(hdll);
}

TirBase TirAlgorithm::GetPara(string procname, string paraname)
{
	return TirBase();
}

int TirAlgorithm::SetPara(string procname, string paraname, TirBase* b)
{
	return 0;
}

TirProcessor** TirAlgorithm::GetProcByName(string procname)
{
	/*
	//test
	LPCSTR nnn = (LPCSTR)procname.c_str();
	typedef long(*Dllfun)(long, long);
	Dllfun processor;
	processor = (Dllfun)GetProcAddress(hdll, nnn);//Processor name, LPCSTR类型
	cout << processor(5, 4) << endl;
	*/
	return nullptr;
}

int TirAlgorithm::SetProcByName(string procname, TirProcessor** proc)
{
	return 0;
}