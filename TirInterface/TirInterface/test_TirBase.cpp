#include "stdafx.h"
#include "TirInterface.h"
void test_TirBase()
{
	TirBase* b = new TirBase();
	b->LoadConfig();
	b->type = "TirParVector";//正确的type
	b->IsType();	
	b->type = "Errtype";//错误的type
	b->IsType();	
	b->name = "vec1";//正确的name
	b->IsName();	
	b->name = "Errname";//错误的name
	b->IsName();
	b->SaveConfig();
	b->~TirBase();
}
