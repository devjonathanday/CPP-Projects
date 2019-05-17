#include<iostream>
#include <string>

#include "IBox.h"
#include "IFactory.h"
#include "Factory.h"
#include "Functions.h"
#include"FallingFactory.h"
#include<time.h>

static SimpleSprite* spriteMasters;
static size_t spriteCount;

int main() {
	srand(time(NULL));
	IBox* p = NULL;
	p = Factory::GetFactory().Create("Red");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	p = Factory::GetFactory().Create("Blue");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	return 0;
}