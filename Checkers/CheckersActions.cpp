#include "../Checkers/Board.cpp"
#include "../Checkers/Checkers.cpp"
#include <vector>


namespace CheckersGame
{
	namespace Actions
	{
		class CheckersActions
		{
		private:
			Models::Checkers checker = Models::Checkers();
			Models::Checkers** checkers = new Models::Checkers * [8];
			Models::Board game_board = Models::Board();


		public:
			CheckersActions()
			{
				for (size_t i = 0; i < 8; ++i)
				{
					checkers[i] = new Models::Checkers[8];
				}
				new_game();
			}


			// выбор шашки для хода
			void choise_checker(int x, int y)
			{
				checker.setChecker(x, y, getColor(x, y));
			}


			void revoke_checker()
			{
				checker = Models::Checkers();
			}


			// сдвигает шашку на выбранную клетку
			void move(int x, int y)
			{
				std::vector<std::pair<int, int>> available_moves = try_move();
				for (auto i : available_moves)
				{
					if (i.first == x && i.second == y)
					{
						std::pair<int, int> location = checker.getLocate();
						game_board.setoffCheckers(location.first, location.second);	// удаляем шашку с доски;
						checkers[location.first][location.second] = Models::Checkers();	// удаляем шашку;
						if (x != location.first)	// удаляем съеденную шашку;
						{
							int stepx = location.first + ((x - location.first) / 2);
							int stepy = location.second + ((y - location.second) / 2);
							game_board.setoffCheckers(stepx, stepy);
							checkers[stepx][stepy] = Models::Checkers();
						}
						checker.setChecker(x, y, checker.getColor());	// переставляем активную шашку;
						checkers[x][y] = checker;	// запоминаем новую шашку;
						game_board.setonCheckers(x, y);	// переставляем шашку на доске;
					}
				}
			}


			// проверяем доступные ходы
			std::vector<std::pair<int, int>> try_move()
			{
				std::vector<std::pair<int, int>> available_moves;
				std::pair<int, int> location = checker.getLocate();
				int sign = -1;
				bool flag = false;
				if (checkers[location.first][location.second].getColor() == true)
				{
					sign = -1;
					flag = false;
				}
				else
				{
					sign = 1;
					flag = true;
				}
				if (game_board.getCheckers(location.first, location.second) == true)
				{
					int count = 1;
					bool left = false;
					if (location.first - count && location.first - count >= 0 && 
						location.second + sign * count <= 7 && location.second + sign * count >= 0)
					{
						left = game_board.getCheckers(location.first - count, location.second + sign * count);
					}
					bool right = true;
					if (location.first - (count + 1) <= 7 && location.first - (count + 1) >= 0 && 
						location.second + sign * (count + 1) <= 7 && location.second + sign * (count + 1) >= 0)
					{
						right = game_board.getCheckers(location.first - (count + 1), location.second + sign * (count + 1));
					}
					while (left == true && right != true &&
						(checkers[location.first - count][location.second + sign * count].getColor() == flag))
					{
						available_moves.push_back(std::pair<int, int>(location.first - (count + 1), location.second + sign * (count + 1)));
						++count;
						if (location.first - count && location.first - count >= 0 &&
							location.second + sign * count <= 7 && location.second + sign * count >= 0)
						{
							left = game_board.getCheckers(location.first - count, location.second + sign * count);
						}
						else 
						{
							left = false;
						}
						if (location.first - (count + 1) <= 7 && location.first - (count + 1) >= 0 &&
							location.second + sign * (count + 1) <= 7 && location.second + sign * (count + 1) >= 0)
						{
							right = game_board.getCheckers(location.first - (count + 1), location.second + sign * (count + 1));
						}
						else
						{
							right = true;
						}
					}
					count = 1;
					left = false;
					if (location.first + count <= 7 && location.first + count >= 0 && 
						location.second + sign * count <= 7 && location.second + sign * count >= 0)
					{
						left = game_board.getCheckers(location.first + count, location.second + sign * count);
					}
					right = true;
					if (location.first + (count + 1) <= 7 && location.first + (count + 1) >= 0 && 
						location.second + sign * (count + 1) <= 7 && location.second + sign * (count + 1) >= 0)
					{
						right = game_board.getCheckers(location.first + (count + 1), location.second + sign * (count + 1));
					}
					while (left == true && right != true &&
						(checkers[location.first + count][location.second + sign * count].getColor() == flag))
					{
						available_moves.push_back(std::pair<int, int>(location.first + (count + 1), location.second + sign * (count + 1)));
						++count;
						if (location.first + count <= 7 && location.first + count >= 0 &&
							location.second + sign * count <= 7 && location.second + sign * count >= 0)
						{
							left = game_board.getCheckers(location.first + count, location.second + sign * count);
						}
						else
						{
							left = false;
						}
						if (location.first + (count + 1) <= 7 && location.first + (count + 1) >= 0 &&
							location.second + sign * (count + 1) <= 7 && location.second + sign * (count + 1) >= 0)
						{
							right = game_board.getCheckers(location.first + (count + 1), location.second + sign * (count + 1));
						}
						else
						{
							right = true;
						}
					}
					left = true;
					if (location.first - 1 <= 7 && location.first - 1 >= 0 && 
						location.second + sign * 1 <= 7 && location.second + sign * 1 >= 0)
					{
						left = game_board.getCheckers(location.first - 1, location.second + sign * 1);
					}
					right = true;
					if (location.first + 1 <= 7 && location.first + 1 >= 0 && 
						location.second + sign * 1 <= 7 && location.second + sign * 1 >= 0)
					{
						right = game_board.getCheckers(location.first + 1, location.second + sign * 1);
					}
					bool center = true;
					if (location.first <= 7 && location.first >= 0 && 
						location.second + sign * 1 <= 7 && location.second + sign * 1 >= 0)
					{
						center = game_board.getCheckers(location.first, location.second + sign * 1);
					}
					if ((left != true || checkers[location.first][location.second].getColor() != flag) &&
						(right != true || checkers[location.first][location.second].getColor() != flag) &&
						center != true)
					{
						available_moves.push_back(std::pair<int, int>(location.first, location.second + sign * 1));
					}
				}
				return available_moves;
			}


			// расставляет шашки по умолчанию
			void new_game()
			{
				for (int y = 0; y < 4; ++y)
				{
					for (int x = 0; x < 4; ++x)
					{
						game_board.setonCheckers(x, y);	// отмечаем шашку на поле
						checkers[x][y].setChecker(x, y, false);	// добавляем чёрную шашку
					}
				}
				for (int y = 4; y < 8; ++y)
				{
					for (int x = 4; x < 8; ++x)
					{
						game_board.setonCheckers(x, y);	// отмечаем шашку на поле
						checkers[x][y].setChecker(x, y, true);	// добавляем белую шашку
					}
				}
			}


			Models::Board getBoardCheckers()
			{
				return game_board;
			}


			Models::Checkers** getCheckers()
			{
				return checkers;
			}


			bool getColor(int x, int y)
			{
				return checkers[x][y].getColor();
			}
		};
	}
}
