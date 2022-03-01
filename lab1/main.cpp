#include <iostream>
#include <string>
#include "basis.h"
#include <fstream>
using namespace std;

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
                if(number == 0){
                    cout<<"\nThere are no student in the base!\n"<<endl;
                   break;
                }
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
                cout<<"What student do you wanna delete?\n>>>";
                cin>>choose;
                number = delete_student(choose, number,students);
                break;
            }

            case 5:{
                individual_task(students, number);
                break;
            }
            case 6:{
                ifstream file;
                cout<<"What's the destination of the file?\n>>>";
                cin>>choose;
                string lines;
                int number_2 = 1;
                file.open(choose);
                if(file)
                    cout<<"File "<<choose<<" is opened!"<<endl;
                else {
                    cout << "Houston, we have troubles with opening file!" << endl;
                }
                while (!file.eof())
                {
                    getline(file, lines);
                    number_2++;
                }
                file.close();
                number_2 = number_2 / 9;
                file.open(choose);
                for(int i = 0; i < number_2; i++){
                    students[i] = f_new_student(file);
                }
                file.close();
                number = number_2;
                break;
            }
            case 7:{
                cout<<"Whats the destination of the file to save?\n>>>";
                cin >> choose;
                ofstream file(choose);
                for(int i = 0; i < number; i++){
                    save(students[i], file);
                }
                break;
            }
            case 8: {
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
