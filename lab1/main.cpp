#include <iostream>
#include <string>
using namespace std;

struct base{
    string name, surname;
    double physics = 0, informatics = 0, mathematics = 0, chemistry = 0, average_score = 0;
    int group = 0;
};

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

void list(base students){
    cout<<endl;
    cout<<"Name: "<<students.name<<endl;
    cout<<"Surname: "<<students.surname<<endl;
    cout<<"Group: "<<students.group<<endl;
    cout << "Physics: " << students.physics << endl;
    cout<<"Mathematics: "<<students.mathematics<<endl;
    cout<<"Chemistry: "<<students.chemistry<<endl;
    cout<<"Informatics: "<<students.informatics<<endl;
    cout<<"Average score: "<<students.average_score<<endl;
}

int main() {
    string choose;

   base *students = new base [100];

    int number = 0;

    while(true) {
        menu();
        cin>>choose;
        switch (stoi(choose)) {
            case 1: {
               students[number] = new_student();
               number++;
                break;
            }

            case 2: {
                for(int i = 0; i < number; i++) {
                    list(students[i]);
                }
                break;
            }

            case 3: {

                cout<<"What the number of the student?\n>>>";
                cin>>choose;
                students[stoi(choose)] = new_student();

                break;
            }

            case 4: {
                break;
            }

            case 5: {
                cout<<"GoodBye!"<<endl;
               return 0;
            }
            default: {
                menu();
                cin>>choose;
                break;
            }
        }
    }
}
