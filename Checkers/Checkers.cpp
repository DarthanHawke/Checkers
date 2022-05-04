#include <utility>


namespace CheckersGame
{
	namespace Models
	{
		class Checkers
		{
		private:
			// ������� �����, posX - ��� X, posY - ��� Y;
			int posX;
			int posY;
			// ���� �����, 0 - ������ �����, 1 - ����� �����;
			bool color;


		public:
			Checkers()
			{
				posX = 0;
				posY = 0;
				color = false;
			}


			// ������ ��� �������;
			void setChecker(int X, int Y, bool side)
			{
				posX = X;
				posY = Y;
				color = side;
			}


			// ������ ��� �������;
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
