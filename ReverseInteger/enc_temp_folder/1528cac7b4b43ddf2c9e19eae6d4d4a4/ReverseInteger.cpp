// ReverseInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
requirements

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21



Constraints:

    -231 <= x <= 231 - 1


*/


#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int32_t UPPER_LIMIT = 2'147'483'647;
constexpr int32_t LOWER_LIMIT = -2'147'483'648;


int reverse(int x) 
{

    /*
    //works with small numbers within the range of int only when * 10
    int reversed = 0;
    int8_t sign = (x < 0) ? (-1) : (1);
    if (x / 10 == 0)
    {
        reversed = x;
    }

    else
    {
        //get the abs value of the number //maybe use abs()
        if (sign == -1)
        {
            x = abs(x);
        }

        while (x > 0)
        {
            reversed = (reversed * 10) + (x % 10);
            x /= 10;
        }
    }
    return reversed * sign;

    */
    int reversednumber1st = 0;
    int reversednumber2nd = 0;
    int reversednumber = 0;
    vector<int> reversedvector;
    int8_t sign = (x < 0) ? (-1) : (1);
    if (x / 10 == 0)
    {
        reversednumber = x;
    }

    else
    {
        //get the abs value of the number //maybe use abs()
        if (sign == -1)
        {
            x = abs(x);
        }

        while (x > 0)
        {
            reversedvector.push_back(x % 10);
            x /= 10;
        }

        for (uint32_t i = 0U ; i < reversedvector.size() / 2U ; i++)
        {
            reversednumber1st = (reversednumber1st * 10) + reversedvector[i];
        }

        for (uint32_t i = reversedvector.size() / 2U; i < reversedvector.size(); i++)
        {
            reversednumber2nd = (reversednumber2nd * 10) + reversedvector[i];
        }

        if (reversednumber1st > 2'147'4)
        {
            if (reversednumber2nd > 83'647)
            {
                reversednumber = 0;
            }
            reversednumber = 0;
        }

        else
        {
            for (auto it : reversedvector)
            {
                reversednumber = (reversednumber * 10) + it;
            }
        }
    }
    return reversednumber * sign;

}

int main()
{
    int number = 1534236469;
    int reversednumber = reverse(number);

    cout << "The reversed number = " << reversednumber << endl;

    while (true)
    {

    }

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
