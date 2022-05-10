#pragma once
#include <utility>


namespace CheckersGame
{
	namespace Models
	{
		class Checkers
		{
		private:
			int m_posX;    // ������� �����, posX - ��� X
			int m_posY;    // ������� �����, posY - ��� Y
			bool m_color;    // ���� �����(false - ������, true - �����)


		public:
			// ����������� �� ���������
			Checkers();

			// �������� ������������ ������������
			Checkers& operator = (const Checkers& copy);

			// ����������� �����������
			Checkers(const Checkers& copy);

			// ����������
			~Checkers();

			// ������������� ������� �����
			void setChecker(int X, int Y, bool side);

			// ���������� ������� �����
			std::pair<int, int> getLocate();

			// ���������� ���� �����
			bool getColor();
		};
	}
}