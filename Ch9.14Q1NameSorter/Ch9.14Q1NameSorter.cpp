// Ch9.14Q1NameSorter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <iterator>

int numberNames()
{
    std::cout << "Enter the number of names to record:\t";

    int numNames{};
    std::cin >> numNames;

    return numNames;
}

std::string enterName(int index)
{
    std::cout << "Enter name number " << index << " :\t";

    std::string name{};
    std::getline(std::cin >> std::ws, name);

    return name;
}

std::string* addNames(std::string* names, int numNames)
{
    for (int i{ 0 }; i < numNames; ++i)
    {
        names[i] = enterName(i + 1);
    }

    return names;
}

void printNames(std::string* names, int numNames)
{
    for (int i{ 0 }; i < numNames; ++i)
    {
        std::cout << "name #" << (i + 1) << " :\t" << names[i] << "\n";
    }
}

int main()
{
    int numNames{ numberNames() };
    
    std::string* names{ new std::string[numNames]{} };

    names = addNames(names, numNames);

    std::sort(names, names + numNames);

    std::cout << "Names in alphabetical order:\n";
    printNames(names, numNames);

    delete[] names;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
