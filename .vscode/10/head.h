#pragma once
#include <string>

using std::string;

class Card
{
    string name;
    int id;
public:
    Card(string name);
    string to_string();
};

class Persons
{
    string name;
    Card* p_id = nullptr;
public:
    Persons(string name);
    ~Persons();
    bool get_id();
    string to_string();
};