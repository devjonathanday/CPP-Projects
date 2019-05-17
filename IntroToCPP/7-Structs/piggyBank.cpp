#include "piggyBank.h"
#include <iostream>

float calcPiggyBankNotes(piggyBank piggy)
{
	return (piggy.oneBills) + (piggy.twoBills * 2) + (piggy.fiveBills * 5);
}
float calcPiggyBankCoins(piggyBank piggy)
{
	return (piggy.quarters * 0.25f) + (piggy.dimes * 0.1f) + (piggy.nickels * 0.05f) + (piggy.pennies * 0.01f);
}
float calcPiggyBankTotal(piggyBank piggy)
{
	return calcPiggyBankNotes(piggy) + calcPiggyBankCoins(piggy);
}