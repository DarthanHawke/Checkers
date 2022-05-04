#include "../Checkers/Sell.cpp"


namespace CheckersGame
{
	namespace Models
	{
		class Board
		{
		private:
			// шахматная доска
			Sell** board = new Sell* [8];


		public:
			Board()
			{
				for (size_t i = 0; i < 8; ++i)
				{
					board[i] = new Sell[8];
				}

				for (size_t y = 0; y < 8; ++++y)
				{
					for (size_t x = 0; x < 8; ++++x)
					{
						board[x][y].setSide(0);	// чёрное поле
						board[x][y].setChecker(0);	// шашки нет
					}
					for (size_t x = 1; x < 8; ++++x)
					{
						board[x][y].setSide(1);	// белое поле
						board[x][y].setChecker(0);	//шашки нет
					}
					for (size_t x = 1; x < 8; ++++x)
					{
						board[x][y + 1].setSide(0);	// чёрное поле
						board[x][y + 1].setChecker(0);	// шашки нет
					}
					for (size_t x = 0; x < 8; ++++x)
					{
						board[x][y + 1].setSide(1);	// белое поле
						board[x][y + 1].setChecker(0);	//шашки нет
					}
				}
			}


			void setonCheckers(int x, int y)
			{
				board[x][y].setChecker(1);	// шашка есть
			}


			void setoffCheckers(int x, int y)
			{
				board[x][y].setChecker(0);	// шашки нет
			}


			bool getCheckers(int x, int y)
			{
				return board[x][y].getChecker();
			}


			bool getField(int x, int y)
			{
				return board[x][y].getSide();
			}
		};
	}
}
