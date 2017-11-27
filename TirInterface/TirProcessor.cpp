#include "stdafx.h"
#include "TirInterface.h"

TirProcessor::TirProcessor()
{
	cout << "TirProcessor constructor called." << endl;
}

TirProcessor::~TirProcessor()
{
	cout << "TirProcessor destructor called." << endl;
}

TirBase* TirProcessor::GetParaByName(string name)
{
	TirBase *p = new TirBase();
	for (auto i = pv.begin(); i != pv.end(); i++)
	{
		p = *i;
		if (p->name == name)
		{	
			cout << p->name << endl;
		}
	}
	return p;

	/*****************************************方法二*******************************************
	输入端应有TirType Type定义，将Type作为输入项*/
	/*switch (Type)
	{
	case TIR_VECTOR:
	{
	TirBase *p1 = new TirParVector;
	TirParVector *v1 = new TirParVector();
	v1->doc = v1->LoadConfig();
	v1->name = name;
	v1->type = "TirParVector";
	p1->vec2 = v1->GetVector();
	return p1;
	break;
	}
	case TIR_MATRIX:
	{
	TirBase *p2 = new TirParMatrix;
	TirParMatrix *m1 = new TirParMatrix();
	m1->doc = m1->LoadConfig();
	m1->name = name;
	m1->type = "TirParMatrix";
	p2->matrix2= m1->GetMatrix();
	return p2;
	break;
	}
	case TIR_STRING:
	{
	TirBase *p3 = new TirParString;
	TirParString *s1 = new TirParString();
	s1->doc = s1->LoadConfig();
	s1->name = name;
	s1->type = "TirParString";
	p3->str2 = s1->GetString();
	return p3;
	break;
	}
	default:
	break;

	}*/
}

int TirProcessor::SetParaByName(string name, TirBase *b)
{
	//TirBase *p = new TirBase();
	for (auto i = pv.begin(); i != pv.end(); i++)
	{

	}


	return 0;
}

void TirProcessor::Process(Mat ** img_in, Mat ** img_out)
{
	cout << "Process is OK." << endl;
}