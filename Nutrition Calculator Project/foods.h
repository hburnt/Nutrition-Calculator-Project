#ifndef FOODS_H
#define FOODS_H

#include <iostream>
#include <vector>

class Foods {
private:
	std::string M_food_name;
	int M_calories;
	double M_fat;
	double M_sugar;
	double M_protein;
	double M_sodium;
public:
	Foods(std::string food_name, int calories, double fat, double sugar, double protein, double sodium);
	std::string getFoodName() const;
	Foods operator+(Foods total);
	int getCalories() const;
	double getFat() const;
	double getSugar() const;
	double getProtein() const;
	double getSodium() const;
	
};

void getFoodList(const std::vector<Foods>);
void selectingFoods(std::vector<int>&, const std::vector<Foods>);
void userIntake(const std::vector<int>, const std::vector<Foods>, std::vector<Foods>&);
void compareInputs(const Foods, const Foods);
void printTotal(const Foods);
#endif