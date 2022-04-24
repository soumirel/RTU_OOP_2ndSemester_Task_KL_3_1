//TODO Вывод дерева иерархии объектов через таб
//TODO Вывод дерева иерархии с готовностями
//TODO Метод установки готовности объекта

#include "Cl_application.h"
#include "Cl_branch.h"
#include "Cl_branch_2.h"
#include "Cl_branch_3.h"
#include "Cl_branch_4.h"
#include "Cl_branch_5.h"

Cl_application::Cl_application(Cl_base* parentPtr)
{
	//Использование сетеров обусловленно закрытостью полей
	Cl_base::root->setParent(parentPtr);
	Cl_base::root->setName("root");
	Cl_base::root->setReadiness(1);
}

//Изменено для КЛ_3_1
void Cl_application::buildTree()
{
	string parentName, childName;
	int classNumber;

	cin >> parentName;

	// Головной объект
	Cl_base* head = new Cl_base(parentName);
	cin >> parentName;
	while (parentName != "endtree") {

		cin >> childName >> classNumber;

		// Создание дочернего объекта определённого класса
		// определяемого введённым номером
		switch (classNumber)
		{
		case 2:
		{
			Cl_base* child = new Cl_branch(childName, root->getObjectPtr(parentName));
			break;
		}

		case 3:
		{
			Cl_base* child = new Cl_branch_2(childName, root->getObjectPtr(parentName));
			break;
		}

		case 4:

		{
			Cl_base* child = new Cl_branch_3(childName, root->getObjectPtr(parentName));
			break;
		}

		case 5:
		{
			Cl_base* child = new Cl_branch_4(childName, root->getObjectPtr(parentName));
			break;
		}

		case 6:
		{
			Cl_base* child = new Cl_branch_5(childName, root->getObjectPtr(parentName));
			break;
		}

		}
		cin >> parentName;
	}
}

//Функция запуска ввода готовностей объектов
void Cl_application::enterReadiness()
{
	string objectName;
	long long numericReadiness;
	while (cin >> objectName >> numericReadiness)
	{
		(root->getObjectPtr(objectName))->setReadiness(numericReadiness);
	}
}

int Cl_application::execApp()
{
	// Вывод построенного дерева;
	cout << "Object tree";
	root->childrenList.at(0)->printTree(false);
	//Вывод дерева и готовностей объектов
	cout << "\nThe tree of objects and their readiness";
	root->childrenList.at(0)->printTree(true);
	return 0;
}
