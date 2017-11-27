#include "stdafx.h"
#include "TirInterface.h"

TirStringPath::TirStringPath()
{
	cout << "TirStringPath constructor called." << endl;
}

TirStringPath::~TirStringPath()
{
	cout << "TirStringPath constructor called." << endl;
}

string TirStringPath::GetPathWin()
{
	path_win = GetString();
	size_t position1 = path_win.find("/");//find first "/"
	while (position1 != string::npos)
	{
		path_win.replace(position1, 1, "\\\\");
		position1 = path_win.find("/", position1 + 1);
	}
	cout << name << "(win) = " << path_win << endl;
	return path_win;
}

string TirStringPath::GetPathNix()
{
	path_nix = GetString();
	size_t postion2 = path_nix.find("/");//find first "/"
	while (postion2 != string::npos)
	{
		path_nix.replace(postion2, 1, "/");
		postion2 = path_nix.find("/", postion2 + 1);
	}
	cout << name << "(nix) = " << path_nix << endl;
	return path_nix;
}

string TirStringPath::GetFileName()
{
	string path = GetString();
	int i = path.find('.', 0);
	int m = path.rfind('/', path.length());
	if (m != string::npos)
	{
		file_name = path.substr(m + 1, i - m - 1);
	}
	cout << name << "(filename) = " << file_name << endl;
	return file_name;
}

string TirStringPath::GetFileExt()
{
	string path = GetString();
	int i = path.find('.', 0);
	if (i != string::npos)
	{
		file_ext = path.substr(i + 1, path.length());//ext从i+1开始，.ext从i开始
	}
	cout << name << "(ext) = " << file_ext << endl;
	return file_ext;
}

void __inline vSplitString(string strSrc, vector<string>& vecDest, char cSeparator)
{
	if (strSrc.empty())
		return;
	string::size_type size_pos = 0;
	string::size_type size_prev_pos = 0;

	while ((size_pos = strSrc.find_first_of(cSeparator, size_pos)) != string::npos)
	{
		string strTemp = strSrc.substr(size_prev_pos, size_pos - size_prev_pos);

		vecDest.push_back(strTemp);
		size_prev_pos = ++size_pos;
	}
	vecDest.push_back(&strSrc[size_prev_pos]);
};
int TirStringPath::IsLegal()
{
	string strVal = GetPathWin();
	vector<string> SplitVec;
	vSplitString(strVal, SplitVec, '\\');
	if (SplitVec.size()>0)
	{
		if (SplitVec[0].size() != 2)
			goto loop;
		const char *pan = SplitVec[0].c_str();
		{
			if ((*pan >= 'a'&&*pan <= 'z') || (*pan >= 'A'&&*pan <= 'Z'))
			{
				cout << "盘符:" << *pan << ",正常" << endl;
			}
			else
			{
				goto loop;
			}
		}
		int npos;
		for (int i = 1; i < SplitVec.size(); i++)
		{
			npos = SplitVec[i].find('\\');
			if (npos>0)
			{
				goto loop;
			}
			npos = SplitVec[i].find('/');
			if (npos>0)
			{
				goto loop;
			}
			npos = SplitVec[i].find(':');
			if (npos>0)
			{
				goto loop;
			}
			npos = SplitVec[i].find('*');
			if (npos>0)
			{
				goto loop;
			}
			npos = SplitVec[i].find('?');
			if (npos>0)
			{
				goto loop;
			}
			npos = SplitVec[i].find('"');
			if (npos>0)
			{
				goto loop;
			}
			npos = SplitVec[i].find('<');
			if (npos>0)
			{
				goto loop;
			}
			npos = SplitVec[i].find('>');
			if (npos>0)
			{
				goto loop;
			}
			npos = SplitVec[i].find('|');
			if (npos>0)
			{
				goto loop;
			}
		}
		cout << strVal << "Path is legal." << endl;
		return 1;
	}
	else
	{
		goto loop;
	}
loop:
	cout << strVal << "Path is illegal." << endl;
	return -1;
}

int TirStringPath::IsExist()
{
	string path = GetString();
	string::size_type idx;
	idx = path.find(file_name);//在path中查找filename
	if (idx == string::npos)//不存在
	{
		cout << "Non-Exist." << endl;
		return -1;
	}
	else//存在
	{
		cout << "Exist." << endl;
		return 1;
	}
}
