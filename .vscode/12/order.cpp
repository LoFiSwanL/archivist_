#include "order.h"
#include <iostream>

using std::cout, std::endl;

void Order::set_status(Status newstatus){
    orderstatus = newstatus;
}
Order::Status Order::get_status() const {
    return orderstatus;
}
void Order::display() const{
    cout << "\nID order: " << id << ", Price: " << price << ", Size: " << serving_size << ", Status: " << get_status_string() << endl;
}
string Order::get_status_string() const{
    switch(orderstatus){
        case NEW: return "NEW";
        case IN_PROGRESS: return "IN_PROGRES";
        case COMPLETED: return "COMPLETED";
        default: return "unknown";
    }
}
void Order::updateStatus(Status newstatus){
    orderstatus = newstatus;
}
void OrderList::UpdateOrderStatus(int id, Order::Status newstatus){
    for(auto& order : orders){
        if(order->get_id() == id){
            order->updateStatus(newstatus);
        }
    }
}
int Order::get_id() const{
    return id;
}
void OrderList::AddOrder(const Order& order){
    orders.push_back(new Order(order));
}
void OrderList::DisplayOrders() const{
    for(const auto& order : orders){
        order->display();
    }
}
OrderList::~OrderList() {
    for (Order* order : orders) {
        delete order;
    }
    orders.clear();
}
