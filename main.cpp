#include <SFML/Window.hpp>

int main()
{
    //sf::Window my_Window(sf::VideoMode(640U,480U),"w",sf::Style::None)
    sf::Window window(sf::VideoMode(800, 600), "My window");
    sf::Window juego(sf::VideoMode(1080, 720), "Tank-Game");
    //cambiar el no título de la ventana
    window.setTitle("Menu principal");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Event eJuego;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
                juego.close();
            }
                

            
            
            
        }
    }

    return 0;
}