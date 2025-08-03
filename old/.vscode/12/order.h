#pragma once
#include <string>
#include <vector>

using std::string, std::vector;

class Order{
    int id;
    int price;
    string serving_size;
public:
    enum Name {COFFEE, TEA, JUICE};
    Name drinkname;
    enum Status {NEW, IN_PROGRESS, COMPLETED};
    Status orderstatus;
    Order(int id, Name drink, int price, string size): id(id), drinkname(drink), price(price), serving_size(size), orderstatus(NEW){}
    void set_status(Status newstatus);
    Status get_status() const;
    void display() const;
    string get_status_string() const;
    void updateStatus(Status newstatus);
    int get_id() const;
};
class OrderList{
    vector<Order*> orders;
public:
    void AddOrder(const Order& order);
    void UpdateOrderStatus(int id, Order::Status newstatus);
    void DisplayOrders() const;
    ~OrderList();
};