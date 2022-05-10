#include "../Checkers/CheckersActions.h"


namespace CheckersGame
{
	namespace Actions
	{
		void CheckersActions::initCheckersActions()
		{
			checker = Models::Checkers();
			checkers = new Models::Checkers * [8];
			for (size_t i = 0; i < 8; ++i) {
				checkers[i] = new Models::Checkers[8];
			}
			gameBoard = Models::Board();
		}


		CheckersActions::CheckersActions()
		{
			initCheckersActions();
			newGame();
		}


		CheckersActions& CheckersActions::operator = (const CheckersActions& copy)
		{
			if (this != &copy) {
				checker = copy.checker;
				checkers = new Models::Checkers * [8];
				for (size_t i = 0; i < 8; ++i) {
					checkers[i] = copy.checkers[i];
				}
				gameBoard = copy.gameBoard;
			}
			return *this;
		}


		CheckersActions::CheckersActions(const CheckersActions& copy)
		{
			checker = copy.checker;
			checkers = new Models::Checkers * [8];
			for (size_t i = 0; i < 8; ++i) {
				checkers[i] = copy.checkers[i];
			}
			gameBoard = copy.gameBoard;
		}


		CheckersActions::~CheckersActions()
		{
			delete[] checkers;
		}


		void CheckersActions::choiseChecker(int x, int y)
		{
			checker.setChecker(x, y, getColor(x, y));
		}


		void CheckersActions::revokeChecker()
		{
			checker = Models::Checkers();
		}


		void CheckersActions::move(int x, int y)
		{
			std::vector<std::pair<int, int>> available_moves = tryMove();
			for (auto i : available_moves) {
				if (i.first == x && i.second == y) {
					std::pair<int, int> location = checker.getLocate();
					gameBoard.setoffCheckers(location.first, location.second);    // Удаляем шашку с доски;
					checkers[location.first][location.second] = Models::Checkers();    // Удаляем шашку;
					checker.setChecker(x, y, checker.getColor());    // Переставляем активную шашку;
					checkers[x][y] = checker;    // Запоминаем новую шашку;
					gameBoard.setonCheckers(x, y);    // Переставляем шашку на доске;
				}
			}
		}


		std::vector<std::pair<int, int>> CheckersActions::tryMove()
		{
			std::vector<std::pair<int, int>> available_moves;
			std::pair<int, int> location = checker.getLocate();
			int sign = -1;
			bool flag = false;
			if (checkers[location.first][location.second].getColor() == true) {
				sign = -1;
				flag = false;
			}
			else {
				sign = 1;
				flag = true;
			}
			if (gameBoard.getCheckers(location.first, location.second) == true) {
				bool center = true;
				if (location.first <= 7 && location.first >= 0
					&& location.second + sign * 1 <= 7 && location.second + sign * 1 >= 0)
					center = gameBoard.getCheckers(location.first, location.second + sign * 1);
				if (center != true)
					available_moves.push_back(std::pair<int, int>(location.first, location.second + sign * 1));
			}
			return available_moves;
		}


		void CheckersActions::newGame()
		{
			for (int y = 0; y < 4; ++y) {
				for (int x = 4; x < 8; ++x) {
					if (gameBoard.getCheckers(x, y))
						gameBoard.setoffCheckers(x, y);    // Удаляем шашку с поля
				}
			}
			for (int y = 4; y < 8; ++y) {
				for (int x = 0; x < 4; ++x) {
					if (gameBoard.getCheckers(x, y))
						gameBoard.setoffCheckers(x, y);    // Удаляем шашку с поля
				}
			}
			for (int y = 0; y < 4; ++y) {
				for (int x = 0; x < 4; ++x) {
					gameBoard.setonCheckers(x, y);    // Отмечаем шашку на поле
					checkers[x][y].setChecker(x, y, false);    // Добавляем чёрную шашку
				}
			}
			for (int y = 4; y < 8; ++y) {
				for (int x = 4; x < 8; ++x) {
					gameBoard.setonCheckers(x, y);    // Отмечаем шашку на поле
					checkers[x][y].setChecker(x, y, true);    // Добавляем белую шашку
				}
			}
		}


		Models::Board CheckersActions::getBoardCheckers()
		{
			return gameBoard;
		}


		Models::Checkers** CheckersActions::getCheckers()
		{
			return checkers;
		}


		bool CheckersActions::getColor(int x, int y)
		{
			return checkers[x][y].getColor();
		}
	}
}
