#include<iostream>
#include "Gold.h"
#include "Kryptonite.h"
#include "Red.h"

int main()
{
	Kryptonite *k1 = new Gold();
	Kryptonite *k2 = new Red();
	Kryptonite *k3 = k1->Clone();
	Kryptonite *k4 = k2->Clone();

	std::cout << "k1=" << k1->Diagnose().c_str() << std::endl;
	std::cout << "k2=" << k2->Diagnose().c_str() << std::endl;
	std::cout << "k3=" << k3->Diagnose().c_str() << std::endl;
	std::cout << "k4=" << k4->Diagnose().c_str() << std::endl;
	//Of course we should tidy up afterwards
	delete k1;
	delete k2;
	delete k3;
	delete k4;

	return 0;
}