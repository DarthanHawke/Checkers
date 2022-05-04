#include <SFML/Graphics.hpp>
#include "../Checkers/Play.cpp"



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	CheckersGame::View::Play play;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			play.process(window, event);
			play.update();
		}

		window.clear();
		play.render(window);
		window.display();
	}

	return 0;
}
