#include "stdafx.h"
#include "TirInterface.h"

TirParString::TirParString()
{
}

TirParString::~TirParString()
{
}

string TirParString::GetString()
{
	doc = LoadConfig();//load
	root = doc.RootElement();  //root
	child = root->FirstChildElement();
	string v;//��������
	int flag;//�жϱ�־	
	flag = 0;//δ�ҵ���������
	for (; child != NULL; child = child->NextSiblingElement())
	{
		v = child->Value();//child
						   //cout << v << endl;
		while (v == "TirParString")//�ж�����
		{
			flag = 1;//�ҵ��������ͣ���δ�ҵ���Ϊname������
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//�ҵ���Ϊname������
					str = key->GetText();
					cout << str << endl;
					break;
				}
			}
			break;
		}
	}
	if (flag == 0)
		cout << "Couldn't find the data type: TirParString." << endl;
	else if (flag == 1)
		cout << "Couldn't find the data : " << name << endl;
	return str;//����string str
}

int TirParString::SetString(string str)
{
	doc = LoadConfig();//load
	root = doc.RootElement();  //root
	child = root->FirstChildElement();
	string v;//��������
	int flag;//�жϱ�־	
	flag = 0;//δ�ҵ���������
	for (; child != NULL; child = child->NextSiblingElement())
	{
		v = child->Value();//child
						   //cout << v << endl;
		while (v == "TirParString")//�ж�����
		{
			flag = 1;//�ҵ��������ͣ���δ�ҵ���Ϊname������
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//�ҵ���Ϊname������	
							 //Set�޸Ľڵ�ֵ����ɾ��ԭ�ڵ��������޸ĺ�ڵ�
					child->RemoveChild(key); //ɾ���ڵ�
					const char* nc = name.c_str();
					const char* strc = str.c_str();
					TiXmlElement *keynew = new TiXmlElement(nc);//����ͬ���ڵ�
					child->LinkEndChild(keynew);
					TiXmlText *textnew = new TiXmlText(strc);
					keynew->LinkEndChild(textnew);
					cout << keynew->GetText() << endl;
					break;
				}
				break;
			}
			break;
		}
	}
	//doc.SaveFile();
	if (flag == 0)
	{
		cout << "Couldn't find the data type: TirParString." << endl;
		return -1;
	}
	else if (flag == 1)
	{
		cout << "Couldn't find the data :" << name << endl;
		return -1;
	}
	else if (flag == 2)
	{
		cout << "Set " << name << " = " << str << " successfully." << endl;
		return 1;
	}
	else
		return 0;
}

char * TirParString::StrCopy(char * strDest, const char * strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL)); //�ж�ָ���Ƿ�Ϸ�,�������ڴ�,ָ��ĳ��ȷ������  
	char* address = strDest;               //��סĿ���ַ����ʼֵ  
	while ((*strDest++ = *strSrc++) != '\0')   //�ȿ���,���ж�,�����Ͳ����ڿ������˺�,�ټ�һ��  
		NULL;                   // *strDest = '\0'; -->����һ��������.��Ϊ�ַ��������ѿ�����.  
	return address;      //����Ŀ���׵�ַ��ֵ��    
}