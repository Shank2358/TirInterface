#include "stdafx.h"
#include "TirInterface.h"
void test_TirBase()
{
	TirBase* b = new TirBase();
	b->LoadConfig();
	b->type = "TirParVector";//��ȷ��type
	b->IsType();	
	b->type = "Errtype";//�����type
	b->IsType();	
	b->name = "vec1";//��ȷ��name
	b->IsName();	
	b->name = "Errname";//�����name
	b->IsName();
	b->SaveConfig();
	b->~TirBase();
}
