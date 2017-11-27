#include "stdafx.h"
#include "TirInterface.h"

void test_TirStringPath()
{
	cout << "****************" << " TirStringPath Test " << "****************" << endl;
	cout << "  **" << "Test TirStringPath constructor." << endl;
	TirStringPath* sp = new TirStringPath();
	sp->doc = sp->LoadConfig();
	sp->name = "path1";
	sp->type = "TirStringPath";
	cout << "  **" << "Test GetPathWin()." << endl;
	string s_win = sp->GetPathWin();
	cout << "  **" << "Test GetPathNix()." << endl;
	string s_nix = sp->GetPathNix();
	cout << "  **" << "Test GetFileName()." << endl;
	string fn = sp->GetFileName();
	cout << "  **" << "Test GetFileExt()." << endl;
	string fe = sp->GetFileExt();
	cout << "  **" << "Test IsExist()." << endl;
	sp->IsExist();
	cout << "  **" << "Test IsLegal()." << endl;
	sp->IsLegal();
	cout << "  **" << "Test TirStringPath destructor." << endl;
	sp->~TirStringPath();
}