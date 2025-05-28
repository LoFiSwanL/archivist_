#pragma once
#include <string>
#include "Topping.h"
#include "Icecream.h"
#include <memory>
#include <vector>
 
class IcecreamWithTopping : public Icecream
{
private:
    std::unique_ptr<Icecream> ice;
    std::unique_ptr<Topping> top;
public:
    IcecreamWithTopping(Icecream* ice, Topping* top) : ice(ice), top(top)
    {
    }

    int getPrice() const 
    {
        return ice->getPrice() + top->getPrice();
    }
    int getWeigth() const
    {
        return ice->getWeigth() + top->getWeigth();
    }
    operator std::string()
    {
        return std::string(*ice) + std::string(*top) +
         std::format("costs{} uah and it's {}g", getPrice(), getWeigth());
    }
};

class IceCreaWithMultipleToppings{
private: 
    std::unique_ptr<Icecream> ice;
    std::vector<std::unique_ptr<Topping>> tops;
public: 
    IceCreaWithMultipleToppings(Icecream* ice) : ice(ice){
    }
    void addTopping(Topping* top){
        tops.emplace_back(top);
    }

    int getPrice() const{
        int sum = 0;
        for(auto& top: tops){
            sum += top->getPrice();
        }
        return ice->getPrice() + sum;
    }

    int getWeigth() const{
        int sum = 0;
        for(auto& top: tops){
            sum += top->getWeigth();
        }
        return ice->getWeigth() + sum;
    }

    operator std::string()
    {
        std::string sum;
        for(auto& top: tops){
            if(!sum.empty()){
                sum += ", ";
            }
            sum += std::string (*top);
        }
        return std::string(*ice) + " " + sum + " " + std::format("costs{} uah and it's {}g", getPrice(), getWeigth());
    }
};
