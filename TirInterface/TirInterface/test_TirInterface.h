#pragma once
#ifndef _TEST_TIRINTERFACE_H_
#define _TEST_TIRINTERFACE_H_

#include "TirInterface.h"

extern void test_TirBase();
extern void test_TirParVector();
extern void test_TirParMatrix();
extern void test_TirParString();
extern void test_TirStringPath();

class myProc :public TirAlgorithm
{
public:
	TirParVector v;
	TirParMatrix m;
	TirParString s;

	TirProcessor GaussianFilter;
	TirProcessor MedianFilter;
	TirProcessor BilateralFiler;
	TirBase *b2;
public:
	myProc::myProc() {
		v;
		m;
	    v.name = "GaussFilterGamma";
		m.name = "GaussFilterPattern";
		
		pv.push_back(&v);
		pv.push_back(&m);
	
		GaussianFilter;
		MedianFilter;
		BilateralFiler;
		GaussianFilter.name = "GaussianFilter";
		MedianFilter.name = "MedianFilter";
		BilateralFiler.name = "BilateralFiler";
		procvec.push_back(&BilateralFiler);
		procvec.push_back(&MedianFilter);
		procvec.push_back(&BilateralFiler);
	}
	myProc::~myProc()
	{
	}
};
extern void test_TirProcessor();
extern void test_TirAlgorithm();

#endif _TEST_TIRINTERFACE_H_