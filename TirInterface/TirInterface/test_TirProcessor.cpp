// TirInterface.cpp: �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "TirInterface.h"
#include "test_TirInterface.h"


void test_TirProcessor()
{
	/*****************************************���Է�����*******************************************
	��TirBase�����¶�������ͬ���͵����ݣ����Ե���*/
	/*myProc * proc = new myProc("GaussFilter");//�½�һ������������
	TirProcessor * myp = new TirProcessor();
	TirBase *b = new TirBase();
	TirProcessor * myp = new TirProcessor();//TirProcessor����ָ��
	b = myp->GetParaByName("vec1", TIR_VECTOR);
	cout << b->vec2 << endl;
	b=myp->GetParaByName("mat1", TIR_MATRIX);
	cout << b->matrix2 << endl;
	b = myp->GetParaByName("str1", TIR_STRING);
	cout << b->str2 << endl;*/
	/*****************************************���Է���һ********************************************/
	cout << "****************" << " TirProcessor Test " << "****************" << endl;
	cout << "  **" << "Test TirProcessor constructor." << endl;
	myProc * proc = new myProc();//�½�һ������������
	TirProcessor * myp = new TirProcessor();
	TirBase * myb = new TirBase();//
	//TirProcessor * pp = myb;//����ָ���࣬������
	TirBase * pm = proc->GetParaByName("GaussFilterGamma");//�����Ƿ�get��
	TirBase * pm1 = proc->GetParaByName("GaussFilterPattern");//�����Ƿ�get��
}