#include <iostream>
#include <string>
#include <regex>

using namespace std;

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}

bool inputNum(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == false)
        {
            return false;
        }
    }
    return true;
}

bool emailValidation(string& a)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(a,pattern);
}
