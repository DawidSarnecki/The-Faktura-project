#include "Table.h"

Table::Table()
{
	// reserve memory on min. 10 positions
	this->listPos.reserve(10);

	// initializing positions of table
	this->listPos.push_back(Position());
	// initializing values in topTable
	this->topTable = new string[9];
	this->topTable[0] = " Lp.";
	this->topTable[1] = "\t\tNazwa\t";
	this->topTable[2] = "\tIlosc";
	this->topTable[3] = "\tjm";
	this->topTable[4] = "\tCena netto";
	this->topTable[5] = "\tWartosc netto";
	this->topTable[6] = "\tStawka VAT";
	this->topTable[7] = "\tkwota VAT";
	this->topTable[8] = "\tWartosc brutto";
}

string Table::getInfo() {
	ostringstream info;
	string line;
	for (int i = 0; i < 127; i++)
		line += "-";
	info << line << endl;
	for (int i = 0; i < 9; i++)
		info << topTable[i];
	info << endl;
	this->total = 0;
	for (int j = 0; j <this->listPos.size(); ++j) {
		total += listPos[j].getValueWithWat();
		info << line << endl;
		info << " " << j + 1 << ".\t" << listPos[j].getName() << "\t" << listPos[j].getQuantity() << "\t"
			<< listPos[j].getUnit() << "\t" << listPos[j].getPrice() << "\t\t" << listPos[j].getValue() << "\t\t"
			<< listPos[j].getVat() << "\t\t" << listPos[j].getVatValue() << "\t\t" << listPos[j].getValueWithWat() << endl;
	}
	info << line << endl;
	info << "  RAZEM DO ZAPLATY:      " << total << "   PLN BRUTTO" << endl;
	info << line << endl;	
	return (info.str());
}

Table::~Table(){}