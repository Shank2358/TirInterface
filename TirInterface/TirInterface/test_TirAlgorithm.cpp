#include "stdafx.h"
#include "TirInterface.h"
#include "test_TirInterface.h"

void test_TirAlgorithm()
{
	cout << "****************" << " TirAlgorithm Test " << "****************" << endl;
	cout << "  **" << "Test TirAlgorithm constructor." << endl;
	myProc * proc = new myProc();
	/*测试GetPara函数。因为参数不知道怎么压入栈，因此“vec1”测不出来。此外，依赖于GetParaByName函数。
	仍然存在的问题：获取vector中的第一个元素"GaussianFilter"输出正常，但是第二个、第三个无法找到。可能是因为对vector的理解不到位。*/
	TirBase *b_test = proc->GetPara("BilateralFiler", "GaussFilterGamma");
	/*测试SetPara函数。依赖于GetParaByName和SetParaByName函数*/
	int result = proc->SetPara("BilateralFiler", "GaussFilterGamma", proc->b2);
}
