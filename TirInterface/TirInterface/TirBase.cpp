#include "stdafx.h"
#include "TirInterface.h"

TirBase::TirBase()
{
	cout << "TirBase constructor called." << endl;
}

TirBase::~TirBase()
{
	cout << "TirBase destructor called." << endl;
}

TiXmlDocument TirBase::LoadConfig()
{
	//Load cfg
	doc="Tir.cfg";
	bool loadOk = doc.LoadFile();//Load
	if (!loadOk)
	{
		cout << "Could not load the config file.Error:" << doc.ErrorDesc() << endl;//faild
		exit(1);
	}
	else
	{
		cout << "Load the config file successfully." << doc.ErrorDesc() << endl;//successfully
	}
	return doc;
}

int TirBase::SaveConfig()
{
	doc.SaveFile();
	cout << "Save the config file successfully." << endl;
	return 0;
}

int TirBase::IsName()
{
	int flag = -1;
	root = doc.RootElement();
	child = root->FirstChildElement();
	while (child != NULL)
	{
		key = child->FirstChildElement();
		while (key != NULL)
		{
			if (key->Value() == name)
			{
				flag = 1;
				break;
			}
			else
			{
				key = key->NextSiblingElement();
				if (key == NULL)
				{
					key = child->FirstChildElement();
					break;
				}
			}
		}
		child = child->NextSiblingElement();
		if (child == NULL)
		{
			child = root->FirstChildElement();
			break;
		}
	}
	if (flag == 1)
	{
		cout << "Find name: " << name << "." << endl;
	}
	else if(flag == -1)
	{
		cout << "Couldn't find name: " << name << "." << endl;
	}
	return flag;
}

int TirBase::IsType()
{
	root = nullptr;
	child = nullptr;
	int flag = -1;
	root = doc.RootElement();
	child = root->FirstChildElement();
	while (child != NULL)
	{
		if (type == child->Value())
		{
			flag = 1;
			break;
		}
		else
		{
			child = child->NextSiblingElement();
			if (child == NULL)
			{
				child = root->FirstChildElement();
				break;
			}
		}
	}
	if (flag == 1)
	{
		cout << "Find type: " << type << "." << endl;
	}
	else
	{
		cout << "Couldn't find type: " << type << "." << endl;
	}
	return flag;
}