// TirInterface.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "TirInterface.h"
#include "test_TirInterface.h"

int main()
{
	test_TirBase();
/*	//Vector
	b.name = "vec1";
	TirParVector v;
	v.doc = b.doc;
	v.name = b.name;
	//Get
	double* vec = v.GetVector();
	double ele_vec = v.GetElement(2);
	//Set
	double arr[] = { 5.55,6.66,7.77,8.88,9.99,10.11 };
	int len = 6;
	double* vec_new = arr;
	v.SetVector(vec_new, len);
	v.SetElement(1, 9.99);

	//Matrix	
	b.name = "mat1";
	TirParMatrix m;
	m.doc = b.doc;
	m.name = b.name;
	//Get
	double** mat = m.GetMatrix();
	double ele_mat = m.GetElement(2, 2);
	//Set
	int i_rows = 3;
	int i_cols = 2;
	double** matrix = new double*[i_rows];
	for (int i = 0; i < i_rows; i++)
	{
		matrix[i] = new double[i_cols];
	}
	matrix[0][0] = 1;	matrix[0][1] = 2;
	matrix[1][0] = 3;	matrix[1][1] = 4;
	matrix[2][0] = 5;	matrix[2][1] = 6;
	for (int i = 0; i < i_rows; i++)
	{
		for (int j = 0; j < i_cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	m.SetMatrix(matrix, i_rows, i_cols);
	m.SetElement(1, 1, 9.99);
	//m.GetElement(1, 1);

	//String
	b.name = "str1";
	TirParString s;
	s.doc = b.doc;
	s.name = b.name;
	string str = s.GetString();
	s.SetString("abcdefg");
	string str1 = s.GetString();

	//Algorithm
	TirAlgorithm al;
	//al.Loadproc("E:\\visual studio 2017\\Projects\\FirstCOM\\x64\\Release\\FirstCOM.dll");
	//al.GetProcByName("addfun");
	//al.Unloadproc();
	//FreeLibrary(hdll);
	//al.GetProcByName("addfun");
*/
	return 0;
}
