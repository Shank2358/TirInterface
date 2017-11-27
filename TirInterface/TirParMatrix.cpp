#include "stdafx.h"
#include "TirInterface.h"

TirParMatrix::TirParMatrix()
{
	cout << "TirParMatrix constructor called." << endl;
}

TirParMatrix::~TirParMatrix()
{
	cout << "TirParMatrix destructor called." << endl;
}

double ** TirParMatrix::GetMatrix()
{
	root = doc.RootElement();  //root  
	child = root->FirstChildElement();
	string r;//rows (string)
	string c;//cols (string)
	int flag;//判断标志	
	flag = 0;//未找到数据类型
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
					TiXmlElement *k1 = key->FirstChildElement();//rows
					r = k1->GetText();
					rows = stoi(r);			
					TiXmlElement *k2 = k1->NextSiblingElement();//cols
					c = k2->GetText();
					cols = stoi(c);
					TiXmlElement *k3 = k2->NextSiblingElement();//value
					string text(k3->GetText());//数据，xml字符串
					for (int i = 0; i < text.length(); i++)
					{
						if (text[i] == ',' || text[i] == ';')
							text[i] = ' ';//逗号或分号形式分隔元素转换为空格形式分隔元素
					}
					matrix = new double *[rows];//new matrix
					stringstream ss(text);//分解字符串
					vector<double> arr;//存储分解完的字符串
					double temp;
					while (ss >> temp)
						arr.push_back(temp);//压栈
					int f = 0;//arr下标
					for (int i = 0; i<rows; i++)
					{
						double *a = new double[cols];
						for (int j = 0; j < cols; j++)
						{
							a[j] = arr.at(f);
							f = f + 1;
						}
						matrix[i] = a;
					}
					cout << name << "[" << rows << "][" << cols << "] = " << endl;
					for (int i = 0; i < rows; i++)
					{
						for (int j = 0; j < cols; j++)
						{
							cout << matrix[i][j] << " ";//输出
						}
						cout << endl;
					}
					arr.clear();
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
		cout << "Couldn't find the data type: TirParMatrix." << endl;
	else if (flag == 1)
		cout << "Couldn't find the data : " << name << endl;
	return matrix;
}

double TirParMatrix::GetElement(int x, int y)
{
	matrix = GetMatrix();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			element = matrix[i][j];
		}
	}
	cout << name << "(" << x << "," << y << ") = " << element << endl;
	return element;
}

int TirParMatrix::SetMatrix(double ** matrix, int i_rows, int i_cols)
{
	//矩阵行数转换为string s_rows
	stringstream ss;
	ss << i_rows;
	string s_rows = ss.str();
	ss.str("");//清除缓冲
			   //cout << s_rows << endl;			   

			   //矩阵列数转换为string s_cols
	ss << i_cols;
	string s_cols = ss.str();
	ss.str("");//清除缓冲
			   //cout << s_cols << endl;

			   //矩阵元素值转换为string s_value
	string s_value;
	for (int i = 0; i < i_rows; i++)
	{
		for (int j = 0; j < i_cols; j++)
		{
			ss << matrix[i][j];
			string temp = ss.str();
			ss.str("");//清除缓冲
					   //cout << temp << endl;
			s_value = s_value + temp + " ";
		}
	}
	TiXmlElement* root = doc.RootElement();//root
	TiXmlElement* child = root->FirstChildElement();
	string v;//数据类型
	int flag;//判断标志	
	flag = 0;//未找到数据类型
	for (; child != NULL; child = child->NextSiblingElement())
	{
		v = child->Value();//child
						   //cout << v << endl;
		while (v == "TirParMatrix")//判断类型
		{
			flag = 1;//找到数据类型，但未找到名为name的数据
			TiXmlElement* key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//找到名为name的数据	
							 //Set修改节点值：先删除原节点再新增修改后节点
					TiXmlElement *k1 = key->FirstChildElement();//rows
					TiXmlElement *k2 = k1->NextSiblingElement();//cols	
					TiXmlElement *k3 = k2->NextSiblingElement();//value										
					key->RemoveChild(k1); //删除节点k1(rows)
					key->RemoveChild(k2); //删除节点k2(cols)
					key->RemoveChild(k3); //删除节点k2(value)
					TiXmlElement *k1new = new TiXmlElement("rows");//新增同名节点len
					TiXmlElement *k2new = new TiXmlElement("cols");//新增同名节点value
					TiXmlElement *k3new = new TiXmlElement("value");//新增同名节点value
					key->LinkEndChild(k1new);//连接节点k1至key的子节点
					key->LinkEndChild(k2new);//连接节点k2至key的子节点
					key->LinkEndChild(k3new);//连接节点k2至key的子节点
					const char* k1strc = s_rows.c_str();
					const char* k2strc = s_cols.c_str();
					const char* k3strc = s_value.c_str();
					TiXmlText *text_k1new = new TiXmlText(k1strc);//k1节点的len值为s_len.c_str()
					TiXmlText *text_k2new = new TiXmlText(k2strc);//k2节点的value值为s_value.c_str()
					TiXmlText *text_k3new = new TiXmlText(k3strc);//k2节点的value值为s_value.c_str()
					k1new->LinkEndChild(text_k1new);//连接text节点
					k2new->LinkEndChild(text_k2new);//连接text节点
					k3new->LinkEndChild(text_k3new);//连接text节点
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
		cout << "Set " << name << "[" << s_rows << "]" << "[" << s_cols << "] = "
			<< s_value << " successfully." << endl;
		return 1;
	}
	else
		return 0;
}

int TirParMatrix::SetElement(int x, int y, double v)
{
	matrix = GetMatrix();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			matrix[i][j] = v;
		}
	}
	SetMatrix(matrix, rows, cols);
	cout << "Set " << name << "(" << x << "," << y << ") = " << v << " successfully." << endl;
	return 0;
}

TirParMatrix TirParMatrix::Copy()
{
	TirParMatrix m;
	m.name = name;
	m.type = type;
	m.rows = rows;
	m.cols =cols;
	m.matrix = matrix;
	cout << "Copy OK!" << endl;
	return m;
}