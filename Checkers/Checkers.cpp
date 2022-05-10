#include "../Checkers/Checkers.h"


namespace CheckersGame
{
	namespace Models
	{
		Checkers::Checkers()
			: m_posX(0)
			, m_posY(0)
			, m_color(false)
		{}


		Checkers& Checkers::operator = (const Checkers& copy)
		{
			if (this != &copy) {
				m_posX = copy.m_posX;
				m_posY = copy.m_posY;
				m_color = copy.m_color;
			}
			return *this;
		}


		Checkers::Checkers(const Checkers& copy)
		{
			m_posX = copy.m_posX;
			m_posY = copy.m_posY;
			m_color = copy.m_color;
		}


		Checkers::~Checkers() {}

		void Checkers::setChecker(int X, int Y, bool side)
		{
			m_posX = X;
			m_posY = Y;
			m_color = side;
		}


		std::pair<int, int> Checkers::getLocate()
		{
			return std::pair<int, int>(m_posX, m_posY);
		}


		bool Checkers::getColor()
		{
			return m_color;
		}
	}
}
