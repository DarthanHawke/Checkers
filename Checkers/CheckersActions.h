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
			Models::Checkers checker;    // ������� �����
			Models::Checkers** checkers;    // ������ ���� ����� �� ����
			Models::Board gameBoard;    // ��������� ����

			// ������������� ������ CheckersActions
			void initCheckersActions();


		public:
			// ����������� �� ���������
			CheckersActions();

			// �������� ������������ ������������
			CheckersActions& operator = (const CheckersActions& copy);

			// ����������� �����������
			CheckersActions(const CheckersActions& copy);

			// ����������
			~CheckersActions();


			// ����� ����� ��� ����
			void choiseChecker(int x, int y);

			// ������ ������ �����
			void revokeChecker();


			// �������� ����� �� ��������� ������
			void move(int x, int y);


			// ��������� ��������� ����
			std::vector<std::pair<int, int>> tryMove();


			// ����������� ����� �� ���������
			void newGame();

			// �������� ��������� ����
			Models::Board getBoardCheckers();

			// �������� ��������� �����
			Models::Checkers** getCheckers();

			// �������� ���� �����
			bool getColor(int x, int y);
		};
	}
}
