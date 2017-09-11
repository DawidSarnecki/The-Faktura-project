#ifndef DATABASE_H  
#define DATABASE_H 
#pragma once
#include "Company.h"
#include "Invoice.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//singleton pattern
class DataBase
{
	friend class Menu;
private:
	DataBase();
	//create a vector to store Companys
	vector<Company> vecComp;

	// create a vector to store Invoices
	vector<Invoice> vecInvo;
	Date dat;

public:
	static DataBase &getSingleton() {
		static DataBase singleton;
		return singleton;
	}

	void showBase();
	void showHistory();
	~DataBase();
};

#endif
