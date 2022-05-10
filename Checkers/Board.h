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
			Sell** board;    // ��������� �����

			// ������������� ������ Board
			void initBoard();


		public:
			// ����������� �� ���������
			Board();

			// �������� ������������ ������������
			Board& operator = (const Board& copy);

			// ����������� �����������
			Board(const Board& copy);

			// ����������
			~Board();

			// ������������� ��������� �������� �����
			void setupBoard(Sell** board);

			// ������������� ����� �� ����
			void setonCheckers(int x, int y);

			// ������� ����� � ����
			void setoffCheckers(int x, int y);

			// ���������� ������� �����
			bool getCheckers(int x, int y);

			// ���������� ���� ����
			bool getField(int x, int y);
		};
	}
}
