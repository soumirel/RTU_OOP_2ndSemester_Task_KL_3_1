#ifndef CL_BASE_H
#define CL_BASE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cl_base {
private:
	// Имя объекта
	string objectName = "";
	// Указатель на родителя объекта
	Cl_base* parentPtr;
	bool readiness = false; //Добавлено для КЛ_3_1
	

public:
	//Объект root - "родитель" всех объектов
	static Cl_base* root;
	//Вектор указателей дочерних объектов
	vector<Cl_base*> childrenList;

	//Конструкторы
	Cl_base() { parentPtr = nullptr; };
	Cl_base(string objectName, Cl_base* parentPtr = nullptr);

	//Сетеры
	void setName(string objectName);
	void setParent(Cl_base* parentPtr);
	void setReadiness(long long numericReadiness);

	//Гетеры
	Cl_base* getParent();
	string getName();
	bool getReadiness();

	//Получение указателя на объект через его имя
	Cl_base* getObjectPtr(string name);

	//Вывод дерева объектов
	void printTree(bool isPrintReadiness, unsigned tabLevel = 0);
};

#endif