#pragma once
#include <string>
#include <iostream>

enum Role {
	admin = 0,
	user = 1,
	undefined =2
};

class User
{
	std::string username;
	std::string password;
	std::string salt;
	std::size_t saltedPassword;
	Role role;

public:
	void set_user();
	User(): username(), password(),salt(), saltedPassword(0), role(Role::undefined) {};
    User(std::string username, std::string password, Role role,std::string salt, std::size_t saltedPassword) :username(username), password(password), role(role),salt(salt), saltedPassword(saltedPassword) {}
    User(std::string username, std::string password, Role role) :username(username), password(password), role(role) {

        this->salt = saltPassword();

        this->saltedPassword = std::hash<std::string>{}(password+salt);

    }


	std::string saltPassword();

	friend std::istream& operator>>(std::istream& cin, User& c);
	friend std::ostream& operator<<(std::ostream& cout, User& c);

	bool operator == (User u) { 
	if ((this->username == u.username) && (std::hash<std::string>{}(this->password + u.salt) == u.saltedPassword)) return true; else return false; }

	void print();

	void set_role(Role role) {
		this->role = role;
	}
	Role get_role() {
		return role;
    }
    std::string get_username() {
        return username;
    }
    std::size_t get_saltedPassword() {
        return saltedPassword;
    }
};
