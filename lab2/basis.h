#ifndef LB1_BASIS_H
#define LB1_BASIS_H

#include <string>
struct base{
    std::string name, surname;
    double physics, informatics, mathematics, chemistry, average_score;
    int group;
};
void menu();

base new_student();

base f_new_student(std::ifstream& file);

void list(base students);

void save(base students, std::ofstream& file);

int delete_student(std::string choose, int number, base students[]);

void individual_task(base students[], int number);



#endif //LB1_BASIS_H
