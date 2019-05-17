#include<iostream>
#include<string>
#include"Potion.h"

Potion::Potion()
{
	name = "Healing Potion";
	HPModifier = 1;
	quality = 50;
	useByDate = 1018;
}
Potion::Potion(string _name, int _HPModifier, int _quality, int _useByDate)
{
	name = _name;
	HPModifier = _HPModifier;
	quality = _quality;
	useByDate = _useByDate;
}
Potion::~Potion()
{

}