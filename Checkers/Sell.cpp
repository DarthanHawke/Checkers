#include "../Checkers/Sell.h"


namespace CheckersGame
{
	namespace Models
	{
		Sell::Sell()
			: m_x(0)
			, m_y(0)
			, m_side(0)
			, m_checker(0)
		{}


		Sell& Sell::operator = (const Sell& copy)
		{
			if (this != &copy) {
				m_x = copy.m_x;
				m_y = copy.m_y;
				m_side = copy.m_side;
				m_checker = copy.m_checker;
			}
			return *this;
		}


		Sell::Sell(const Sell& copy)
		{
			m_x = copy.m_x;
			m_y = copy.m_y;
			m_side = copy.m_side;
			m_checker = copy.m_checker;
		}


		Sell::~Sell() {}


		void Sell::setSide(bool color)
		{
			m_side = color;
		}


		void Sell::setChecker(bool setchecker)
		{
			m_checker = setchecker;
		}


		bool Sell::getSide()
		{
			return m_side;
		}


		bool Sell::getChecker()
		{
			return m_checker;
		}
	}
}
