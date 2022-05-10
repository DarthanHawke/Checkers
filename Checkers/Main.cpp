#include <SFML/Graphics.hpp>
#include "../Checkers/Play.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	CheckersGame::View::Play play;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (play.getGameIsStart()) {
				play.process(window, event);
				play.update();
			}
			else
				play.gameStart(window, event);
		}

		window.clear(sf::Color::White);
		if (play.getGameIsStart())
			play.render(window);
		else
			play.renderStartMenu(window);
		window.display();
	}
	return 0;
}
