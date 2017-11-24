#include "stdafx.h"
#include "TirInterface.h"

TirProcessor::TirProcessor()
{
}

TirProcessor::~TirProcessor()
{
}

TirBase TirProcessor::GetParaByName(string name)
{
	return TirBase();
}

int TirProcessor::SetParaByName(string name, TirBase b)
{
	return 0;
}

void TirProcessor::Process(Mat ** img_in, Mat ** img_out)
{

}