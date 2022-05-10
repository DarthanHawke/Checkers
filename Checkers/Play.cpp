#include "../Checkers/Play.h"


namespace CheckersGame
{
	namespace View
	{
		void Play::initPlay()
		{
			field = sf::RectangleShape(sf::Vector2f(100, 100));
			checker = sf::CircleShape(50);
			checkersActions = Actions::CheckersActions();
			gameBoard = checkersActions.getBoardCheckers();
			checkers = checkersActions.getCheckers();
		}


		Play::Play()
			: m_countStep(0)
			, m_countgame(0)
			, m_step(true)
			, m_click(false)
			, m_gameIsStart(false)
		{
			initPlay();
		}


		Play& Play::operator = (const Play& copy) {
			if (this != &copy) {
				m_countStep = copy.m_countStep;
				m_countgame = copy.m_countgame;
				m_step = copy.m_step;
				m_click = copy.m_click;
				m_gameIsStart = copy.m_gameIsStart;
			}
			return *this;
		}


		Play::Play(const Play& copy) {
			m_countStep = copy.m_countStep;
			m_countgame = copy.m_countgame;
			m_step = copy.m_step;
			m_click = copy.m_click;
			m_gameIsStart = copy.m_gameIsStart;
		}


		Play::~Play() {}


		void Play::startNewPlay()
		{
			checkersActions = Actions::CheckersActions();
			gameBoard = checkersActions.getBoardCheckers();
			checkers = checkersActions.getCheckers();
			m_countStep = 0;
			m_step = true;
			m_click = false;
			m_gameIsStart = false;
		}


		bool Play::getGameIsStart()
		{
			return m_gameIsStart;;
		}


		bool Play::getStep()
		{
			return m_step;
		}


		void Play::setStep(bool move)
		{
			m_step = move;
		}


		bool Play::getClick()
		{
			return m_click;
		}


		void Play::setClick(bool cl)
		{
			m_click = cl;
		}


		void Play::gameStart(sf::RenderWindow& _window, sf::Event _event)
		{
			if (_event.type == sf::Event::MouseButtonPressed) {
				if (_event.key.code == sf::Mouse::Left) {
					mouseLocation = sf::Mouse::getPosition(_window);
					if (mouseLocation.y < 500
						&& mouseLocation.y > 400
						&& mouseLocation.x < 500
						&& mouseLocation.x > 300) {
						startNewPlay();
						m_gameIsStart = true;
					}
				}
			}
		}


		void Play::renderStartMenu(sf::RenderWindow& _window)
		{
			sf::Texture startMenu, finishMenu;
			startMenu.loadFromFile("../Checkers/StartMenu.jpg");
			finishMenu.loadFromFile("../Checkers/FinishMenu.jpg");
			sf::Sprite menuStart(startMenu), menuEnd(finishMenu);
			menuStart.setPosition(0, 0);
			menuEnd.setPosition(0, 0);
			if (m_countgame <= 0)
				_window.draw(menuStart);
			else
				_window.draw(menuEnd);
		}


		void Play::gameFinish()
		{
			++m_countgame;
			m_gameIsStart = false;
		}


		void Play::process(sf::RenderWindow& _window, sf::Event _event)
		{
			if (m_countStep >= 64)
				gameFinish();
			if (_event.type == sf::Event::MouseButtonPressed) {
				if (_event.key.code == sf::Mouse::Left) {
					if (!getClick()) {
						mouseLocation = sf::Mouse::getPosition(_window);
						for (size_t y = 1; y <= 8; ++y) {
							for (size_t x = 1; x <= 8; ++x) {
								if (mouseLocation.y < (static_cast<float>(y) * 100)
									&& mouseLocation.y >((static_cast<float>(y) - 1) * 100)
									&& mouseLocation.x < (static_cast<float>(x) * 100)
									&& mouseLocation.x >((static_cast<float>(x) - 1) * 100)
									&& checkersActions.getColor(x - 1, y - 1) == true
									&& gameBoard.getCheckers(x - 1, y - 1) == true) {
									checkersActions.choiseChecker(x - 1, y - 1);
									travelOptions = checkersActions.tryMove();
									if (travelOptions.size() <= 0)
										checkersActions.revokeChecker();
									else
										setClick(true);
									return;
								}
							}
						}
					}
					if (getClick()) {
						if (getStep()) {
							mouseLocation = sf::Mouse::getPosition(_window);
							for (auto i : travelOptions) {
								if (mouseLocation.y < ((static_cast<float>(i.second) + 1) * 100)
									&& mouseLocation.y >(static_cast<float>(i.second) * 100)
									&& mouseLocation.x < ((static_cast<float>(i.first) + 1) * 100)
									&& mouseLocation.x >(static_cast<float>(i.first) * 100)) {
									checkersActions.move(i.first, i.second);
									gameBoard = checkersActions.getBoardCheckers();
									checkers = checkersActions.getCheckers();
									setClick(false);
									setStep(false);
									++m_countStep;
									return;
								}
							}
						}
					}
				}
			}
		}


		void Play::update()
		{
			if (!getStep()) {
				std::vector<std::pair<int, int>> available_checkers;
				for (size_t y = 0; y < 8; ++y) {
					for (size_t x = 0; x < 8; ++x) {
						if (checkersActions.getColor(x, y) != true && gameBoard.getCheckers(x, y) == true)
							available_checkers.push_back(std::pair<int, int>(x, y));
					}
				}
				std::vector<std::pair<int, int>>::iterator iter = available_checkers.begin();
				size_t pos = rand() % available_checkers.size();
				std::pair<int, int> choise = available_checkers[pos];
				available_checkers.erase(iter + pos);
				checkersActions.choiseChecker(choise.first, choise.second);
				travelOptions = checkersActions.tryMove();
				while (travelOptions.size() <= 0 && available_checkers.size() > 0) {
					iter = available_checkers.begin();
					pos = rand() % available_checkers.size();
					choise = available_checkers[pos];
					available_checkers.erase(iter + pos);
					checkersActions.choiseChecker(choise.first, choise.second);
					travelOptions = checkersActions.tryMove();
				}
				if (travelOptions.size() > 0) {
					choise = travelOptions[rand() % travelOptions.size()];
					checkersActions.move(choise.first, choise.second);
					gameBoard = checkersActions.getBoardCheckers();
				}
				else
					gameFinish();
				travelOptions.clear();
				setStep(true);
				return;
			}
		}


		void Play::render(sf::RenderWindow& _window)
		{
			checker.setOutlineThickness(3);
			for (size_t y = 0; y < 8; ++y) {
				for (size_t x = 0; x < 8; ++x) {
					field.setPosition((static_cast<float>(x) * 100), (static_cast<float>(y) * 100));
					if (gameBoard.getField(x, y) == false)
						field.setFillColor(sf::Color::Black);
					if (gameBoard.getField(x, y) == true)
						field.setFillColor(sf::Color::White);
					_window.draw(field);
					for (auto i : travelOptions) {
						field.setPosition(static_cast<float>(i.first) * 100, static_cast<float>(i.second) * 100);
						field.setFillColor(sf::Color::Yellow);
						_window.draw(field);
					}
					checker.setPosition((static_cast<float>(x) * 100), (static_cast<float>(y) * 100));
					if (gameBoard.getCheckers(x, y) == true) {
						if (checkersActions.getColor(x, y) == false) {
							checker.setFillColor(sf::Color::Black);
							checker.setOutlineColor(sf::Color::White);
						}
						if (checkersActions.getColor(x, y) == true) {
							checker.setFillColor(sf::Color::White);
							checker.setOutlineColor(sf::Color::Black);
						}
						_window.draw(checker);
					}
				}
			}
		}
	}
}