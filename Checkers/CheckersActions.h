#pragma once
#include "../Checkers/Board.h"
#include "../Checkers/Checkers.h"
#include <vector>


namespace CheckersGame
{
	namespace Actions
	{
		class CheckersActions
		{
		private:
			Models::Checkers checker;    // Текущая шашка
			Models::Checkers** checkers;    // Массив всех шашек на поле
			Models::Board gameBoard;    // Шахматное поле

			// Инициализация класса CheckersActions
			void initCheckersActions();


		public:
			// Конструктор по умолчанию
			CheckersActions();

			// Оператор присваивания копированием
			CheckersActions& operator = (const CheckersActions& copy);

			// Конструктор копирования
			CheckersActions(const CheckersActions& copy);

			// Деструктор
			~CheckersActions();


			// Выбор шашки для хода
			void choiseChecker(int x, int y);

			// Отмена выбора шашки
			void revokeChecker();


			// Сдвигаем шашку на выбранную клетку
			void move(int x, int y);


			// Проверяем доступные ходы
			std::vector<std::pair<int, int>> tryMove();


			// Расставляем шашки по умолчанию
			void newGame();

			// Получаем шахматное поле
			Models::Board getBoardCheckers();

			// Получаем доступные шашки
			Models::Checkers** getCheckers();

			// Получаем цвет шашки
			bool getColor(int x, int y);
		};
	}
}
