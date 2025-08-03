#pragma once
#include <string>
#include <format>

class Topping
{
public:
    virtual int getPrice() const = 0;
    virtual int getWeigth() const = 0;
    virtual operator std::string() = 0;
};

class Caramel : public Topping
{
private:
    const int price = 10;
    const int weight = 20;

public:
    int getPrice() const 
    {
        return price;
    }
    int getWeigth() const
    {
        return weight;
    }
    operator std::string()
    {
        return std::format("Caramel");
    }
};

class Peanuts : public Topping
{
private:
    const int price = 15;
    const int weight = 25;

public:
    int getPrice() const 
    {
        return price;
    }
    int getWeigth() const
    {
        return weight;
    }
    operator std::string()
    {
        return std::format("Peanuts");
    }
};

class Strawberry : public Topping
{
private:
    const int price = 17;
    const int weight = 25;

public:
    int getPrice() const 
    {
        return price;
    }
    int getWeigth() const
    {
        return weight;
    }
    operator std::string()
    {
        return std::format("Strawberry");
    }
};