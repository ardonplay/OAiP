#ifndef LB1_BASIS_H
#define LB1_BASIS_H

#include <string>
struct base{
    int number;
    std::string name, surname, SecondName,HomeAddress;
    std::string date;
};
void menu();

void SearchingMenu();

base new_customer(int number);

base f_new_customer(std::ifstream& file);

void list(base customers);

void save(base customers, std::ofstream& file);

int delete_customer(std::string choose, int number, base customers[]);

void individual_task(base customers[], int number);

int LinearSearch(std::string SearchPoint);

#endif //LB1_BASIS_H
