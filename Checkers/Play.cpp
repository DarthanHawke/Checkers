#include <SFML/Graphics.hpp>
#include "../Checkers/CheckersActions.cpp"


namespace CheckersGame
{
	namespace View
	{
		class Play
		{
		private:
			sf::Vector2i mouse_location;
			Actions::CheckersActions checkersActions;
			std::vector<std::pair<int, int>> travel_options;
			sf::RectangleShape field = sf::RectangleShape(sf::Vector2f(100, 100));
			Models::Board game_board = checkersActions.getBoardCheckers();
			Models::Checkers** checkers = checkersActions.getCheckers();
			sf::CircleShape checker = sf::CircleShape(50);
			bool step;
			bool click;


		public:
			Play()
			{
				checkersActions = Actions::CheckersActions();
				step = true;
				click = false;
			}

			bool getStep()
			{
				return step;
			}

			void setStep(bool move)
			{
				step = move;
			}

			bool getClick()
			{
				return click;
			}

			void setClick(bool cl)
			{
				click = cl;
			}

			void process(sf::RenderWindow& _window, sf::Event _event)
			{
				if (_event.type == sf::Event::MouseButtonPressed)
				{
					if (_event.key.code == sf::Mouse::Left)
					{
						if (!getClick())
						{
							mouse_location = sf::Mouse::getPosition(_window);

							for (size_t y = 1; y <= 8; ++y)
							{
								for (size_t x = 1; x <= 8; ++x)
								{
									if (mouse_location.y < (y * 100) &&
										mouse_location.y >((y - 1) * 100) &&
										mouse_location.x < (x * 100) &&
										mouse_location.x >((x - 1) * 100) &&
										checkersActions.getColor(x - 1, y - 1) == true &&
										game_board.getCheckers(x - 1, y - 1) == true)
									{
										checkersActions.choise_checker(x - 1, y - 1);
										travel_options = checkersActions.try_move();
										if (travel_options.size() <=0)
										{
											checkersActions.revoke_checker();
										}
										else
										{
											setClick(true);
										}
										return;
									}
								}
							}
						}
						if (getClick())
						{
							if (getStep())
							{
								mouse_location = sf::Mouse::getPosition(_window);
								for (auto i : travel_options)
								{
									if (mouse_location.y < ((i.second + 1) * 100) &&
										mouse_location.y >(i.second * 100) &&
										mouse_location.x < ((i.first + 1) * 100) &&
										mouse_location.x >(i.first * 100))
									{
										checkersActions.move(i.first, i.second);
										game_board = checkersActions.getBoardCheckers();
										checkers = checkersActions.getCheckers();
										setClick(false);
										setStep(false);
										return;
									}
								}
							}
						}
					}
				}
			}


			void update()
			{
				if (!getStep())
				{
					std::vector<std::pair<int, int>> available_checkers;
					for (size_t y = 0; y < 8; ++y)
					{
						for (size_t x = 0; x < 8; ++x)
						{
							if (checkersActions.getColor(x, y) != true && game_board.getCheckers(x, y) == true)
							{
								available_checkers.push_back(std::pair<int, int>(x, y));
							}
						}
					}
					std::vector<std::pair<int, int>>::iterator iter = available_checkers.begin();
					size_t pos = rand() % available_checkers.size();
					std::pair<int, int> choise = available_checkers[pos];
					available_checkers.erase(iter + pos);
					checkersActions.choise_checker(choise.first, choise.second);
					travel_options = checkersActions.try_move();
					while (travel_options.size() <= 0 && available_checkers.size() > 0)
					{
						iter = available_checkers.begin();
						pos = rand() % available_checkers.size();
						choise = available_checkers[rand() % available_checkers.size()];
						available_checkers.erase(iter + pos);
						checkersActions.choise_checker(choise.first, choise.second);
						travel_options = checkersActions.try_move();
					}
					if (travel_options.size() > 0)
					{
						choise = travel_options[rand() % travel_options.size()];
						checkersActions.move(choise.first, choise.second);
					}
					travel_options.clear();
					setStep(true);
					return;
				}
			}


			void render(sf::RenderWindow& _window)
			{
				checker.setOutlineThickness(3);
				for (size_t y = 0; y < 8; ++y)
				{
					for (size_t x = 0; x < 8; ++x)
					{
						field.setPosition((x * 100), (y * 100));
						if (game_board.getField(x, y) == false)
						{
							field.setFillColor(sf::Color::Black);
						}
						if (game_board.getField(x, y) == true)
						{
							field.setFillColor(sf::Color::White);
						}
						_window.draw(field);
						for (auto i : travel_options)
						{
							field.setPosition(i.first * 100, i.second * 100);
							field.setFillColor(sf::Color::Yellow);
							_window.draw(field);
						}
						checker.setPosition((x * 100), (y * 100));
						if (game_board.getCheckers(x, y) == true)
						{
							if (checkersActions.getColor(x, y) == false)
							{
								checker.setFillColor(sf::Color::Black);
								checker.setOutlineColor(sf::Color::White);
							}
							if (checkersActions.getColor(x, y) == true)
							{
								checker.setFillColor(sf::Color::White);
								checker.setOutlineColor(sf::Color::Black);
							}
							_window.draw(checker);
						}
					}
				}
			}
		};
	}
}