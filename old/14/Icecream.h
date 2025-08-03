#pragma once
#include <string>
#include <format>

class Icecream
{
public:
    virtual int getPrice() const = 0;
    virtual int getWeigth() const = 0;
    virtual operator std::string() = 0;
};

class CholocateIcecream : public Icecream
{
private:
    const int price = 50;
    const int weight = 100;

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
        return std::format("Chocolate Icecream");
    }
};

class FruitIce : public Icecream
{
private:
    const int price = 30;
    const int weight = 70;

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
        return std::format("Fruit Ice");
    }
};

class PureIceCream : public Icecream
{
private:
    const int price = 40;
    const int weight = 150;

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
        return std::format("Icecream");
    }
};