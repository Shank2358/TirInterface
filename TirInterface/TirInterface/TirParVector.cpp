#include "stdafx.h"
#include "TirInterface.h"

TirParVector::TirParVector()
{
}

TirParVector::~TirParVector()
{
}

double * TirParVector::GetVector()
{
	doc = LoadConfig();//load
	root = doc.RootElement();  //root
	child = root->FirstChildElement();
	int num;//元素序号
	string v;//数据类型
	int flag;//判断标志	
	flag = 0;//未找到数据类型
	for (; child != NULL; child = child->NextSiblingElement())
	{
		v = child->Value();//child
						   //cout << v << endl;
		while (v == "TirParVector")//判断类型
		{
			flag = 1;//找到数据类型，但未找到名为name的数据
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//找到名为name的数据
					TiXmlElement *k1 = key->FirstChildElement();//len
					len = atoi(k1->GetText());
					//cout << len << endl;
					TiXmlElement *k2 = k1->NextSiblingElement();//value
					string text(k2->GetText());//数据，cfg字符串
											   //cout << text << endl;
					for (int i = 0; i < len; i++)
					{
						if (text[i] == ',' || text[i] == ';')
						{
							text[i] = ' ';
							//逗号或分号形式分隔元素转换为空格形式分隔元素
						}
					}					
					stringstream ss(text);//分解字符串
					vector<double> arr;//存储分解完的字符串
					double temp;
					num = 0;
					while (ss >> temp)
					{
						arr.push_back(temp);//压栈
						num++;//元素个数=压栈次数
					}
					vec = new double[num];//new parseq
					for (int i = 0; i < num; i++)
					{
						vec[i] = arr.at(i);
						cout << vec[i] << " ";
					}
					cout << endl;
					arr.clear();
					break;
				}
			}
			break;
		}
	}
	if (flag == 0)
		cout << "Couldn't find the data type: TirParVector." << endl;
	else if (flag == 1)
		cout << "Couldn't find the data : " << name << endl;
	return vec;//返回double * vec
}

double TirParVector::GetElement(int n)
{
	vec = GetVector();
	for (int i = 0; i < n; i++)
	{
		element = vec[i];
	}
	cout << element << endl;
	return element;
}

int TirParVector::SetVector(double * vec, int i_len)
{
	//向量长度转换为string s_len
	stringstream ss;
	ss << i_len;
	string s_len = ss.str();
	ss.str("");//清除缓冲
			   //cout << s_len << endl;

			   //向量元素值转换为string s_value
	string s_value;
	for (int i = 0; i < i_len; i++)
	{
		ss << *vec;
		string temp = ss.str();
		ss.str("");//清除缓冲
				   //cout << temp << endl;
		s_value = s_value + temp + " ";
		vec++;
	}
	//cout << s_value << endl;

	doc = LoadConfig();//load
	root = doc.RootElement();  //root
	child = root->FirstChildElement();
	string v;//数据类型
	int flag;//判断标志	
	flag = 0;//未找到数据类型
	for (; child != NULL; child = child->NextSiblingElement())
	{
		v = child->Value();//child
						   //cout << v << endl;
		while (v == "TirParVector")//判断类型
		{
			flag = 1;//找到数据类型，但未找到名为name的数据
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//找到名为name的数据	
							 //Set修改节点值：先删除原节点再新增修改后节点
					TiXmlElement *k1 = key->FirstChildElement();//len
					TiXmlElement *k2 = k1->NextSiblingElement();//value										
					key->RemoveChild(k1);//删除节点k1(len)
					key->RemoveChild(k2);//删除节点k2(value)
					TiXmlElement *k1new = new TiXmlElement("len");//新增同名节点len
					TiXmlElement *k2new = new TiXmlElement("value");//新增同名节点value
					key->LinkEndChild(k1new);//连接节点k1至key的子节点
					key->LinkEndChild(k2new);//连接节点k2至key的子节点
					const char* k1strc = s_len.c_str();
					const char* k2strc = s_value.c_str();
					TiXmlText *text_k1new = new TiXmlText(k1strc);//k1节点的len值为s_len.c_str()
					TiXmlText *text_k2new = new TiXmlText(k2strc);//k2节点的value值为s_value.c_str()
					k1new->LinkEndChild(text_k1new);//连接text节点至k1new节点
					k2new->LinkEndChild(text_k2new);//连接text节点k2new节点
					cout << k1new->GetText() << endl;
					cout << k2new->GetText() << endl;
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
		cout << "Set " << name << "[" << s_len << "]" << "=" << s_value << " successfully." << endl;
		return 1;
	}
	else
		return 0;
}

int TirParVector::SetElement(int n, double v)
{
	vec = GetVector();
	for (int i = 0; i < n; i++)
	{
		vec[i] = v;
	}
	SetVector(vec, len);
	return 0;
}

TirParVector TirParVector::Copy()
{
	return TirParVector();
}