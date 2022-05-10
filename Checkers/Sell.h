#pragma once


namespace CheckersGame
{
	namespace Models
	{
		class Sell
		{
		private:
			int m_x;    // Координаты ячейки доски
			int m_y;    // Координаты ячейки доски
			bool m_side;    // Цвет поля(true - белый, false - чёрный)
			bool m_checker;    // Наличие шашки(true - стоит на клетке, false - ячейка пуста)


		public:
			// Конструктор по умолчанию
			Sell();

			// Оператор присваивания копированием
			Sell& operator = (const Sell& copy);

			// Конструктор копирования
			Sell(const Sell& copy);

			// Деструктор
			~Sell();

			// Устанавливает цвет поля
			void setSide(bool color);

			// Устанавливает наличие шашки
			void setChecker(bool setchecker);

			// Возвращает цвет поля
			bool getSide();

			// Возвращает наличие шашки
			bool getChecker();
		};
	}
}