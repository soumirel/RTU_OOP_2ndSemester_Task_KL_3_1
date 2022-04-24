#include "Cl_application.h"

int main()
{
	Cl_application AppObject;
	AppObject.buildTree();
	AppObject.enterReadiness();
	return AppObject.execApp();
}