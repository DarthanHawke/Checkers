#pragma once
#include <SFML/Graphics.hpp>
#include "../Checkers/CheckersActions.h"


namespace CheckersGame
{
	namespace View
	{
		class Play
		{
		private:
			sf::Vector2i mouseLocation;
			sf::RectangleShape field;
			sf::CircleShape checker;
			std::vector<std::pair<int, int>> travelOptions;
			Actions::CheckersActions checkersActions;
			Models::Board gameBoard;
			Models::Checkers** checkers;
			int m_countStep;    // ����������� ����� ��������� �������
			int m_countgame;    // ���������� ��������� ������
			bool m_step;    // ���������� ��� ���(true - ������, false - ����������)
			bool m_click;    // ���������� ������� �� ����� ��� ����(true - �������, false - ���)
			bool m_gameIsStart;    // ����������, �������� �� ����(true - ��������, false - ����� ��������� � ����)

			// ������������� ������ Play
			void initPlay();


		public:
			// ����������� �� ���������
			Play();

			// �������� ������������ ������������
			Play& operator = (const Play& copy);

			// ����������� �����������
			Play(const Play& copy);

			// ����������
			~Play();

			// ���������� ��������� ��� ����� ����
			void startNewPlay();

			// ���������� ��������, �������� �� ����
			bool getGameIsStart();

			// ���������� ��� ���������� ��� ������
			bool getStep();

			// ������������� ��� ����������� ��� ������
			void setStep(bool move);

			// ����������, ������ �� ������ ��������(����� ������� ����)
			bool getClick();

			// ������������� �������� ������ ��������(����� ������� ����)
			void setClick(bool cl);

			// ��������� ����
			void gameStart(sf::RenderWindow& _window, sf::Event _event);

			// ��������� ���������� ����
			void renderStartMenu(sf::RenderWindow& _window);

			// ������������� ��������� ���������� ����
			void gameFinish();

			// ��� ������
			void process(sf::RenderWindow& _window, sf::Event _event);

			// ��� ����������
			void update();

			// ��������� ����
			void render(sf::RenderWindow& _window);
		};
	}
}