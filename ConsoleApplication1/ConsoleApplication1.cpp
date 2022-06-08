// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "vec.h";

constexpr auto SCREENSIZE = 800;

int thing = 3;
vec<int> arra{ 1,2,3,4,5,6,7,8 };
vec< sf::RectangleShape* > rec;//this constructor allocates memory, but does not push values to it


int main()
{   
    for (int x = 0; x < 6; x++) {
        rec.push_back(new sf::RectangleShape(sf::Vector2f(SCREENSIZE/(x+1),SCREENSIZE/(x+1))));
        rec[x]->setFillColor(sf::Color::Black);
    }
    sf::RenderWindow screen(sf::VideoMode{800,800}, std::string("title"));
    sf::Event event;

    std::cout << "Hello World!\n";
    while (screen.isOpen() == true) {
        //event queue
        while (screen.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                screen.close();
            
        }


        //drawing stuff
        for (int x = 0; x < rec.length(); x++) {
            screen.clear(sf::Color::White);
            screen.draw(*rec[x]);
            screen.display();
        }

    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
