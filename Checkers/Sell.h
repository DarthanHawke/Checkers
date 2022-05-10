#pragma once


namespace CheckersGame
{
	namespace Models
	{
		class Sell
		{
		private:
			int m_x;    // ���������� ������ �����
			int m_y;    // ���������� ������ �����
			bool m_side;    // ���� ����(true - �����, false - ������)
			bool m_checker;    // ������� �����(true - ����� �� ������, false - ������ �����)


		public:
			// ����������� �� ���������
			Sell();

			// �������� ������������ ������������
			Sell& operator = (const Sell& copy);

			// ����������� �����������
			Sell(const Sell& copy);

			// ����������
			~Sell();

			// ������������� ���� ����
			void setSide(bool color);

			// ������������� ������� �����
			void setChecker(bool setchecker);

			// ���������� ���� ����
			bool getSide();

			// ���������� ������� �����
			bool getChecker();
		};
	}
}