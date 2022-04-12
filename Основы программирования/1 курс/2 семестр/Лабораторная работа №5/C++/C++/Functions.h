#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "Teacher.h"

Student* generateStudents(size_t a_cCounter);
Teacher* generateTeachers(size_t a_cCounter);

void outputStudents(const Student* students, size_t size);
void outputTeachers(const Teacher* teachers, size_t size);

Teacher getTeacherWithHighestSalary(Teacher* teachers, size_t size);