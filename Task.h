#pragma once

#include <vector>
#include <string>
#include <iostream>
class Task
{
    int number_of_options;
    int correct_answer;
    std::string question;
    std::vector<std::string> answer_options;

public:
    int get_options_number(){return number_of_options;}
    int get_correct_answer(){return correct_answer;}
    std::string get_question(){return question;}
    std::vector<std::string> get_options(){return answer_options;}


    Task(){
        std::cout << "??????? ??????: ";
        std::cin >> question;

        while(number_of_options<1 && number_of_options > 8){
        std::cout << "??????? ?????????? ????????? ??????: ";
        std::cin >> number_of_options;
        }

        std::string temp;
        for (int i = 0; i < number_of_options; i++) {
            std::cout << "??????? ??????? ????? " << i << ": ";
            std::cin >> temp;
            answer_options.push_back(temp);
        }

        while (correct_answer < 1 && correct_answer > number_of_options) {
            std::cout << "??????? ????? ??????? ????????: ";
            std::cin >> correct_answer;
        }

    }

Task(int numb) :number_of_options(numb){
        std::cout << "??????? ??????: ";
        std::cin >> question;

        std::string temp;
        for (int i = 0; i < numb; i++) {
            std::cout << "??????? ??????? ????? " << i << ": ";
            std::cin >> temp;
            answer_options.push_back(temp);
        }

        while (correct_answer < 1 && correct_answer > number_of_options) {
            std::cout << "??????? ????? ??????? ????????: ";
            std::cin >> correct_answer;
        }
    }

    Task(int numb, int corr):number_of_options(numb), correct_answer(corr) {
        std::cout << "??????? ??????: ";
        std::cin >> question;

        std::string temp;
        for (int i = 0; i < numb; i++){
            std::cout << "??????? ??????? ????? " << i << ": ";
            std::cin >> temp;
            answer_options.push_back(temp);
        }
    }

    Task(int numb, int corr, std::string q) :number_of_options(numb), correct_answer(corr),question(q) {
        std::string temp;
        for (int i = 0; i < numb; i++) {
            std::cout << "??????? ??????? ????? " << i << ": ";
            std::cin >> temp;
            answer_options.push_back(temp);
        }
    }
    Task(int numb, int corr, std::string q, std::vector<std::string> options) :number_of_options(numb), correct_answer(corr),question(q),answer_options(options) {}
};

