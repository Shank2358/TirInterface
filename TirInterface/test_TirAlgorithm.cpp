#include "stdafx.h"
#include "TirInterface.h"
#include "test_TirInterface.h"

void test_TirAlgorithm()
{
	cout << "****************" << " TirAlgorithm Test " << "****************" << endl;
	cout << "  **" << "Test TirAlgorithm constructor." << endl;
	myProc * proc = new myProc();
	/*����GetPara��������Ϊ������֪����ôѹ��ջ����ˡ�vec1���ⲻ���������⣬������GetParaByName������
	��Ȼ���ڵ����⣺��ȡvector�еĵ�һ��Ԫ��"GaussianFilter"������������ǵڶ������������޷��ҵ�����������Ϊ��vector����ⲻ��λ��*/
	TirBase *b_test = proc->GetPara("BilateralFiler", "GaussFilterGamma");
	/*����SetPara������������GetParaByName��SetParaByName����*/
	int result = proc->SetPara("BilateralFiler", "GaussFilterGamma", proc->b2);
}
