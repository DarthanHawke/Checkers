#include <utility>


namespace CheckersGame
{
	namespace Models
	{
		class Checkers
		{
		private:
			// позиция шашки, posX - ось X, posY - ось Y;
			int posX;
			int posY;
			// цвет шашки, 0 - чёрные шашки, 1 - белые шашки;
			bool color;


		public:
			Checkers()
			{
				posX = 0;
				posY = 0;
				color = false;
			}


			// сеттер для позиции;
			void setChecker(int X, int Y, bool side)
			{
				posX = X;
				posY = Y;
				color = side;
			}


			// геттер для позиции;
			std::pair<int, int> getLocate()
			{
				return std::pair<int, int>(posX, posY);
			}

			bool getColor()
			{
				return color;
			}
		};
	}
}
