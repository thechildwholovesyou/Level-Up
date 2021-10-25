#include<bits/stdc++.h>
#include "hashtable.h"
using namespace std;

int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("BurgerPizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 35);
    price_menu.print();
}