#include <iostream>
#include <string>
#include "basis.h"
#include <fstream>
using namespace std;

int main() {

    string choose;

   base *customer = new base [100];

    int number = 0;

    while(true) {
        menu();
        cin>>choose;
        switch (stoi(choose)) {
            case 1: {
                customer[number] = new_customer(number+1);
               number++;
                break;
            }

            case 2: {
                if(number == 0){
                    cout<<"\nThere are no customer in the base!\n"<<endl;
                   break;
                }
                for(int i = 0; i < number; i++) {
                    list(customer[i]);
                }
                break;
            }

            case 3: {

                cout<<"What the number of the customer?\n>>>";
                cin>>choose;
                customer[stoi(choose)] = new_customer(number+1);

                break;
            }

            case 4: {
                cout<<"What customer do you wanna delete?\n>>>";
                cin>>choose;
                number = delete_customer(choose, number, customer);
                break;
            }

            case 5:{
                individual_task(customer, number);
                break;
            }
            case 6:{
                ifstream file;
                cout<<"What's the destination of the file?\n>>>";
                cin>>choose;
                string lines;
                int number_2 =1;
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
                number_2 = number_2 / 6;
                file.open(choose);
                for(int i = 0; i < number_2; i++){
                    customer[i] = f_new_customer(file);
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
                    save(customer[i], file);
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
