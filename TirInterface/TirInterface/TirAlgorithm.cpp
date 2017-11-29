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
	//CLSID clsid;//CLSIDָ��
	//CLSIDFromProgID(OLESTR("base.1"), &clsid);//ProgIDָ�룬classname.rgs�п����ҵ�
											  //rgs�����ע��Ľű��ļ�����ʹ��Regsvr32.exeע�����ʱ������ڲ����ǵ���������ļ���rgs�ļ�������Դ����ʽ����DLL�ڵġ�
	//CComPtr<ITirBase>pFirstClass;//����ָ�룬ָ��COM�е���
	//pFirstClass.CoCreateInstance(clsid);
	/*size_t pathsize = path.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(path.length() - 1));//stringתLPCWSTR
	mbstowcs_s(&convertedChars, wcstring, pathsize, path.c_str(), _TRUNCATE);
	cout << hdll << endl;
	hdll = LoadLibrary(wcstring);//LPCWSTR���͵�path
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
	flag = 0;//δ�ҵ���Ϊprocname��Processor
	for (auto i = procvec.begin(); i != procvec.end(); i++)
	{
		p = *i;
		if (p->name == procname) //while(p->IsName(proname))
		{		
			//cout << p->name<<endl;
			flag = 1;//���������ҵ���Ϊprocname��Processor
			break;
			//pp = p->GetParaByName(paraname);//ͨ������GetParaByName���paraname��ֵ����������pp
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
	flag = 0;//δ�ҵ���Ϊprocname��Processor
	for (auto i = procvec.begin(); i != procvec.end(); ++i)
	{
		p = *i;
		if (p->name == procname) //while(p->IsName(proname))
		{
			cout << p->name << endl;
			flag = 1;//���������ҵ���Ϊprocname��Processor  Ȼ���أ���������LoadProc����������Ϊprocname��cfg�ļ���
			break;
			pp = p->GetParaByName(paraname);//����Ϊparaname��ԭ�����ҵ�����������pp �������ʼע�͵� ִ��
											//ע��GetParaByName���ص���һ��ָ������ָ��
			if (pp != NULL)//ע��C++��ֻ����ָ�����ָ���жϸ����Ƿ�Ϊ�գ�����ֱ���ж���Ķ����Ƿ�Ϊ�գ������ж���Ч������Ч���������
			{
				flag = 2;//����Ϊparaname��ԭ�����ҵ�����������pp�ɹ�
				if (pp->type == b->type) //�ж�ԭ������Ϊparaname�Ĳ�����type��ҪSet��ȥ�Ĳ�����type�Ƿ�һ��if(p->IsType=b->IsType)
				{
					flag = 3;//cfg�ļ���ԭ����paraname�Ĳ�����ҪSet��paraname�Ĳ���������ͬ������׼��д��
					int r;
					r = p->SetParaByName(paraname, b);//����SetParaByName����????ΪʲôҪ����pָ���SetParaByName�����أ�
													  ////r =SetParaByName(paraname, b);��������
					flag = 4;
					/*if (para->type == "TirParVector")
					{
					TirParVector * pv;
					pv = (TirParVector *)para;
					p = pv->Copy;//��Ҫд���Vector���͵Ĳ������Ƹ�p
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
	processor = (Dllfun)GetProcAddress(hdll, nnn);//Processor name, LPCSTR����
	cout << processor(5, 4) << endl;
	*/

	/*********************************�˴�Ϊ����COM�������*****************************************/
	/*#import "E:\\Project\\jing\\test4\\x64\\Release\\test4.dll" no_namespace
	CoInitialize(NULL);
	CLSID clsid;//CLSIDָ��
	CLSIDFromProgID(OLESTR("base.1"), &clsid);//ProgIDָ�룬classname.rgs�п����ҵ�
	//rgs�����ע��Ľű��ļ�����ʹ��Regsvr32.exeע�����ʱ������ڲ����ǵ���������ļ���rgs�ļ�������Դ����ʽ����DLL�ڵġ�
	CComPtr<ITirBase>pFirstClass;//����ָ�룬ָ��COM�е���
	pFirstClass.CoCreateInstance(clsid);
	long ret = pFirstClass->add1(1, 2);//������,Ӧ��Ϊprocname
	cout << ret << endl;
	long ret2 = pFirstClass->add2(2, 2);//������
	cout << ret2 << endl;
	pFirstClass.Release();//�ͷ��ڴ�
	CoUninitialize();*/
	return nullptr;
}

int TirAlgorithm::SetProcByName(string procname, TirProcessor** proc)
{
	return 0;
}