#include "stdafx.h"
#include "TirInterface.h"

void test_TirBase()
{
	cout << "****************" << " TirBase Test " << "***************" << endl;
	cout << "  **" << "Test TirBase constructor." << endl;
	TirBase* b = new TirBase();
	cout << "  **" << "Test LoadConfig()." << endl;
	b->LoadConfig();
	cout << "  **" << "Test IsType()." << endl;
	b->type = "TirParVector";//正确的type
	b->IsType();	
	b->type = "Errtype";//错误的type
	b->IsType();	
	cout << "  **" << "Test IsName()." << endl;
	b->name = "vec1";//正确的name
	b->IsName();	
	b->name = "Errname";//错误的name
	b->IsName();
	cout << "  **" << "Test SaveConfig()." << endl;
	b->SaveConfig();
	cout << "  **" << "Test TirBase destructor." << endl;
	b->~TirBase();
}
