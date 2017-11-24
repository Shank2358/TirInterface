#pragma once
#ifndef _TIRINTERFACE_H_
#define _TIRINTERFACE_H_

#include"tinyxml.h"
#include"stdlib.h"
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<windows.h>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

class TirBase
{
	//Data	
public:
	string name;
	string type;
	TiXmlDocument doc;
protected:
	TiXmlElement* root;
	TiXmlElement* child;
	TiXmlElement* key;
	string text;
	//Methods
public:
	TirBase();
	~TirBase();
	TiXmlDocument LoadConfig();
	int SaveConfig();
	int IsName();
	int IsType();
};

class TirParVector : public TirBase
{
	//Data
protected:
	double* vec;
	int len;
	double element;
	//Methods
public:
	TirParVector();
	~TirParVector();
	double* GetVector();
	double GetElement(int n);
	int SetVector(double* vec, int len);
	int SetElement(int n, double v);
	TirParVector Copy();
};

class TirParMatrix : public TirBase
{
	//Data
protected:
	double** matrix;
	int rows;
	int cols;
	double element;
	//Methods
public:
	TirParMatrix();
	~TirParMatrix();
	double** GetMatrix();
	double GetElement(int x, int y);
	int SetMatrix(double** matrix, int rows, int cols);
	int SetElement(int x, int y, double v);
	TirParMatrix Copy();
};

class TirParString : public TirBase
{
	//Data
protected:
	string str;
private:
	char* strDest;
	const char* strSrc;
	//Methods
public:
	TirParString();
	~TirParString();
	string GetString();
	int SetString(string str);
	char * StrCopy(char *strDest, const char *strSrc);
};

class TirStringPath : public TirParString
{
	//Data
protected:
	string path_win;
	string path_nix;
	string file_name;
	string file_ext;
	//Methods
public:
	TirStringPath();
	~TirStringPath();
	string GetPathWin();
	string GetPathNix();
	string GetFileName();
	string GetFileExt();
private:
	int IsLegal();
	int IsExist();
};

class TirProcessor : public TirStringPath
{
	//Data
protected:
	Mat** img_in;
	Mat** img_out;
	//Methods
public:
	TirProcessor();
	~TirProcessor();
	TirBase GetParaByName(string name);
	int SetParaByName(string name, TirBase b);
	virtual void Process(Mat** img_in, Mat** img_out);
};

class TirAlgorithm : public TirProcessor
{
	//Data
protected:
	string procname;
	TirProcessor** proc;//£¿
	int num;
private:
	Mat** imgbuff;
	//Methods
public:
	TirAlgorithm();
	~TirAlgorithm();
	void Loadproc(string path);
	void Unloadproc();
	TirBase GetPara(string procname, string paraname);
	int SetPara(string procname, string paraname, TirBase* b);
	TirProcessor** GetProcByName(string procname);
	int SetProcByName(string procname, TirProcessor** proc);
};

#endif _TIRINTERFACE_H_
