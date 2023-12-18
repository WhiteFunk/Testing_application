#pragma once

#include "Task.h"

class Test
{
	int number_of_tasks;
	std::vector <Task> tasks;

public:

	Test() {}
	Test(int NOT) :number_of_tasks(NOT) {
		for(int i =0;i<number_of_tasks;i++)
		tasks.push_back(Task());
	}
	Test(int NOT, int number_of_options) :number_of_tasks(NOT) {
		for (int i = 0; i < number_of_tasks; i++)
			tasks.push_back(Task(number_of_options));
	}

};

