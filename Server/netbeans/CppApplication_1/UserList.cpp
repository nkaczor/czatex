/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserList.cpp
 * Author: kamil
 * 
 * Created on January 9, 2016, 2:45 PM
 */

#include "UserList.h"
#include <cstddef>

#include <iostream>
#include <string>

UserList::UserList() {
    _usersList = new std::vector<User*>();
}

UserList::UserList(const UserList& orig) {
}

UserList::~UserList() {
}

int UserList::getNumberOfUsers()
{
    return _usersList->size();
}

string UserList::getUsers()
{
    string users = "";
    
    for (vector<User*>::iterator iterator = _usersList->begin(); iterator != _usersList->end(); iterator++)
    {  
        if (std::distance(iterator, _usersList->end())-1 == 0)
        {
           users = users + (*iterator)->getName(); 
        }else
        {
            users = users + (*iterator)->getName() + "\n";
        }  
    }
    
    return users;
}

vector<User*>* UserList::getUsersList()
{
    return _usersList;
}

void UserList::insertUser(User *user)
{
    _usersList->push_back(user);
}

UserList& UserList::getUserList()
{
	static UserList *userList = NULL;

	if (userList == NULL){
		userList = new UserList();
	}

	return *userList;
}

void UserList::destroyUserList()
{
	UserList *player = &getUserList();
	delete player;
}

