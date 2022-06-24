#include "graphics.h"
#include <cstdio>
#include <unistd.h>
namespace fs = std::filesystem;
void graphics::renaming(std::string Directory){
    std::string directory_name = Directory;
    std::string extension = ".png";
    std::string cache;
    std::ifstream file;
    int count = 0;
    try // Может быть исключение, например, если папки не существует
    {
        for (auto &p : fs::directory_iterator(directory_name)) // Для всех файлов в папке
        {
            if (!fs::is_regular_file(p.status()))
                continue; // Пропускаем, если это не простой файл, а папка или что-то другое

            std::string name(p.path().filename());
            if(name == "1.png"){
                return;
            }

            bool match = !name.compare(name.size() - extension.size(), extension.size(), extension);

            if (!match)
                continue;

            // Тут делаем с путем то, что нужно
            std::cout << name << std::endl;
            int i =0;
            while(name[i]!='.'){
              cache+=name[i];
              i++;
            }
            name.clear();
            for(int j =0; j < i-1;j++){
                name+=cache[j];
            }
            cache.clear();
            cache=name;
            count++;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
    std::cout<<cache<<std::endl;

    for(int i = 0; i < count;i++){
        std::string filename =Directory +cache+ std::to_string(i)+".png";
        file.open(filename);
        std::ofstream save;
        save.open(Directory+std::to_string(i+1)+".png");

        std::string line;
        if(file && save){

            while(getline(file,line)){
                save <<line<< "\n";
            }
            std::cout << "Copy Finished \n";

        } else {
            //Something went wrong
            printf("Cannot read File");
        }
        file.close();
        char *Name = new char [sizeof filename + 10];
        for(int i =0; i < sizeof filename+10;i++){
            Name[i]=filename[i];
            std::cout<<Name[i];
        }std::cout<<std::endl;
        remove(Name);
        save.close();
    }
}
void graphics::gif(unsigned int delay,std::string directory_of_image,sf::RenderWindow &window) {
        sf::Texture texture;
        sf::Sprite sprite;
        std::ifstream file;

        file.open(directory_of_image + std::to_string(1)+".png");
        if(!file){
            std::cout<<"Cant open first file, please make sure that's you write right directory!"<<std::endl;
            exit(134);
        }
        file.close();

        int count = 1;
        while(file){
            file.open(directory_of_image + std::to_string(count)+".heic");
            count++;
            file.close();
        }
        count=count-2;


            sf::Event event;

            while ( window.pollEvent( event ) )
            {
                if(event.type == sf::Event::Closed){
                    window.close( );
                    break;
                }
            }
            for(int i = 1; i <=count;i++) {
                usleep(delay*10000);
                window.clear(sf::Color::White);
                texture.loadFromFile(directory_of_image + std::to_string(i) + ".png");
                sprite.setTexture(texture);
                window.draw(sprite);
                window.display( );
            }

}

void graphics::graph(sf::RenderWindow &window, float wight, float height) {

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
        window.clear(sf::Color::White);

        sf::CircleShape circle;

        circle.setRadius(1);
        circle.setFillColor(sf::Color::Black);

        float cird = height/2.;
        for (float x = 0; x < wight; x+=0.01){
            float y = -cos(x)*60;
            circle.setPosition(x*20, y+cird);
            window.draw(circle);
        }
        circle.setRadius(1);
        circle.setFillColor(sf::Color::Black);
        for(float x = 0; x < wight;x+=0.01){
            circle.setPosition(x,height/2);
            window.draw(circle);
        }

        for(float y = 0; y < height;y+=0.01){
        circle.setPosition(wight/2,y);
        window.draw(circle);
        }
        window.display();
}
