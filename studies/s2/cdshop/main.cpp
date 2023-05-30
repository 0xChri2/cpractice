#include <iostream>
#include "category.h"
#include "bestseller.h"
#include "offer.h"
#include "normal.h"

using namespace std;
int main() {
    category* arr[3];
    arr[0] = new normal(100,10,10);
    arr[1] = new offer(100,10,10);
    arr[2] = new bestseller(100,10,10);

    cout << "Price Normal: " << arr[0]->price(10) << " \n";
    cout << "Price Offer: " << arr[1]->price(10) << " \n";
    cout << "Price Bestseller: " << arr[2]->price(10) << " \n";
    return 0;
}
