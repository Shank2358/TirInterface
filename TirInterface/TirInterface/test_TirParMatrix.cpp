#include "stdafx.h"
#include "TirInterface.h"

void test_TirParMatrix() 
{
	cout << "****************" << " TirPMatrix Test " << "****************" << endl;
	cout << "  **" << "Test TirParMatrix constructor." << endl;
	TirParMatrix* m = new TirParMatrix();
	m->doc = m->LoadConfig();
	m->name = "mat1";
	m->type = "TirParMatrix";
	cout << "  **" << "Test GetMatrix()." << endl;
	double** mat = m->GetMatrix();
	cout << "  **" << "Test GetElement()." << endl;
	double ele_mat = m->GetElement(2,2);
	cout << "  **" << "Test SetMatrix()." << endl;
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
	m->SetMatrix(matrix, i_rows, i_cols);
	cout << "  **" << "Test SetElement()." << endl;
	m->SetElement(1, 1, 9.99);
	cout << "  **" << "Test Copy()." << endl;
	TirParMatrix m_new;
	m_new = m->Copy();
	cout << "  **" << "Test TirParMatrix destructor." << endl;
	m->~TirParMatrix();
}