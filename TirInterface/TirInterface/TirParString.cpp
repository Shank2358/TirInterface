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
	int flag = 0;//未找到数据类型
	for (; child != NULL; child = child->NextSiblingElement())
	{
		while (child->Value() == type)//判断类型
		{
			flag = 1;//找到数据类型，但未找到名为name的数据
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//找到名为name的数据
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
	int flag = 0;//未找到数据类型
	for (; child != NULL; child = child->NextSiblingElement())
	{
		while (child->Value() == type)//判断类型
		{
			flag = 1;//找到数据类型，但未找到名为name的数据
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//找到名为name的数据	
					child->RemoveChild(key); //删除节点
					const char* nc = name.c_str();
					const char* strc = str.c_str();
					TiXmlElement *keynew = new TiXmlElement(nc);//新增同名节点
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
	assert((strDest != NULL) && (strSrc != NULL)); //判断指针是否合法,即分配内存,指向某块确定区域  
	char* address = strDest;               //记住目标地址的起始值  
	while ((*strDest++ = *strSrc++) != '\0')   //先拷贝,后判断,这样就不用在拷贝完了后,再加一句  
		NULL;                   // *strDest = '\0'; -->即加一个结束符.因为字符串结束已拷贝了.  
	return address;      //返回目标首地址的值。    
}
*/