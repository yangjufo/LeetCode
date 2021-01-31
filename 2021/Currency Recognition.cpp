#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define US "$"
#define EU "€"
#define JA "￥"

bool isCurrency(string &strAmount)
{
    if (strAmount.empty())
    {
        return false; // empty string is invalid
    }

    int start = 0, end = strAmount.length() - 1;
    if (strAmount[start] == '-')
    {
        start++; // skip negative sign
    }
    else if (strAmount[start] == '(')
    {
        if (strAmount[end] != ')')
        {
            return false;
        }        
        end--;
        start++; // skip parantheses        
    }

    bool supportPoint;

    if (strAmount.find(US, start) == start)
    {
        supportPoint = true; // Dollar allows decimal point
        start++;
    }
    else if (strAmount.find(EU, start) == start)
    {
        supportPoint = true; // Euro allows decimal point
        start += 3;           // Euro symbol takes three characters
    }
    else if (strAmount.find(JA, start) == start)
    {
        supportPoint = false; // Japanese Yen does not allow decimial point
        start += 3;           // Yen symbol takes three characters
    }
    else
    {
        return false; // must have symbol;
    }

    bool leadingZero = false, nonZeroFound = false, thousandFound = false;
    int count = 0; // count digits to validate thousands
    while (start <= end)
    {        
        if (isdigit(strAmount[start]))
        {
            if (strAmount[start] == '0')
            {
                if (!nonZeroFound)
                {
                    if (leadingZero)
                    {
                        return false; // adjacent zeros before '.'; cases after '.' have been handled
                    }
                    leadingZero = true; // first zero is a leading zero
                }
            }
            else
            {
                nonZeroFound = true;
            }
            count++;
        }
        else if (strAmount[start] == ',')
        {                             
            if ((thousandFound && count < 3) || count > 3) {
                return false; // cannot have less than 3 digits between two ',' or more than 3 before first ','
            }
            thousandFound = true;
            count = 0;
        }
        else if (strAmount[start] == '.')
        {
            if (!supportPoint)
            {
                return false; // invalid for Yen'.'
            }

            if (end - start != 2)
            {
                return false; // must be 2 digits after '.'
            }

            if (!isdigit(strAmount[start + 1]) || !isdigit(strAmount[start + 2]))
            {
                return false; // must be digits after '.'
            }                        

            break; // end
        }
        else
        {
            return false; // other characters are not allowed
        }
        start++;
    }
    
    if (thousandFound && count != 3) {
        return false; // must have 3 digits after last ','
    }
    if (leadingZero && nonZeroFound) {
        return false; // leading zero
    }
    if (!leadingZero && !nonZeroFound) {
        return false; // must have at least one digit
    }
        

    return true;
}

int main()
{
    vector<string> amounts = {
        "$450",
        "-€23",
        "(￥2400)",
        "$4500",
        "€0.25",
        "$1,200,000.00",
        "cat",
        "&25",
        "$45,0",
        "(€350",
        "(-$3.50)",
        "￥120.00",
        "$-50",
        " €43.25",
        "$65.",
        "€82.1",
        "48.50",
        "￥1200,000",
        "￥1,200,000",
        "$1.0",
        "$0,111"
        };

    for (string amount : amounts) {
        bool ans = isCurrency(amount);    
        cout << amount << " " << ans << endl;
    }
}