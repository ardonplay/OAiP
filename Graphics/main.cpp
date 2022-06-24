#include <thread>
#include "graphics.h"
using namespace std;
void Menu(){
    cout<<"\tGraphics\t"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"1.Gif"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"2.Graphic"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<">>>";
}
int main() {
    graphics graphics;
    float height = 1000, wight = 1000;
    while(true) {
        Menu();
        string choose;
        cin >> choose;
        switch (stoi(choose)) {
            case 1:{
                cout<<"What destination of directory:"<<endl;
                cout<<">>>";
                cin>>choose;
                sf::RenderWindow window(sf::VideoMode(height, wight), "Lab8");
                while (window.isOpen()) {
                    graphics.gif(1, choose, window);
                }
                break;
            }
            case 2: {
                sf::RenderWindow window(sf::VideoMode(height, wight), "Lab8");
                    graphics.graph(window,wight, height);
                    break;
            }
            case 3:{
                exit(100);
            }
        }


    }
}