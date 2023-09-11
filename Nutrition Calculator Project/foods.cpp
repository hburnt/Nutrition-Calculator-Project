#include "foods.h"
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

Foods::Foods(std::string food_name, int calories, double fat, double sugar, double protein, double sodium){
	M_food_name = food_name;
	M_calories = calories;
	M_fat = fat;
	M_sugar = sugar;
	M_protein = protein;
	M_sodium = sodium;
}

std::string Foods::getFoodName() const {
	return M_food_name;
}
int Foods::getCalories() const {
	return M_calories;
}
double Foods::getFat() const{
	return M_fat;
}
double Foods::getSugar() const {
	return M_sugar;
}
double Foods::getProtein() const {
	return M_protein;
}
double Foods::getSodium() const {
	return M_sodium;
}

void getFoodList(const std::vector<Foods> foodList){
	for (int i = 0; i < foodList.size(); i++){
		std::cout << '(' << i+1 << ") " << foodList.at(i).getFoodName() << std::endl;
	}
}

void selectingFoods(std::vector<int>& userInput, const std::vector<Foods> food_database)
{
	bool done = false;
	while (!done){
		int x = 0;
		getFoodList(food_database);
		std::cout << std::endl << "Select the food that you ate" << std::endl << "Type 11 to quit logging food" << std::endl << std::endl;
		std::cin >> x;
		if (x-1 > food_database.size() + 1 || x-1 < 0){
			std::cout << std::endl << "Invalid Selection!" << std::endl;
		}
		else if (x == 11){
			done = true;
		}
		else{
			userInput.push_back(x-1);
		}
	}
}

void userIntake(const std::vector<int> index, const std::vector<Foods> food_database, std::vector<Foods>& intake){
	for (int i = 0; i < index.size(); i++){
		intake.push_back(food_database.at(index.at(i)));
	}
}

Foods Foods::operator+(Foods total){
	total.M_calories = total.M_calories + M_calories;
	total.M_fat = total.M_fat + M_fat;
	total.M_sugar = total.M_sugar + M_sugar;
	total.M_protein = total.M_protein + M_protein;
	total.M_sodium = total.M_sodium + M_sodium;

	return total;
}

void compareInputs(const Foods daysIntake, const Foods recommendedIntake) {
	if (daysIntake.getCalories() > recommendedIntake.getCalories()) {
		std::cout << "You exceeded 2000 calories today: " << daysIntake.getCalories() << " calories out of " << recommendedIntake.getCalories() << " calories" << std::endl;
	}

	if (daysIntake.getFat() > recommendedIntake.getFat()) {
		std::cout << "You exceeded 70g of fat today: " << daysIntake.getFat() << "g out of " << recommendedIntake.getFat()<< "g" << std::endl;
	}

	if (daysIntake.getSugar() > recommendedIntake.getSugar()) {
		std::cout << "You exceeded 30g of sugar today: " << daysIntake.getSugar() << "g out of " << recommendedIntake.getSugar() << "g" << std::endl;
	}

	if (daysIntake.getProtein() > recommendedIntake.getProtein()) {
		std::cout << "You exceeded 50g of fat today: " << daysIntake.getProtein() << "g out of " << recommendedIntake.getProtein() << "g" << std::endl;
	}

	if (daysIntake.getSodium() > recommendedIntake.getSodium()) {
		std::cout << "You exceeded 2,300mg of fat today: " << daysIntake.getSodium() << "mg out of " << recommendedIntake.getSodium() << "mg" << std::endl;
	}
}

void printTotal(const Foods total){
	std::cout << UNDERLINE << "Today's Intake" << CLOSEUNDERLINE << "     " << UNDERLINE << "Calories" << CLOSEUNDERLINE << "     " << UNDERLINE << "Fat" << CLOSEUNDERLINE;
	std::cout << "     " << UNDERLINE << "Sugar" << CLOSEUNDERLINE << "     " << UNDERLINE << "Protein" << CLOSEUNDERLINE << "     " << UNDERLINE << "Sodium" << CLOSEUNDERLINE<< std::endl;
	std::cout << "                      " << total.getCalories() << "       " << total.getFat() << "     " << total.getSugar() << "     " << total.getProtein() << "         " << total.getSodium() << std::endl;
}