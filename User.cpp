user class code


#include"User.h"
#include<fstream>


User::User()
{
	this->name = "";
	this->password = "";
	this->taskSize = 0;
	this->tasks = new Task[taskSize];
	bool IsLoggedIn = false;
}
User::User(string name)
{
	this->name = name;
	this->password = "";
	this->taskSize = 0;
	this->tasks = new Task[taskSize];
	bool IsLoggedIn = false;
}
User::User(string name, string password)
{
	this->name = name;
	this->password = password;
	this->taskSize = 0;
	this->tasks = new Task[taskSize];
	bool IsLoggedIn = false;
}
string& User::getName()
{
	return this->name;
}
string& User::getPassword()
{
	return this->password;
}
void User::ResetPass(string newpassword)
{

}
void User::DeleteTask(int index)
{
	Task* temp = new Task[this->taskSize - 1];
	int ind = 0;
	for (int i = 0; i < this->taskSize; i++)
	{
		if (i != index)
		{
			temp[ind] = tasks[i];
			ind++;
		}
	}
	this->taskSize--;
	delete[]tasks;
	tasks = temp;
}



void User::AddTask(Task& task)
{
	Task* temp = new Task[this->taskSize + 1];

	for (int i = 0; i < this->taskSize; i++)
	{
		temp[i] = tasks[i];
	}
	temp[this->taskSize] = task;
	this->taskSize++;
	delete[]tasks;
	tasks = temp;
}




void User::EditTask(int index)
{
	for (int i = 0; i < this->taskSize; i++)
	{
		if (i == index)
		{
			tasks[i].UpdateTask();
			break;
		}
	}
}
void User::ViewProfile()
{
	cout << "Name :\t\t" << this->name << "\n";
	cout << "Number Of Tasks :\t" << this->taskSize << "\n";
	for (int i = 0; i < this->taskSize; i++)
	{
		this->tasks[i].ListTask();
		cout << "\n\n";
	}
}




void User::handleUser()
{
	cout << "------------What do You Want To Do----------\n";
	cout << "1) Update Task.\n";
	cout << "2) Delete Task.\n";
	cout << "3) Add A New Task.\n";
	cout << "4) List All Tasks.\n";
	int choice;
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		cout << "Enter Number Of Task You Want To Update\n";
		cin >> choice;
		EditTask(choice);
	}
	else if (choice == 2)
	{

		cout << "Enter Number Of Task You Want To Delete\n";
		cin >> choice;
		DeleteTask(choice);
	}
	else if (choice == 3)
	{

		string temptitle;
		string tempdesc;
		Date tempdueDate;
		cout << "Enter Title of Your Task\n";
		getline(cin, temptitle);
		cout << "Enter Description of Your Task\n";
		getline(cin, tempdesc);
		cout << "Enter Due Date of Your Task (dd/mm/yyyy)\n";
		cin >> tempdueDate.day >> tempdueDate.month >> tempdueDate.year;
		Task temp;
		temp.createTask(temptitle, tempdesc, tempdueDate);
		AddTask(temp);
	}
	else if (choice == 4)
	{
		ViewProfile();
	}
}





bool User::CreateAccount(ofstream& wrt)
{
	cout << "Enter Name\n";
	getline(cin, this->name);
	cout << "Enter Password\n";
	getline(cin, this->password);
	wrt << this->name << " ";
	wrt << this->password << "\n";
	return true;
}






bool User::LogOut()
{
	IsLoggedIn = false;
	return true;
}