#pragma once

struct piggyBank
{
	int oneBills;
	int twoBills;
	int fiveBills;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
};
float calcPiggyBankNotes(piggyBank piggy);
float calcPiggyBankCoins(piggyBank piggy);
float calcPiggyBankTotal(piggyBank piggy);