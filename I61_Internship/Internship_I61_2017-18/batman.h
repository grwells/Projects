class Batman
{
	int initial_State;
	int final_State;
	int current_State;

	public:
		Batman();
		bool isHealthy();
		float lifeExpectancy();
		float getCharge();
		float percentageCharge(); 
		void profile();
		void loadProfile(string file);
		void warningMessage();
		void setBoundaries(int minCharge, int initialState);
};
