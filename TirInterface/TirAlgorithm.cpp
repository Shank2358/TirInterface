#include "stdafx.h"
#include "TirInterface.h"
#include "atlcomcli.h" 
//#import "E:\\visual studio 2017\\Projects\\A2\\x64\\Release\\A2.dll" no_namespace

TirAlgorithm::TirAlgorithm()
{
	cout << "TirAlgorithm constructor called." << endl;
}

TirAlgorithm::~TirAlgorithm()
{
	cout << "TirAlgorithm destructor called." << endl;
}

void TirAlgorithm::Loadproc(string path)
{
	//CoInitialize(NULL);
	//CLSID clsid;//CLSID指针
	//CLSIDFromProgID(OLESTR("base.1"), &clsid);//ProgID指针，classname.rgs中可以找到
											  //rgs是组件注册的脚本文件，当使用Regsvr32.exe注册组件时，组件内部便是调用了这个文件。rgs文件是以资源的形式存于DLL内的。
	//CComPtr<ITirBase>pFirstClass;//智能指针，指向COM中的类
	//pFirstClass.CoCreateInstance(clsid);
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
	CoUninitialize();
	//FreeLibrary(hdll);
}

TirBase* TirAlgorithm::GetPara(string procname, string paraname)
{
	TirProcessor * p = new TirProcessor();
	TirBase* pp = new TirBase();
	int flag;
	flag = 0;//未找到名为procname的Processor
	for (auto i = procvec.begin(); i != procvec.end(); i++)
	{
		p = *i;
		if (p->name == procname) //while(p->IsName(proname))
		{		
			//cout << p->name<<endl;
			flag = 1;//在容器中找到名为procname的Processor
			break;
			//pp = p->GetParaByName(paraname);//通过函数GetParaByName获得paraname的值，赋给基类pp
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "Find the Processor:" << procname << " successfully" << endl;
		return pp;
	}
	else if (flag == 0)
	{
		cout << "Couldn't find the Processor: " << procname << endl;
		return 0;
	}

}

int TirAlgorithm::SetPara(string procname, string paraname, TirBase* b)
{
	TirProcessor * p = new TirProcessor();
	TirBase *pp = new TirBase();
	int flag;
	flag = 0;//未找到名为procname的Processor
	for (auto i = procvec.begin(); i != procvec.end(); ++i)
	{
		p = *i;
		if (p->name == procname) //while(p->IsName(proname))
		{
			cout << p->name << endl;
			flag = 1;//在容器中找到名为procname的Processor  然后呢？？？调用LoadProc函数吗？找名为procname的cfg文件吗？
			break;
			pp = p->GetParaByName(paraname);//把名为paraname的原参数找到，赋给基类pp 从这儿开始注释掉 执行
											//注意GetParaByName返回的是一个指向基类的指针
			if (pp != NULL)//注意C++中只能用指向类的指针判断该类是否为空，不能直接判断类的对象是否为空，可以判断有效还是无效（）句柄法
			{
				flag = 2;//把名为paraname的原参数找到，赋给基类pp成功
				if (pp->type == b->type) //判断原来的名为paraname的参数的type与要Set进去的参数的type是否一致if(p->IsType=b->IsType)
				{
					flag = 3;//cfg文件中原来的paraname的参数与要Set的paraname的参数类型相同，可以准备写入
					int r;
					r = p->SetParaByName(paraname, b);//调用SetParaByName函数????为什么要调用p指向的SetParaByName函数呢？
													  ////r =SetParaByName(paraname, b);不可以吗？
					flag = 4;
					/*if (para->type == "TirParVector")
					{
					TirParVector * pv;
					pv = (TirParVector *)para;
					p = pv->Copy;//把要写入的Vector类型的参数复制给p
					}*/
					cout << r << endl;
				}
			}
		}
	}
	if (flag == 0)
	{
		cout << "Couldn't find the Processor " << procname << endl;
		return -1;
	}
	else if (flag == 1)
	{
		cout << "Find the Processor " << procname << " successfully, but maybe the function GetParaByName occurs error." << endl;
		return -1;
	}
	else if (flag == 2)
	{
		cout << "The TirBase pp get the previous parameter named paraname successfully. But the type between the previous and the present parameter is different." << endl;
		return -1;
	}
	else if (flag == 3)
	{
		cout << "The present parameter have the same type with the previous one. Maybe the function SetParaByName uses incorrectly." << endl;
		return -1;
	}
	else if (flag == 4)
	{
		cout << "Set " << paraname << " successfully." << endl;
		return 1;
	}
	else
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

	/*********************************此处为调用COM组件程序*****************************************/
	/*#import "E:\\Project\\jing\\test4\\x64\\Release\\test4.dll" no_namespace
	CoInitialize(NULL);
	CLSID clsid;//CLSID指针
	CLSIDFromProgID(OLESTR("base.1"), &clsid);//ProgID指针，classname.rgs中可以找到
	//rgs是组件注册的脚本文件，当使用Regsvr32.exe注册组件时，组件内部便是调用了这个文件。rgs文件是以资源的形式存于DLL内的。
	CComPtr<ITirBase>pFirstClass;//智能指针，指向COM中的类
	pFirstClass.CoCreateInstance(clsid);
	long ret = pFirstClass->add1(1, 2);//函数名,应改为procname
	cout << ret << endl;
	long ret2 = pFirstClass->add2(2, 2);//函数名
	cout << ret2 << endl;
	pFirstClass.Release();//释放内存
	CoUninitialize();*/
	return nullptr;
}

int TirAlgorithm::SetProcByName(string procname, TirProcessor** proc)
{
	return 0;
}