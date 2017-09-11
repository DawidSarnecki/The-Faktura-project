
#pragma once
#include <windows.h>
#include <time.h>
#include "Menu.h"
#include <iostream>
using namespace std;

void SetWindow(int Width, int Height);


int main() {
	SetWindow(100, 50);
	
	Menu faktura;

	faktura.~Menu();

	system("pause");
	return 0;
}


void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

