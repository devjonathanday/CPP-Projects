#include "Student.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printStudentInfo(student scholar)
{
	cout << "Student ID: " << scholar.id << endl;
	cout << "Course: " << scholar.course << endl;
	cout << "Last exam score: " << scholar.score << "%" << endl;
}

void sortByScore(student studentBody[], int size)
{
	bool changed = true;
	while (changed)
	{
		changed = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (studentBody[i].score > studentBody[i + 1].score)
			{
				int temp = studentBody[i].score;
				studentBody[i].score = studentBody[i + 1].score;
				studentBody[i + 1].score = temp;
				changed = true;
			}
		}
	}
}

void avgOfStudents(student studentBody[], int classSize)
{
	int avg = 0;
	int median = 0;
	for (int i = 0; i < classSize; i++)
	{
		avg += studentBody[i].score;
	}
	cout << "Average score: " << avg / classSize << endl;
	sortByScore(studentBody, classSize);
	cout << "Median score: " << studentBody[classSize / 2].score << endl;
}

int studentsInCourse(student studentBody[], int classSize, int course)
{
	int numberOfStudents = 0;
	for (int i = 0; i < classSize; i++)
	{
		if (studentBody[i].course == course)
		{
			numberOfStudents++;
		}
	}
	return numberOfStudents;
}