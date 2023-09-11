#include <iostream>
#include <vector>
#include "foods.h"
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

using namespace std;

int main() {
	vector<Foods> food_database;
	vector<int> user_selections;
	vector<Foods> intake;
	Foods totalIntake("", 0, 0, 0, 0, 0);
	Foods compareValues("Recommended", 2000, 70, 30, 50, 2300);

	food_database.push_back(Foods("Avacado", 160, 15, 1, 2, 7));
	food_database.push_back(Foods("Apple", 52, 0.2, 10.4, 0.3, 2));
	food_database.push_back(Foods("Steak", 179, 7.6, 0, 26, 60));
	food_database.push_back(Foods("Potato Chips", 160, 10, 0.5, 2, 170));
	food_database.push_back(Foods("Cod Fish", 90, 0.5, 0, 20, 79.5));
	food_database.push_back(Foods("Broccoli", 31, 0.4, 1.5, 2.5, 0));
	food_database.push_back(Foods("French Toast", 219, 11, 4, 7.3, 237));
	food_database.push_back(Foods("Top Ramen", 380, 14, 0, 9, 1590));
	food_database.push_back(Foods("Eggs", 78, 5, 0.5, 6, 62));
	food_database.push_back(Foods("Ice Cream", 273, 15, 28, 4.6, 106));

	selectingFoods(user_selections, food_database);
	userIntake(user_selections, food_database, intake);
	
	for (int i = 0; i < intake.size(); i++) {
		totalIntake = totalIntake + intake.at(i);
	}
	compareInputs(totalIntake, compareValues);
	
	return 0;
}