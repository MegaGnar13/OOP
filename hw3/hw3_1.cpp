//Visual Studio 2019에서 컴파일 

#include <iostream>
using namespace std;

// Beverage class
class Beverage {
protected:
	string description = "Unknown Beverage";
public:
	string menu;
	double money = 0;
	virtual string getDescription() { return "Unknown Beverage"; }
	virtual double cost() { return 0; }
};


// Espresso class
class Espresso : public Beverage {
public:
	Espresso() {}
	string getDescription() { return "Espresso"; }
	double cost() { return 1.99; }
};


// HouseBlend class
class HouseBlend : public Beverage {
public:
	HouseBlend() {}
	string getDescription() { return "House Blend Coffee"; }
	double cost() { return 0.89; }
};

// Decorator class
class Decorator : public Beverage {
protected:
	Beverage* beverage;
};

// Mocha class
class Mocha : public Decorator {
public:
	Mocha(Beverage* t_beverage) {
		money = t_beverage->cost();
		menu = t_beverage->getDescription();
	}

	string getDescription() {
		return menu + ", Mocha";
	}

	double cost() { money = money + 0.2; return money; }
};

// Whip class
class Whip : public Decorator {
public:
	Whip(Beverage* t_beverage) {
		money = t_beverage->cost();
		menu = t_beverage->getDescription();
	}

	string getDescription() {
		return menu + ", Whip";
	}
	double cost() { money = money + 0.45; return money; }
};



int main() {

	Beverage* beverage1;
	beverage1 = new Espresso();
	beverage1 = new Mocha(beverage1);
	beverage1 = new Mocha(beverage1);
	cout << "Total cost: " << beverage1->cost() << endl;
	cout << beverage1->getDescription() << endl;
	Beverage* beverage2;
	beverage2 = new HouseBlend();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	cout << "Total cost: " << beverage2->cost() << endl;
	cout << beverage2->getDescription() << endl;
	delete beverage1, beverage2;
	return 0;

}