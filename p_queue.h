#pragma once
#ifndef P_QUEUE_H
#define P_QUEUE_H
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
//Implementationen måste ligga i headerfilen då
//kompilatorn inte vet vilken typ som ska användas
//också därför mallen skapas först när klassen används
template<class T>
struct stockOrder {
	std::string fullName;
	T price;
	stockOrder(std::string name, double price) : fullName(name), price(price) {};
	bool operator<(const stockOrder& orderToCompare) const {
		return price < orderToCompare.price;
	}
};
template<class T>
class pQueue {
private:
	std::vector<T> stockOrders;
public:
	T pop() {
		auto poppedStock = stockOrders.at(0);
		stockOrders.erase(stockOrders.begin());
		return poppedStock;
	}
	void push(const T& value) {
		stockOrders.insert(std::upper_bound(stockOrders.begin(), stockOrders.end(), value), value);
	}
	size_t size() {
		return stockOrders.size();
	}
	bool empty() {
		return stockOrders.empty();
	}
};
#endif // !P_QUEUE_H
