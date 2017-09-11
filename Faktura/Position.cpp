#include "Position.h"

Position::Position()
{
	this->number = 1;
	this->name = "-------no_input--------";
	this->quantity = 1;
	this->unit = "szt.";
	this->price = 1;
	this->value = this->quantity * this->price;
	this->vat = 23;
	this->vatValue = this->value * this->vat / 100;
	this->ValueWithVat = this->value + this->vatValue;
}

Position::Position(int num, string nam, int q, string un, double pri, double v)
{
	this->number = num;
	this->name = nam;
	this->quantity = q;
	this->unit = un;
	this->price = pri;
	this->value = this->quantity * this->price;
	this->vat = v;
	this->vatValue = this->value * this->vat / 100;
	this->ValueWithVat = this->value + this->vatValue;
}

void Position::setNumber(int num) { this->number = num; }
void Position::setName(string nam) { this->name = nam; }
void Position::setQuantity(int quant) { this->quantity = quant; }
void Position::setUnit(string un) { this->unit = un; }
void Position::setPrice(double p) { this->price = p; }
void Position::setVat(double v) { this->vat = v; }
void Position::calculate(){
	this->value = this->quantity * this->price;
	this->vatValue = this->value *this->vat / 100;
	this->ValueWithVat = this->value + this->vatValue;
}

int Position::getNumber() { return  this->number; }
string Position::getName() { return this->name; }
int Position::getQuantity() { return this->quantity; }
string Position::getUnit() { return this->unit; }
double Position::getPrice() { return this->price; }
double Position::getValue() { return this->value; }
double Position::getVat() { return this->vat; }
double Position::getVatValue(){return this->vatValue;}
double Position::getValueWithWat(){return this->ValueWithVat;}
string Position::getPosition(){ return this->name; }


//cout << setprecision(2) << whatever;
//cout << round(x * 10000) / 10000.0;