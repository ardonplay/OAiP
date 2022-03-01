#include "basis.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void menu(){
    cout<<"\tList of commands\t\n"
          "------------------------------\n"
          "1.Create new data of student"
          "\n------------------------------\n"
          "2.List of students"
          "\n------------------------------\n"
          "3.Edit student data"
          "\n------------------------------\n"
          "4.Delete student"
          "\n-----------------------------\n"
          "5.Individual task"
          "\n-----------------------------\n"
          "6.Open Base"
          "\n-----------------------------\n"
          "7.Save Base"
          "\n-----------------------------\n"
          "8.exit"
          "\n------------------------------"<<endl;
    cout<<">>>";
}

base new_student(){
    string choose;
    base students;
    cout<<"Name: ";
    cin>>choose;
    students.name = choose;
    cout<<"Surname: ";
    cin>>choose;
    students.surname = choose;
    cout<<"Group: ";
    cin>>choose;
    students.group = stoi(choose);
    cout<<"Physics: ";
    cin>>choose;
    students.physics = stoi(choose);
    cout<<"Mathematics: ";
    cin>>choose;
    students.mathematics = stoi(choose);
    cout<<"Chemistry: ";
    cin>>choose;
    students.chemistry = stoi(choose);
    cout<<"Informatics: ";
    cin>>choose;
    students.informatics = stoi(choose);
    students.average_score = (students.informatics + students.physics + students.chemistry + students.mathematics)/4.;
    return students;
}

base f_new_student(ifstream& file){
    string line;
    base students;
    getline(file,line);
    students.name = line;
    getline(file,line);
    students.surname = line;
    getline(file,line);
    students.group = stoi(line);
    getline(file,line);
    students.physics = stoi(line);
    getline(file,line);
    students.mathematics = stoi(line);
    getline(file,line);
    students.chemistry = stoi(line);
    getline(file,line);
    students.informatics = stoi(line);
    students.average_score = (students.informatics + students.physics + students.chemistry + students.mathematics)/4.;
    getline(file, line);
    getline(file, line);
    return students;
}

void list(base students){
    cout << endl;
    cout << "Name: " << students.name << endl;
    cout << "Surname: " << students.surname << endl;
    cout << "Group: " << students.group << endl;
    cout << "Physics: " << students.physics << endl;
    cout << "Mathematics: " << students.mathematics << endl;
    cout << "Chemistry: " << students.chemistry << endl;
    cout << "Informatics: " << students.informatics << endl;
    cout << "Average score: " << students.average_score << endl;
}

void save(base students, ofstream& file){
    file << students.name << endl;
    file << students.surname <<endl;
    file << students.group <<endl;
    file << students.physics << endl;
    file << students.mathematics << endl;
    file << students.chemistry << endl;
    file << students.informatics << endl;
    file << students.average_score << endl;
    file << endl;
}
int delete_student(string choose, int number, base students[]){
    int element = stoi(choose);
    element--;
    for(int i = element; i < number; i++)
        students[i] = students[i + 1];
    return number-1;
}

void individual_task(base students[], int number){
    for(int i = 0; i < number; i++){
        if(students[i].average_score == 8 || students[i].average_score == 9  || students[i].average_score ==10){
            list(students[i]);
        }
    }
}
