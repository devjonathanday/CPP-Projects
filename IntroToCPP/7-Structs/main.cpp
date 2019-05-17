#include <iostream>
#include "person.h"
#include "piggyBank.h"
#include "student.h"
#include "vector2.h"
#include "PlayerVZombie.h"

int main()
{
	Person paul = {};
	Person jon = { 15, 1000, 20 };

	printPerson(jon);
	piggyBank myBank = { 7, 1, 2, 4, 3, 10, 40 };

	cout << calcPiggyBankCoins(myBank) << endl;
	student me        = { 189078, 1, 100 };
	student jimmy     = { 768154, 2, 67 };
	student johnson   = { 386723, 2, 98 };
	student jerusalem = { 687686, 3, 82 };
	student jongus    = { 617879, 1, 1 };

	printStudentInfo(me);
	printStudentInfo(jimmy);
	printStudentInfo(johnson);
	printStudentInfo(jerusalem);
	printStudentInfo(jongus);

	cout << endl;

	student studentBody[] { me, jimmy, johnson, jerusalem, jongus};

	avgOfStudents(studentBody, 5);
	cout << "Students in Course 1: " << studentsInCourse(studentBody, 5, 1) << endl;

	vector2 vec1 = { 4, 5 };
	vector2 vec2 = { 9, 12 };

	cout << "Vector 1: (" << vec1.x << ", " << vec1.y << ")" << endl;
	cout << "Vector 2: (" << vec2.x << ", " << vec2.y << ")" << endl;

	cout << "Sum of Vector 1 and 2: ";
	printVector(vectorSum(vec1, vec2));
	cout << endl;

	cout << "Difference of Vector 1 and 2: ";
	printVector(vectorDifference(vec1, vec2));
	cout << endl;

	cout << "Distance between the vectors: " << vectorDistance(vec1, vec2) << endl;

	Battle();

	system("pause");

	return 0;
}