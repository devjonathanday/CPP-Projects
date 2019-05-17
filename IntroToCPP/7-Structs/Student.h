#pragma once

struct student
{
	int id;
	int course;
	int score;
};

void printStudentInfo(student scholar);
void sortByScore(student studentBody[], int size);
void avgOfStudents(student studentBody[], int classSize);
int studentsInCourse(student studentBody[], int classSize, int course);