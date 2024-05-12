taskmanager header file:


#pragma once
#include"User.h"
#include<fstream>

class TaskManager
{
private:
	User* users;
	int sizeofUsers;
public:

	TaskManager();
	TaskManager(User* users, int size);
	int getUserSize();
	void setSizeOfUsers(int& size);
	void AddUser(User& user);
	void DeleteUser(int index);
	void HandleUserTasks();
	void ViewAllTasks();
	void ListUsers();
	bool signUp(ofstream& wrt);
	bool Login(ifstream& rdr);
	bool LogOut();
};

