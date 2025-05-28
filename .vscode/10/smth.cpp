#include "head.h"

using namespace std;

Card::Card(string name)
{
    this->name = name;
    id = rand();
}
string Card::to_string()
{
    return name + " " + std::to_string(id);
}
Persons::Persons(string name)
{
    this->name = name;
}
Persons::~Persons()
{
    if(p_id != nullptr){
        delete p_id;
    }
}
bool Persons::get_id(){
    if(p_id != nullptr){
        delete p_id;
    }
    p_id = new Card(name);
    return true;
}
string Persons::to_string(){
    if(p_id != nullptr){
        return name + " with id: " + p_id->to_string();
    }
    else return name + " with no id";
}
