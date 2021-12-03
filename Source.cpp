#include "p_queue.h"
#include <iostream>
#include <stdlib.h>
int main() {
	srand(time(NULL));
	pQueue<stockOrder<double>> buyOrders;
	pQueue<stockOrder<double>> sellOrders;
	for (int i = 0; i < 7; i++) {
		buyOrders.push(stockOrder<double>("Erik Pendel", rand() % 30 + 1)); //Between 1-30
		buyOrders.push(stockOrder<double>("Jarl Wallenburg", rand() % 30 + 1));
		buyOrders.push(stockOrder<double>("Joakim von Anka", rand() % 30 + 1));

		sellOrders.push(stockOrder<double>("Erik Pendel", rand() % 30 + 1));
		sellOrders.push(stockOrder<double>("Jarl Wallenburg", rand() % 30 + 1));
		sellOrders.push(stockOrder<double>("Joakim von Anka", rand() % 30 + 1));
	}
	while (!buyOrders.empty() && !sellOrders.empty()) {
		auto currBuy = buyOrders.pop();
		auto currSell = sellOrders.pop();
		if ((currSell.price <= currBuy.price) && (currBuy.fullName != currSell.fullName)) { //Dont buy stocks from yourself
			std::cout << currBuy.fullName << " k\x94pte aktie fr\x86n " << currSell.fullName << " f\x94r priset " << currSell.price << "sek" << std::endl;
		}
		else {
			sellOrders.push(currSell);
		}
	}
	return 0;
}