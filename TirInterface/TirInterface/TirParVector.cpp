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
	int num;//Ԫ�����
	string v;//��������
	int flag;//�жϱ�־	
	flag = 0;//δ�ҵ���������
	for (; child != NULL; child = child->NextSiblingElement())
	{
		v = child->Value();//child
						   //cout << v << endl;
		while (v == "TirParVector")//�ж�����
		{
			flag = 1;//�ҵ��������ͣ���δ�ҵ���Ϊname������
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//�ҵ���Ϊname������
					TiXmlElement *k1 = key->FirstChildElement();//len
					len = atoi(k1->GetText());
					//cout << len << endl;
					TiXmlElement *k2 = k1->NextSiblingElement();//value
					string text(k2->GetText());//���ݣ�cfg�ַ���
											   //cout << text << endl;
					for (int i = 0; i < len; i++)
					{
						if (text[i] == ',' || text[i] == ';')
						{
							text[i] = ' ';
							//���Ż�ֺ���ʽ�ָ�Ԫ��ת��Ϊ�ո���ʽ�ָ�Ԫ��
						}
					}					
					stringstream ss(text);//�ֽ��ַ���
					vector<double> arr;//�洢�ֽ�����ַ���
					double temp;
					num = 0;
					while (ss >> temp)
					{
						arr.push_back(temp);//ѹջ
						num++;//Ԫ�ظ���=ѹջ����
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
	return vec;//����double * vec
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
	//��������ת��Ϊstring s_len
	stringstream ss;
	ss << i_len;
	string s_len = ss.str();
	ss.str("");//�������
			   //cout << s_len << endl;

			   //����Ԫ��ֵת��Ϊstring s_value
	string s_value;
	for (int i = 0; i < i_len; i++)
	{
		ss << *vec;
		string temp = ss.str();
		ss.str("");//�������
				   //cout << temp << endl;
		s_value = s_value + temp + " ";
		vec++;
	}
	//cout << s_value << endl;

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
		while (v == "TirParVector")//�ж�����
		{
			flag = 1;//�ҵ��������ͣ���δ�ҵ���Ϊname������
			key = child->FirstChildElement();
			for (; key != NULL; key = key->NextSiblingElement())
			{
				while (key->Value() == name)
				{
					flag = 2;//�ҵ���Ϊname������	
							 //Set�޸Ľڵ�ֵ����ɾ��ԭ�ڵ��������޸ĺ�ڵ�
					TiXmlElement *k1 = key->FirstChildElement();//len
					TiXmlElement *k2 = k1->NextSiblingElement();//value										
					key->RemoveChild(k1);//ɾ���ڵ�k1(len)
					key->RemoveChild(k2);//ɾ���ڵ�k2(value)
					TiXmlElement *k1new = new TiXmlElement("len");//����ͬ���ڵ�len
					TiXmlElement *k2new = new TiXmlElement("value");//����ͬ���ڵ�value
					key->LinkEndChild(k1new);//���ӽڵ�k1��key���ӽڵ�
					key->LinkEndChild(k2new);//���ӽڵ�k2��key���ӽڵ�
					const char* k1strc = s_len.c_str();
					const char* k2strc = s_value.c_str();
					TiXmlText *text_k1new = new TiXmlText(k1strc);//k1�ڵ��lenֵΪs_len.c_str()
					TiXmlText *text_k2new = new TiXmlText(k2strc);//k2�ڵ��valueֵΪs_value.c_str()
					k1new->LinkEndChild(text_k1new);//����text�ڵ���k1new�ڵ�
					k2new->LinkEndChild(text_k2new);//����text�ڵ�k2new�ڵ�
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