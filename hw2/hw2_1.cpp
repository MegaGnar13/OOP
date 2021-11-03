//Visual Studio 2019에서 컴파일 

#include <iostream>
using namespace std;

// Order Class
class Order {
private:
	string orderID;
	string orderName;
public:
	Order();
	Order(string id, string oname);
	~Order();
	string getOrderInfo();
	string getOrderID();
};
// Order Implementation
Order::Order() {
	
}
Order::Order(string id, string oname) {
	orderID = id;
	orderName = oname;
}
Order::~Order() {

}

string Order::getOrderInfo() {
	return orderName;
}
string Order::getOrderID() {
	return orderID;
}



// OrderProcessing Class
class OrderProcessing {
private:
	int maxNumOrder;
	Order* orderQueue;
	int front, rear;
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
	front = -1;
	rear = -1;
	orderQueue = new Order[maxOrder];
	
}

OrderProcessing::~OrderProcessing() {
	delete[] orderQueue;
}

int OrderProcessing::OrderCnt = 0;


int OrderProcessing::addOrder(Order newOrder) {
	
	if ((front == 0 && rear == maxNumOrder - 1) || (rear == (front - 1) % (maxNumOrder - 1))) {
		cout << "Queue is full, Total orders so far : " << OrderCnt << endl;
		return 0;
	}
	else if (front == -1) {
		OrderCnt ++;
		front = rear = 0;
		orderQueue[rear] = newOrder;
		cout << '['<< newOrder.getOrderInfo()<<']' << " is ordered by " << '['<<newOrder.getOrderID()<<']' << ", Total orders so far : " << OrderCnt << endl;
		return 1;
	}
	else if (rear == maxNumOrder - 1 && front != 0) {
		OrderCnt ++;
		rear = 0;
		orderQueue[rear] = newOrder;
		cout << '[' << newOrder.getOrderInfo() << ']' << " is ordered by " << '[' << newOrder.getOrderID() << ']' << ", Total orders so far : " << OrderCnt << endl;
		return 1;
	}
	else {
		OrderCnt ++;
		rear++;
		orderQueue[rear] = newOrder;
		cout << '[' << newOrder.getOrderInfo() << ']' << " is ordered by " << '[' << newOrder.getOrderID() << ']' << ", Total orders so far : " << OrderCnt << endl;
		return 1;
	}
}
int OrderProcessing::serveOrder() {
	if (front == -1) {
		cout << "Queue is empty, Total orders so far : " << OrderCnt << endl;
		return 0;
	}

	Order data = orderQueue[front];
	
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == maxNumOrder - 1) {
		front = 0;
	}
	else {
		front++;
	}
	cout << '[' << data.getOrderInfo() << ']' << " is served to " << '[' << data.getOrderID() << ']' << ", Total orders so far : " << OrderCnt << endl;
	return 1;
	
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
	CoffeeShop starbugs(5);
	Order o1("Alice", "Mocha"), o2("Bob", "Espresso"), o3("David", "Soy"),
		o4("Brown", "Latte"), o5("Evans", "Whip"), o6("Wilson", "Milk");
	/*
	OrderProcessing q(5);
	q.addOrder(o1);
	q.addOrder(o2);
	q.serveOrder();
	q.addOrder(o3);
	q.addOrder(o4);
	q.addOrder(o5);
	q.addOrder(o6);
	q.addOrder(o1);
	q.serveOrder();
	q.serveOrder();
	q.serveOrder();
	q.serveOrder();
	q.serveOrder();
	q.serveOrder();
	q.addOrder(o2);
	*/
	
	starbugs.getOrderProcessingHandler()->addOrder(o1);
	starbugs.getOrderProcessingHandler()->addOrder(o2);
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->addOrder(o3);
	starbugs.getOrderProcessingHandler()->addOrder(o4);
	starbugs.getOrderProcessingHandler()->addOrder(o5);
	starbugs.getOrderProcessingHandler()->addOrder(o6);
	starbugs.getOrderProcessingHandler()->addOrder(o1);
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->addOrder(o2);
	

	return 0;
}