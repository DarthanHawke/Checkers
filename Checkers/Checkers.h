#pragma once
#include <utility>


namespace CheckersGame
{
	namespace Models
	{
		class Checkers
		{
		private:
			int m_posX;    // Позиция шашки, posX - ось X
			int m_posY;    // Позиция шашки, posY - ось Y
			bool m_color;    // Цвет шашки(false - чёрный, true - белый)


		public:
			// Конструктор по умолчанию
			Checkers();

			// Оператор присваивания копированием
			Checkers& operator = (const Checkers& copy);

			// Конструктор копирования
			Checkers(const Checkers& copy);

			// Деструктор
			~Checkers();

			// Устанавливает позицию шашки
			void setChecker(int X, int Y, bool side);

			// Возвращает позицию шашки
			std::pair<int, int> getLocate();

			// Возвращает цвет шашки
			bool getColor();
		};
	}
}