#include "stdafx.h"
#include "TirInterface.h"

void test_TirParVector()
{
	cout << "****************" << " TirParVector Test " << "****************" << endl;
	cout << "  **" << "Test TirParVector constructor." << endl;
	TirParVector* v = new TirParVector();
	v->doc = v->LoadConfig();
	v->name = "vec1";
	v->type = "TirParVector";
	cout << "  **" << "Test GetVector()." << endl;
	double* vec = v->GetVector();
	cout << "  **" << "Test GetElement()." << endl;
	double ele_vec = v->GetElement(2);
	cout << "  **" << "Test SetVector()." << endl;
	double arr[] = { 5.55,6.66,7.77,8.88,9.99,10.11 };
	int len = 6;
	double* vec_new = arr;
	v->SetVector(vec_new, len);
	cout << "  **" << "Test SetElement()." << endl;
	v->SetElement(1, 9.99);
	cout << "  **" << "Test Copy()." << endl;
	TirParVector v_new;
	v_new = v->Copy();
	cout << "  **" << "Test TirParVector destructor." << endl;
	v->~TirParVector();
}