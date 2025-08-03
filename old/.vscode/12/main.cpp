#include <iostream>
#include "order.h"

using namespace std;

int main(){
    OrderList orderlist1;

    Order order1(1, Order::COFFEE, 50, "Medium");
    Order order2(2, Order::JUICE , 100, "Large");
    Order order3(3, Order::TEA, 45, "Small");

    orderlist1.AddOrder(order1);
    orderlist1.AddOrder(order2);
    orderlist1.AddOrder(order3);
    orderlist1.UpdateOrderStatus(2, Order::IN_PROGRESS);

    orderlist1.DisplayOrders();

    return 0;
}