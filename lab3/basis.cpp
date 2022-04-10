#include "basis.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void menu(){
    cout<<"\tList of commands\t\n"
          "------------------------------\n"
          "1.Create new data of customer"
          "\n------------------------------\n"
          "2.List of customers"
          "\n------------------------------\n"
          "3.Edit customer data"
          "\n------------------------------\n"
          "4.Delete customer"
          "\n-----------------------------\n"
          "5.Search"
          "\n-----------------------------\n"
          "6.Open Base"
          "\n-----------------------------\n"
          "7.Save Base"
          "\n-----------------------------\n"
          "8.exit"
          "\n------------------------------"<<endl;
    cout<<">>>";
}

void SearchingMenu(){
    cout<<"\tList of Searching variables\t\n"
          "------------------------------\n"
          "1.Linear Search"
          "\n------------------------------\n"
          "2.Binary search"
          "\n------------------------------"<<endl;
    cout<<">>>";
}

base new_customer(int number){
    string choose;
    base customers;
    customers.number = number;
    cout<<"Name: ";
    cin>>choose;
    customers.name = choose;
    cout<<"Surname: ";
    cin>>choose;
    customers.surname = choose;
    cout<<"Second Name: ";
    cin>>choose;
    customers.SecondName = choose;
    cout<<"Home address: ";
    cin>>choose;
    string choose2;
    getline(cin, choose2);
    customers.HomeAddress = choose  + choose2;
    cout<<"Date: ";
    cin>>choose;
    customers.date = choose;
    return customers;
}

base f_new_customer(ifstream& file){
    string line;
    base customers;
    getline(file,line);
    customers.number = stoi(line);
    getline(file,line);
    customers.name = line;
    getline(file,line);
    customers.surname = line;
    getline(file,line);
    customers.SecondName = line;
    getline(file,line);
    customers.HomeAddress = line;
    getline(file,line);
    customers.date = line;
    getline(file,line);
    return customers;
}

void list(base customers){
    cout << endl;
    cout<<"Number: " << customers.number <<endl;
    cout << "Name: " << customers.name << endl;
    cout << "Surname: " << customers.surname << endl;
    cout << "Second Name: " << customers.SecondName << endl;
    cout << "Home Address: " << customers.HomeAddress << endl;
    cout << "Date: " << customers.date << endl;
}

void save(base customers, ofstream& file){
    file << customers.number << endl;
    file << customers.name << endl;
    file << customers.surname <<endl;
    file << customers.SecondName <<endl;
    file << customers.HomeAddress << endl;
    file << customers.date << endl;
    file << endl;
}
int delete_customer(string choose, int number, base customers[]){
    int element = stoi(choose);
    element--;
    for(int i = element; i < number; i++)
        customers[i] = customers[i + 1];
    return number-1;
}

void LinearSearch(string SearchPoint, int number, base customers[]){
    int* number_search = new int [0],  indexation_point = 0;
    for(int index = 0; index < number; index++) {
        if (customers[index].name == SearchPoint ||
            customers[index].surname == SearchPoint ||
            customers[index].SecondName == SearchPoint ||
            customers[index].HomeAddress == SearchPoint ||
            customers[index].date == SearchPoint) {
            indexation_point++;
            number_search[indexation_point] = customers[index].number;
        }
    }
        if(indexation_point !=0){
            cout<<"Found " << indexation_point << "positions!" << endl;
            for(int index = 0; index < indexation_point; index++){
                list(customers[number_search[index]]);
            }
        }
        else{
            cout<<"Nothing found!"<<endl;
        }
}

void individual_task(base customers[], int number){
    SearchingMenu();
    string choose;
    cin >> choose;
    switch (stoi(choose)) {
        case 1:{
            cout<<"Type what you need to find" << endl;
            cout<<">>>";
            cin >> choose;
            LinearSearch(choose, number, customers);
            break;
        }
        case 2:{
            cout<<"Error 503"<<endl;
            break;
        }
        default :{
            cout<<"Error 404"<<endl;
            break;
        }
    }
}