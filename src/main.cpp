#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::string> vcodes;
std::vector<std::pair<int, int>> vlinks;

// Generate example from question
void generate(int n)
{
    vcodes.clear();
    N = n;
    for (int i = 0; i < n; i++)
        vcodes.push_back("A");
    for (int i = 0; i < n; i++)
        vcodes.push_back("B");

    vlinks.push_back(std::make_pair(1, 4));
    vlinks.push_back(std::make_pair(2, 4));
}
/*
I assume that '4' indicates the first object in the second group

Convert the link indices to zero-based indepedently in each group

*/
void zerobase()
{
    for (auto &l : vlinks)
    {
        l.first -= 1;
        l.second -= N + 1;
    }
}

void link()
{
    for (auto &link : vlinks)
    {
        for (int object = 0; object < N; object++)
            if (object == link.first)
                vcodes[object] += "A";
            else
                vcodes[object] += "B";
        for (int object = 0; object < N; object++)
            if (object == link.second)
                vcodes[N + object] += "A";
            else
                vcodes[N + object] += "C";
    }
}

bool checkUnique()
{
    for (int i1 = 0; i1 < N; i1++)
        for (int i2 = i1 + 1; i2 < N; i2++)
        {
            if (vcodes[i1] == vcodes[i2])
            {
                std::cout << i1 << " == " << i2 << " " << vcodes[i1] << "\n";
                return false;
            }
        }
    std::cout << "all codes are unique\n";
    return true;
}

std::vector<std::string> permute(std::vector<std::string> &base)
{
    std::vector<std::string> ret;
    do
    {
        std::string us = "";
        for( int i = 0; i < base.size(); i++ )
            us += base[i];
        std::cout << us << " ";
        ret.push_back(us);
    } while (std::next_permutation(base.begin(), base.end()));
    std::cout << "\n";
    return ret;
}

void makeUnique()
{
    std::vector<std::string> base1 = { "A","B","C"};
    std::vector<std::string> vus;

    if (vcodes.size() <= 5)
    {

        vus = permute(base1);
    }
    else
    {
        // need more unique codes
        // do a double permutation
        
        vus = permute(base1);
        vus = permute( vus );
    }

    for (int i = 0; i < 2 * N; i++)
    {
        vcodes[i] += vus[i];
    }

    if (!checkUnique())
        exit(1);
}

void displayCodes()
{
    for (auto &c : vcodes)
        std::cout << c << "\n";
}

main()
{
    generate(9);
    zerobase();
    link();
    makeUnique();
    displayCodes();
    return 0;
}
