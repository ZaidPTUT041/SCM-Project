Task header file:


#pragma once
#include<string>
#include<iostream>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;


	friend ostream& operator<<(ostream& cout, Date& d)
	{
		cout << d.day << "/ " << d.month << " /" << d.year;
		return cout;
	}
};


class Task
{
private:

	string title;
	string description;
	Date dueDate;
	bool IsCompleted;

public:

	Task();
	Task(string title, string desc);
	void createTask(string title, string desc, Date dueDate);
	void UpdateTask();
	void updateTitle();
	void updateDescription();
	void updateDueDate();
	void markAsCompleted();
	void ListTask();
};
