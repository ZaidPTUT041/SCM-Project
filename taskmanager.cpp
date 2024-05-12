task manager code:


#include"TaskManager.h"
#include<fstream>
using namespace std;

TaskManager::TaskManager()
{
	this->users = nullptr;
	this->sizeofUsers = 0;
}
TaskManager::TaskManager(User* users, int size)
{
	this->sizeofUsers = size;
	this->users = new User[size];
	for (int i = 0; i < size; i++)
	{
		this->users[i] = users[i];
	}
}
void TaskManager::AddUser(User& user)
{
	User* temp = new User[this->sizeofUsers + 1];

	for (int i = 0; i < this->sizeofUsers; i++)
	{
		temp[i] = this->users[i];
	}
	temp[this->sizeofUsers] = user;
	this->sizeofUsers++;
	delete[]users;
	this->users = temp;
}
void TaskManager::DeleteUser(int index)
{
	User* temp = new User[this->sizeofUsers - 1];
	int ind = 0;
	for (int i = 0; i < this->sizeofUsers; i++)
	{
		if (i != index)
		{
			temp[ind] = this->users[i];
			ind++;
		}
	}
	this->sizeofUsers--;
	delete[]users;
	this->users = temp;
}


void TaskManager::HandleUserTasks()
{
	for (int i = 0; i < sizeofUsers; i++)
	{
		if (users[i].IsLoggedIn)
		{
			users[i].handleUser();
		}
	}
}


void TaskManager::ViewAllTasks()
{
	for (int i = 0; i < sizeofUsers; i++)
	{
		if (users[i].IsLoggedIn)
		{
			users[i].ViewProfile();
		}
	}
}


void TaskManager::ListUsers()
{
	for (int i = 0; i < sizeofUsers; i++)
	{
		users[i].ViewProfile();
	}
}



bool TaskManager::LogOut()
{
	for (int i = 0; i < sizeofUsers; i++)
	{
		if (users[i].IsLoggedIn)
		{
			bool check = users[i].LogOut();
			return check;
		}
	}
	return false;
}


bool TaskManager::signUp(ofstream& wrt)
{
	
	User temp;
	temp.CreateAccount(wrt);
	AddUser(temp);
	return true;
}



int TaskManager::getUserSize()
{
	return sizeofUsers;
}



void TaskManager::setSizeOfUsers(int& size)
{
	this->sizeofUsers = size;
}


bool TaskManager::Login(ifstream& rdr)
{
	cout << "Enter Name\n";
	string tempname;
	getline(cin, tempname);
	string temppass;
	cout << "Enter Password\n";
	getline(cin, temppass);
	rdr.seekg(0,ios::beg);
	string tn;
	string tp;
	while (rdr)
	{
		rdr >> tn;
		rdr >> tp;
		for (int i = 0; i < sizeofUsers; i++)
		{
			if (strcmp(tempname.c_str(), tn.c_str()) == 0 && strcmp(temppass.c_str(), tp.c_str()) == 0)
			{
				users[i].IsLoggedIn = true;
				return true;
			}
		}
		
	}
	return false;
	
}

