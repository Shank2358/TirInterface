// TirInterface.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "TirInterface.h"
#include "test_TirInterface.h"


void test_TirProcessor()
{
	/*****************************************测试方法二*******************************************
	在TirBase类重新定义了相同类型的数据，可以调出*/
	/*myProc * proc = new myProc("GaussFilter");//新建一个处理器名字
	TirProcessor * myp = new TirProcessor();
	TirBase *b = new TirBase();
	TirProcessor * myp = new TirProcessor();//TirProcessor类型指针
	b = myp->GetParaByName("vec1", TIR_VECTOR);
	cout << b->vec2 << endl;
	b=myp->GetParaByName("mat1", TIR_MATRIX);
	cout << b->matrix2 << endl;
	b = myp->GetParaByName("str1", TIR_STRING);
	cout << b->str2 << endl;*/
	/*****************************************测试方法一********************************************/
	cout << "****************" << " TirProcessor Test " << "****************" << endl;
	cout << "  **" << "Test TirProcessor constructor." << endl;
	myProc * proc = new myProc();//新建一个处理器名字
	TirProcessor * myp = new TirProcessor();
	TirBase * myb = new TirBase();//
	//TirProcessor * pp = myb;//子类指向父类，有问题
	TirBase * pm = proc->GetParaByName("GaussFilterGamma");//测试是否get到
	TirBase * pm1 = proc->GetParaByName("GaussFilterPattern");//测试是否get到
}