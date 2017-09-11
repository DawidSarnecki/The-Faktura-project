#ifndef POSITION_H  
#define POSITION_H
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Position
{
private:
	int number;
	string name;
	int quantity;
	string unit;
	double price;
	double value;
	double vat;
	double vatValue;
	double ValueWithVat;
public:
	Position();
	Position(int num, string nam, int q, string un, double pri, double v);
	void setNumber(int num);
	void setName(string nam);
	void setQuantity(int quant);
	void setUnit(string unit);
	void setPrice(double p);
	void setVat(double v);
	void calculate();

	int getNumber();
	string getName ();
	int getQuantity();
	string getUnit();
	double getPrice();
	double getValue();
	double getVat();
	double getVatValue();
	double getValueWithWat();
	string getPosition();
	
};
#endif
