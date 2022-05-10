#include "../Checkers/Board.h"


namespace CheckersGame
{
	namespace Models
	{
		void Board::initBoard()
		{
			board = new Sell * [8];
			for (size_t i = 0; i < 8; ++i) {
				board[i] = new Sell[8];
			}
		}


		Board::Board()
		{
			initBoard();
			setupBoard(board);
		}


		Board& Board::operator = (const Board& copy)
		{
			if (this != &copy) {
				for (size_t i = 0; i < 8; ++i) {
					delete[] board[i];
				}
				delete[] board;
				board = new Sell * [8];
				for (size_t i = 0; i < 8; ++i) {
					board[i] = new Sell[8];
					for (size_t j = 0; j < 8; ++j) {
						board[i][j] = copy.board[i][j];
					}
				}
			}
			return *this;
		}


		Board::Board(const Board& copy)
			: board(new Sell* [8])
		{
			for (size_t i = 0; i < 8; ++i) {
				board[i] = new Sell[8];
				for (size_t j = 0; j < 8; ++j) {
					board[i][j] = copy.board[i][j];
				}
			}
		}


		Board::~Board()
		{
			for (size_t i = 0; i < 8; ++i) {
				delete[] board[i];
			}
			delete[] board;
		}


		void Board::setupBoard(Sell** board)
		{
			for (size_t y = 0; y < 8; ++++y) {
				for (size_t x = 0; x < 8; ++++x) {
					board[x][y].setSide(0);    // Чёрное поле
					board[x][y].setChecker(0);    // Шашки нет
				}
				for (size_t x = 1; x < 8; ++++x) {
					board[x][y].setSide(1);    // Белое поле
					board[x][y].setChecker(0);    // Шашки нет
				}
				for (size_t x = 1; x < 8; ++++x) {
					board[x][y + 1].setSide(0);    // Чёрное поле
					board[x][y + 1].setChecker(0);    // Шашки нет
				}
				for (size_t x = 0; x < 8; ++++x) {
					board[x][y + 1].setSide(1);    // Белое поле
					board[x][y + 1].setChecker(0);    // Шашки нет
				}
			}
		}


		void Board::setonCheckers(int x, int y)
		{
			board[x][y].setChecker(1);    // Шашка есть
		}


		void Board::setoffCheckers(int x, int y)
		{
			board[x][y].setChecker(0);    // Шашки нет
		}


		bool Board::getCheckers(int x, int y)
		{
			return board[x][y].getChecker();
		}


		bool Board::getField(int x, int y)
		{
			return board[x][y].getSide();
		}
	}
}
