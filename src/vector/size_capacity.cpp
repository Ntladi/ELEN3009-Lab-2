// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}

//Exercise 2.1

//In line 4: vec: size: 0
//In line 5: capacity: 0

//A size of a vector can be defined as the total number of elements in a vector.
//While the capacity is the maximum number of elements a vector can store before resizing.

//The vector's capacity doubles in order to store more elements. This occurs when the capacity is full and a new elements needs to be added to maximize space efficiency.