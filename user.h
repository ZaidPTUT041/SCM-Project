#pragma once



#include<iostream>
#include<string>
#include"Task.h"
using namespace std;




class User
{
private:
	string name;
	string password;
	Task* tasks;
	int taskSize;
user header file:


public:
	bool IsLoggedIn;
	User();
	User(string name);
	User(string name, string password);
	string& getName();
	string& getPassword();
	void ResetPass(string newpassword);
	void DeleteTask(int index);
	void AddTask(Task& task);
	void EditTask(int index);
	void ViewProfile();
	//bool Login(string n, string p);
	bool CreateAccount(ofstream& wrt);
	void handleUser();
	bool LogOut();
};

