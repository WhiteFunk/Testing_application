#include "User.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <functional>

#include <conio.h>


std::istream& operator>>(std::istream& cin, User& c)
{
	int temp = -1;
	cin >> temp;

	c.role = static_cast<Role>(temp);

	cin >> c.username;
	cin >> c.saltedPassword;
	cin >> c.salt;
	return cin;
}

std::ostream& operator<<(std::ostream& cout, User& c)
{
	cout << static_cast<int>(c.role) << std::endl;
	cout << c.username << std::endl;
	cout << c.saltedPassword << std::endl;
	cout << c.salt << std::endl;
	return cout;
}

void User::set_user()
{
	role = Role::undefined;
	std::cout << "Логин: "; std::cin >> username;
	std::cout << "Пароль: "; //std::cin >> password;


	std::string input;
	char input_char;
	

	do {
		input.clear();
		while (true) {
			input_char = _getch();

			if (input_char == '\b') {
				std::cout << "\b" << " " << "\b\b" << " " << "\b";
				input.pop_back();
				continue;
			}
			if (input_char < 32 && input_char != '\b') {
				std::cout << std::endl;
				break;
			}
			std::cout << "*";
			input.push_back(input_char);
		}
	} while (input.size()<8);

	password = input;

	salt = saltPassword();

	saltedPassword = std::hash<std::string>{}(password+salt);
}

std::string User::saltPassword()
{
	std::string result, temp;
	std::string latin = "abcdefghijklmnopqrstuvwxyz";
	temp += latin;
	std::transform(latin.begin(), latin.end(), latin.begin(), ::toupper);
	temp += latin;

	for (int i = 0; i < 10; i++) {
		temp += std::to_string(i);
	}


	std::string pass = "";
	int index;
	srand((unsigned)time(nullptr));
	for (int j = 0; j < 10; j++) {
		index = rand() % temp.length();
		pass += temp[index];
	}
	result += pass;

	return result;
}

void User::print()
{
	std::cout << std::setw(15);
	switch (static_cast<int>(this->role)) {
	case 0:
		std::cout << "Администратор";
		break;
	case 1:
		std::cout << "Пользователь";
		break;
	case 2:
		std::cout << "Не определён";
		break;
	}
	std::cout << std::setw(15) << username;
	std::cout << std::setw(30) <<saltedPassword; 
	std::cout << std::endl;

}


