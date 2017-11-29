#include "stdafx.h"
#include "TirInterface.h"

TirParString::TirParString()
{
	cout << "TirParString constructor called." << endl;
}

TirParString::~TirParString()
{
	cout << "TirParString destructor called." << endl;
}

string TirParString::GetString()
{
	root = doc.RootElement(); 
	child = root->FirstChildElement();
	int flag = 0;//δ�ҵ���������
	for (; child != NULL; child = child->NextSiblingElement())
	{
		while (child->Value() == type)//�ж�����
		{
			flag = 1;//�ҵ��������ͣ���δ�ҵ���Ϊname������
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//�ҵ���Ϊname������
					str = key->GetText();
					cout << name << " = " << str << endl;
					break;
				}
			}
			break;
		}
		if (child == NULL)
		{
			child = root->FirstChildElement();
			break;
		}
	}
	if (flag == 0)
		cout << "Couldn't find the data type: TirParString." << endl;
	else if (flag == 1)
		cout << "Couldn't find the data : " << name << endl;
	return str;
}

int TirParString::SetString(string str)
{
	root = doc.RootElement();
	child = root->FirstChildElement();
	int flag = 0;//δ�ҵ���������
	for (; child != NULL; child = child->NextSiblingElement())
	{
		while (child->Value() == type)//�ж�����
		{
			flag = 1;//�ҵ��������ͣ���δ�ҵ���Ϊname������
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//�ҵ���Ϊname������	
					child->RemoveChild(key); //ɾ���ڵ�
					const char* nc = name.c_str();
					const char* strc = str.c_str();
					TiXmlElement *keynew = new TiXmlElement(nc);//����ͬ���ڵ�
					child->LinkEndChild(keynew);
					TiXmlText *textnew = new TiXmlText(strc);
					keynew->LinkEndChild(textnew);
					break;
				}
				if (key == NULL)
				{
					key = child->FirstChildElement();
					break;
				}
			}
			break;
		}
		if (child == NULL)
		{
			child = root->FirstChildElement();
			break;
		}
	}
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

TirParString TirParString::Copy()
{
	TirParString s;
	s.name = name;
	s.type = type;
	s.str = str;
	cout << "Copy OK!" << endl;
	return s;
}

/*
char * TirParString::StrCopy(char * strDest, const char * strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL)); //�ж�ָ���Ƿ�Ϸ�,�������ڴ�,ָ��ĳ��ȷ������  
	char* address = strDest;               //��סĿ���ַ����ʼֵ  
	while ((*strDest++ = *strSrc++) != '\0')   //�ȿ���,���ж�,�����Ͳ����ڿ������˺�,�ټ�һ��  
		NULL;                   // *strDest = '\0'; -->����һ��������.��Ϊ�ַ��������ѿ�����.  
	return address;      //����Ŀ���׵�ַ��ֵ��    
}
*/