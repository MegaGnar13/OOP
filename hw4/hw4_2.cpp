//Visual Studio 2019에서 컴파일 
#include <iostream>
#include <string>
#include <vector>
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


// Order Class
class Order {
private:
	string orderID;
	string orderName;
	double orderCost;
public:

	Order();
	Order(string id, string oname);
	Order(string id, Beverage* omenu);
	~Order();
	string getOrderInfo();
	string getOrderID();
	double getCost();
	friend istream& operator>>(istream& in, Order& t_o) {

		string t_o_orderID = t_o.getOrderID();

		int num_of_Base;
		int num_of_deco;
		Beverage* omenu;

		cout << "Enter your name for the order: ";

		in >> t_o.orderID;

		cout << "Select the Base Beverage: (1) Espresso ($1.99), (2) HouseBlend ($0.89) =>" << endl;
		in >> num_of_Base;
		if (num_of_Base == 1) {
			omenu = new Espresso();
		}
		else {
			omenu = new HouseBlend();
		}


		while (true) {
			cout << "Select the Decorators.After selecting all deco, press(3) : (1) Mocha($0.20), (2) Whipped Cream($0.45), (3) Done =>" << endl;
			in >> num_of_deco;
			if (num_of_deco == 3) {
				break;
			}
			else if (num_of_deco == 1) {
				omenu = new Mocha(omenu);
			}
			else {
				omenu = new Whip(omenu);
			}

		}
		cout << "Finalizing the Order..." << endl;

		t_o.orderCost = omenu->cost();
		t_o.orderName = omenu->getDescription();


		return in;

	}


};
// Order Implementation
Order::Order() {
	orderID = "none";
	orderName = "none";

}
Order::Order(string id, string oname) {
	orderID = id;
	orderName = oname;
}

Order::Order(string id, Beverage* omenu) {
	orderID = id;
	orderName = omenu->getDescription();
	orderCost = omenu->money;
}
Order::~Order() {

}

string Order::getOrderInfo() {
	return orderName;
}
string Order::getOrderID() {
	return orderID;
}
double Order::getCost() {
	return orderCost;
}


// OrderProcessing Class
class OrderProcessing {
private:
	int maxNumOrder;
	vector<Order> orderQueue;
	static int OrderCnt;
public:
	int addOrder(Order newOrder);
	int serveOrder();
	OrderProcessing(int maxOrder);
	~OrderProcessing();



};

// OrderProcessing Implementation

OrderProcessing::OrderProcessing(int maxOrder) {
	maxNumOrder = maxOrder;
	orderQueue;

}

OrderProcessing::~OrderProcessing() {
	
}

int OrderProcessing::OrderCnt = 0;


int OrderProcessing::addOrder(Order newOrder) {
	if (orderQueue.size() == maxNumOrder) {
		cout << "Queue is full, Total orders so far : " << OrderCnt << endl;
		return 0;
	}

	else
	{	
		OrderCnt++;
		orderQueue.push_back(newOrder);
		cout << '[' << newOrder.getOrderInfo() << ']' << " is ordered by " << '[' << newOrder.getOrderID() << ']' << " with cost $" << newOrder.getCost() << " Total orders so far : " << OrderCnt << endl;
		return 1;
	}

	
}
int OrderProcessing::serveOrder() {
	if (orderQueue.empty()) {
		cout << "Queue is empty, Total orders so far : " << OrderCnt << endl;
		return 0;
	}

	else {
		Order data = orderQueue.front();
		orderQueue.erase(orderQueue.begin());
		cout << '[' << data.getOrderInfo() << ']' << " is served to " << '[' << data.getOrderID() << ']' << ", Total orders so far : " << OrderCnt << endl;
		return 1;
	}
	
}

// CoffeShop Class
class CoffeeShop {
private:
	int numOfTables; //The number of in-dining tables
	string name;
	OrderProcessing* myOrderProcessing; //My order processing
public:
	CoffeeShop(); //Use Create a default number of table
	CoffeeShop(int numTable);
	CoffeeShop(int numTable, string shop_name);
	~CoffeeShop();
	OrderProcessing* getOrderProcessingHandler();
};
// CoffeeShop implementation
CoffeeShop::CoffeeShop() {
	numOfTables = 5;
	name = "starbugs";
	myOrderProcessing = new OrderProcessing(5);
}
CoffeeShop::CoffeeShop(int numTable) {
	numOfTables = numTable;
	name = "starbugs";
	myOrderProcessing = new OrderProcessing(numTable);
}
CoffeeShop::CoffeeShop(int numTable, string shop_name) {
	numOfTables = numTable;
	name = shop_name;
	myOrderProcessing = new OrderProcessing(numTable);
}
CoffeeShop::~CoffeeShop() {
	delete myOrderProcessing;
}

OrderProcessing* CoffeeShop::getOrderProcessingHandler() {
	return myOrderProcessing;

}

int main() {
	Beverage* beverage1;
	beverage1 = new Espresso(); //1.99
	beverage1 = new Mocha(beverage1); //0.20
	beverage1 = new Mocha(beverage1); //0.20
	cout << "Total cost: " << beverage1->cost() << endl;
	cout << beverage1->getDescription() << endl;
	Beverage* beverage2;
	beverage2 = new HouseBlend(); //0.89
	beverage2 = new Mocha(beverage2); //0.20
	beverage2 = new Whip(beverage2); //0.45
	cout << "Total cost: " << beverage2->cost() << endl;
	cout << beverage2->getDescription() << endl;
	CoffeeShop starbugs(5);
	Order o1("Alice", beverage1), o2("Bob", beverage2);
	starbugs.getOrderProcessingHandler()->addOrder(o1);
	starbugs.getOrderProcessingHandler()->addOrder(o2);
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	return 0;
}