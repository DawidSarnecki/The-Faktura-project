#ifndef MENU_H  
#define MENU_H 
#pragma once
#include "Company.h"]
#include "Invoice.h"
#include "DataBase.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Menu 
{
public:
	Menu();
	void showMenu();
	void addInvoice();
	void addCompany();

	//invoice menu
	void menuInvoice(int n);
	void menuInvData(int n, DataBase *wsk);
	void menuTable(Table* tab);
	void menuPosition(Position* pos, Table* tab);

	//company menu
	void menuCompany(int n);
	void menuCompany(int n, Company* comp, char wich);

	//database menu
	void menuBase();
	void menuHistory();

	~Menu();
};
#endif
