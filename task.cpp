Code of Task Class:





#include"Task.h"

Task::Task()
{
	this->title = "";
	this->description = "";
	this->dueDate = { 0,0,0 };
	this->IsCompleted = false;
}
Task::Task(string title, string desc)
{
	this->title = title;
	this->description = desc;
	this->dueDate = { 0,0,0 };
	this->IsCompleted = false;
}
void Task::createTask(string title, string desc, Date dueDate)
{
	this->title = title;
	this->description = desc;
	this->dueDate = dueDate;
	this->IsCompleted = false;
}
void Task::UpdateTask()
{
	cout << "------------What do You Want To Update----------\n";
	cout << "1) Update Title.\n";
	cout << "2) Update Description.\n";
	cout << "3) Update Due Date.\n";
	int choice;
	cin >> choice;
	cin.ignore();
	switch (choice)
	{
	case 1:
		updateTitle();
		break;
	case 2:
		updateDescription();
		break;
	case 3:
		updateDueDate();
		break;
	}
}




void Task::updateTitle()
{
	string tempTitle;
	cout << "Enter New Title For Your Task \n";
	getline(cin, tempTitle);
	this->title = tempTitle;
}
void Task::updateDescription()
{
	string tempDesc;
	cout << "Enter New Description For Your Task \n";
	getline(cin, tempDesc);
	this->title = tempDesc;
}


void Task::updateDueDate()
{
	Date tempDate;
	cout << "Enter New Due Date For Your Task (dd / mm / yyyy)\n";
	char d;
	cin >> tempDate.day >> d >> tempDate.month >> d >> tempDate.year;
	this->dueDate = tempDate;
}
void Task::markAsCompleted()
{
	if (!IsCompleted)
	{
		this->IsCompleted = true;
	}
}

void Task::ListTask()
{
	cout << "Title :\t-----------" << this->title << "---------\n\n";
	cout << "Description :\t" << this->description << "\n";
	cout << "Due Date :   " << this->dueDate << "\n";
	cout << "Completion Status :   ";
	{
		if (IsCompleted)
		{
			cout << "Completed\n";
		}
		else if (!IsCompleted)
		{
			cout << "Pending\n";
		}
	}
}

