#include<iostream>
#include <SFML/Graphics.hpp>
#include<sstream>
#include <cmath>


std::string IntToString(int a);

class GUI
{
    sf::RenderWindow window;
    int no_of_nodes=0;
    sf::CircleShape node[10];
    sf::Text nodenum[10];
    sf::RectangleShape **line;
    sf::Text **wt;
    int **link;
    float **x;
    float **y;
   // sf::Texture texture;
    sf::Font font;
    float position[10][2];


public:
    GUI();

    int start();
    int drawnodes();
    void inputWeight(int** weight);


    int display();

    void update(int nodeno,int precede );
   // int selectSource();

};