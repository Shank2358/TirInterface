#include "stdafx.h"
#include "TirInterface.h"

void test_TirParString()
{
	cout << "****************" << " TirParString Test " << "****************" << endl;
	cout << "  **" << "Test TirParString constructor." << endl;
	TirParString* s = new TirParString();
	s->doc = s->LoadConfig();
	s->name = "str1";
	s->type = "TirParString";
	cout << "  **" << "Test GetString()." << endl;
	string s1 = s->GetString();
	cout << "  **" << "Test SetString()." << endl;
	string s2 = "abcdefg";
	s->SetString(s2);
	cout << "  **" << "Test Copy()." << endl;
	TirParString s_new;
	s_new = s->Copy();
	cout << "  **" << "Test TirParVector destructor." << endl;
	s->~TirParString();
}