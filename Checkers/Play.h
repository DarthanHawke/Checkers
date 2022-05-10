#pragma once
#include <SFML/Graphics.hpp>
#include "../Checkers/CheckersActions.h"


namespace CheckersGame
{
	namespace View
	{
		class Play
		{
		private:
			sf::Vector2i mouseLocation;
			sf::RectangleShape field;
			sf::CircleShape checker;
			std::vector<std::pair<int, int>> travelOptions;
			Actions::CheckersActions checkersActions;
			Models::Board gameBoard;
			Models::Checkers** checkers;
			int m_countStep;    // Колиичество ходов сделанных игроком
			int m_countgame;    // Колличство сыгранных партий
			bool m_step;    // Определяет чей ход(true - игрока, false - компьютера)
			bool m_click;    // Определяет выбрана ли шашка для хода(true - выбрана, false - нет)
			bool m_gameIsStart;    // Определяет, запущена ли игра(true - запущена, false - игрок находится в меню)

			// Инициализация класса Play
			void initPlay();


		public:
			// Конструктор по умолчанию
			Play();

			// Оператор присваивания копированием
			Play& operator = (const Play& copy);

			// Конструктор копирования
			Play(const Play& copy);

			// Деструктор
			~Play();

			// Сбрасываем параметры для новой игры
			void startNewPlay();

			// Возвращает значение, запущена ли игра
			bool getGameIsStart();

			// Возвращает ход компьютера или игрока
			bool getStep();

			// Устанавливает ход компььютера или игрока
			void setStep(bool move);

			// Возвращает, нажата ли кнопка действия(левая кномпка мыши)
			bool getClick();

			// Устанавливает значение кнопки действия(левая кномпка мыши)
			void setClick(bool cl);

			// Стартовое меню
			void gameStart(sf::RenderWindow& _window, sf::Event _event);

			// Отрисовка стартового меню
			void renderStartMenu(sf::RenderWindow& _window);

			// Устанавливает значеение завершения игры
			void gameFinish();

			// Ход игрока
			void process(sf::RenderWindow& _window, sf::Event _event);

			// Ход компьютера
			void update();

			// Отрисовка игры
			void render(sf::RenderWindow& _window);
		};
	}
}