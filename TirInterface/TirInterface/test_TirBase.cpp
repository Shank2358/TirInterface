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
	b->type = "TirParVector";//��ȷ��type
	b->IsType();	
	b->type = "Errtype";//�����type
	b->IsType();	
	cout << "  **" << "Test IsName()." << endl;
	b->name = "vec1";//��ȷ��name
	b->IsName();	
	b->name = "Errname";//�����name
	b->IsName();
	cout << "  **" << "Test SaveConfig()." << endl;
	b->SaveConfig();
	cout << "  **" << "Test TirBase destructor." << endl;
	b->~TirBase();
}
