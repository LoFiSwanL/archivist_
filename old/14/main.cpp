#include "Vendor.h"
#include <iostream>

int main()
{
    VendorOne ice;
    std::cout << std::string(*ice.createIcecream(Vendor::ICECREAM)) << std::endl;
    std::cout << std::string(*ice.createTopping(Vendor::STRAWBERRY)) << std::endl;
    std::cout << std::string(ice.createIcecreamWithTopping(Vendor::ICECREAM, Vendor::PEANUTS)) << std::endl;

    VendorMultiple cream(Vendor::icecreamTypes::FRUIT);
    cream.AddTopping(Vendor::STRAWBERRY);
    cream.AddTopping(Vendor::STRAWBERRY);
    cream.AddTopping(Vendor::STRAWBERRY);

    std::cout << std::string(cream.assemble()) << std::endl;

    VendorMultiple2 icecream;
    icecream.selectIcecreamBase(Vendor::icecreamTypes::CHOCOLATE);
    icecream.AddTopping(Vendor::toppingTypes::CARAMEL);
    icecream.AddTopping(Vendor::toppingTypes::CARAMEL);

    std::cout << std::string(*icecream.assemble()) << std::endl;

    std::cout << std::string(*VendorMultiple2().selectIcecreamBase(Vendor::icecreamTypes::FRUIT).AddTopping(Vendor::CARAMEL).AddTopping(Vendor::PEANUTS).assemble()) << std::endl;
    
    return 0;
}