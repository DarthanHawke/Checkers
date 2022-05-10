#pragma once
#include "../Checkers/Sell.h"
#include <utility> 


namespace CheckersGame
{
	namespace Models
	{
		class Board
		{
		private:
			Sell** board;    // шахматная доска

			// Инициализация класса Board
			void initBoard();


		public:
			// Конструктор по умолчанию
			Board();

			// Оператор присваивания копированием
			Board& operator = (const Board& copy);

			// Конструктор копирования
			Board(const Board& copy);

			// Деструктор
			~Board();

			// Устанавливает начальные значения доски
			void setupBoard(Sell** board);

			// Устанавливает шашку на поле
			void setonCheckers(int x, int y);

			// Убирает шашку с поля
			void setoffCheckers(int x, int y);

			// Возвращает позицию шашки
			bool getCheckers(int x, int y);

			// Возвращает цвет поля
			bool getField(int x, int y);
		};
	}
}
