namespace CheckersGame
{
	namespace Models
	{
		class Sell
		{
		private:
			int x;
			int y;
			bool side;
			bool checker;


		public:
			Sell()
			{
				x = 0;
				y = 0;
				side = 0;
				checker = 0;
			}


			void setSide(bool color)
			{
				side = color;
			}


			void setChecker(bool setchecker)
			{
				checker = setchecker;
			}


			bool getSide()
			{
				return side;
			}


			bool getChecker()
			{
				return checker;
			}
		};
	}
}
