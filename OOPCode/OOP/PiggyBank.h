#pragma once

// Manages a digital money store that can only be deposited.
// The balance may not be withdrawn without retrieving the full value.
class DigitalPiggyBank
{
private:
	// Maintains the current balance of the piggy bank.
	float currentBalance = 0;
public:
	// Add funds to the value of the current balance.
	void deposit(float net);

	// Returns and clears the total current balance.
	float withdraw();

	// Returns the current balance of the function.
	float balance();
};