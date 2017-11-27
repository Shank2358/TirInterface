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
	int flag;//�жϱ�־	
	flag = 0;//δ�ҵ���������
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
					TiXmlElement *k1 = key->FirstChildElement();//rows
					r = k1->GetText();
					rows = stoi(r);			
					TiXmlElement *k2 = k1->NextSiblingElement();//cols
					c = k2->GetText();
					cols = stoi(c);
					TiXmlElement *k3 = k2->NextSiblingElement();//value
					string text(k3->GetText());//���ݣ�xml�ַ���
					for (int i = 0; i < text.length(); i++)
					{
						if (text[i] == ',' || text[i] == ';')
							text[i] = ' ';//���Ż�ֺ���ʽ�ָ�Ԫ��ת��Ϊ�ո���ʽ�ָ�Ԫ��
					}
					matrix = new double *[rows];//new matrix
					stringstream ss(text);//�ֽ��ַ���
					vector<double> arr;//�洢�ֽ�����ַ���
					double temp;
					while (ss >> temp)
						arr.push_back(temp);//ѹջ
					int f = 0;//arr�±�
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
							cout << matrix[i][j] << " ";//���
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
	//��������ת��Ϊstring s_rows
	stringstream ss;
	ss << i_rows;
	string s_rows = ss.str();
	ss.str("");//�������
			   //cout << s_rows << endl;			   

			   //��������ת��Ϊstring s_cols
	ss << i_cols;
	string s_cols = ss.str();
	ss.str("");//�������
			   //cout << s_cols << endl;

			   //����Ԫ��ֵת��Ϊstring s_value
	string s_value;
	for (int i = 0; i < i_rows; i++)
	{
		for (int j = 0; j < i_cols; j++)
		{
			ss << matrix[i][j];
			string temp = ss.str();
			ss.str("");//�������
					   //cout << temp << endl;
			s_value = s_value + temp + " ";
		}
	}
	TiXmlElement* root = doc.RootElement();//root
	TiXmlElement* child = root->FirstChildElement();
	string v;//��������
	int flag;//�жϱ�־	
	flag = 0;//δ�ҵ���������
	for (; child != NULL; child = child->NextSiblingElement())
	{
		v = child->Value();//child
						   //cout << v << endl;
		while (v == "TirParMatrix")//�ж�����
		{
			flag = 1;//�ҵ��������ͣ���δ�ҵ���Ϊname������
			TiXmlElement* key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//�ҵ���Ϊname������	
							 //Set�޸Ľڵ�ֵ����ɾ��ԭ�ڵ��������޸ĺ�ڵ�
					TiXmlElement *k1 = key->FirstChildElement();//rows
					TiXmlElement *k2 = k1->NextSiblingElement();//cols	
					TiXmlElement *k3 = k2->NextSiblingElement();//value										
					key->RemoveChild(k1); //ɾ���ڵ�k1(rows)
					key->RemoveChild(k2); //ɾ���ڵ�k2(cols)
					key->RemoveChild(k3); //ɾ���ڵ�k2(value)
					TiXmlElement *k1new = new TiXmlElement("rows");//����ͬ���ڵ�len
					TiXmlElement *k2new = new TiXmlElement("cols");//����ͬ���ڵ�value
					TiXmlElement *k3new = new TiXmlElement("value");//����ͬ���ڵ�value
					key->LinkEndChild(k1new);//���ӽڵ�k1��key���ӽڵ�
					key->LinkEndChild(k2new);//���ӽڵ�k2��key���ӽڵ�
					key->LinkEndChild(k3new);//���ӽڵ�k2��key���ӽڵ�
					const char* k1strc = s_rows.c_str();
					const char* k2strc = s_cols.c_str();
					const char* k3strc = s_value.c_str();
					TiXmlText *text_k1new = new TiXmlText(k1strc);//k1�ڵ��lenֵΪs_len.c_str()
					TiXmlText *text_k2new = new TiXmlText(k2strc);//k2�ڵ��valueֵΪs_value.c_str()
					TiXmlText *text_k3new = new TiXmlText(k3strc);//k2�ڵ��valueֵΪs_value.c_str()
					k1new->LinkEndChild(text_k1new);//����text�ڵ�
					k2new->LinkEndChild(text_k2new);//����text�ڵ�
					k3new->LinkEndChild(text_k3new);//����text�ڵ�
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