#pragma once
#include "Icecream.h"
#include "Topping.h"
#include "Multiple.h"

class Vendor
{
public:
    enum icecreamTypes
{
    ICECREAM,
    CHOCOLATE,
    FRUIT
};
    enum toppingTypes
{
    CARAMEL,
    PEANUTS,
    STRAWBERRY
};

    Icecream* createIcecream(icecreamTypes type)
    {
        if(type == ICECREAM)
        {
            return new PureIceCream();
        }
        if(type == CHOCOLATE)
        {
            return new CholocateIcecream();
        }
        if(type == FRUIT)
        {
            return new FruitIce();
        }
        throw std::invalid_argument("No such type of an icecream");
    }
    Topping* createTopping(toppingTypes type)
    {
        if(type == CARAMEL)
        {
            return new Caramel();
        }
        if(type == PEANUTS)
        {
            return new Peanuts();
        }
        if(type == STRAWBERRY)
        {
            return new Strawberry();
        }
        throw std::invalid_argument("No such type of a topping");
    }
    
};
class VendorOne : public Vendor{
public:
    IcecreamWithTopping createIcecreamWithTopping(icecreamTypes iceType, toppingTypes topType)
    {
        return IcecreamWithTopping(createIcecream(iceType), createTopping(topType));
    }
};
class VendorMultiple : public Vendor{
private:
    IceCreaWithMultipleToppings MultipleIcecream;
public:
    void AddTopping(toppingTypes type){
        MultipleIcecream.addTopping(createTopping(type));
    }
    IceCreaWithMultipleToppings assemble(){
        return std::move(MultipleIcecream);
    }
    VendorMultiple(icecreamTypes type) : MultipleIcecream(createIcecream(type))
    {
    }
};

class VendorMultiple2 : public Vendor{
private: 
    Icecream* icecream = nullptr;
public: 
    VendorMultiple2& selectIcecreamBase(icecreamTypes type){
        if(icecream != nullptr){
            delete icecream;
        }
        icecream = createIcecream(type);
        return *this;
    }
    
    VendorMultiple2& AddTopping(toppingTypes type){
        icecream = new IcecreamWithTopping(icecream, createTopping(type));
        return *this;
    }
    Icecream* assemble(){
        Icecream* smth = icecream;
        icecream = nullptr;
        return smth;
    }
    ~VendorMultiple2(){
        delete icecream;
    }
};
