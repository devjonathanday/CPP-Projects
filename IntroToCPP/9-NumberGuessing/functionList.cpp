#include <iostream>
#include "functions.h"
#include <time.h>

int randomNumber(int maxRange)
{
	srand(time(NULL));
	return rand() % maxRange + 1;
}