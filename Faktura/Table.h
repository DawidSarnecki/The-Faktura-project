#ifndef TABLE_H  
#define TABLE_H
#pragma once
#include "Position.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Table
{

private:
	string * topTable;
	vector<Position> listPos;
	double total;

public:
	friend class Menu;
	Table();
	string getInfo();

	~Table();
};
#endif
