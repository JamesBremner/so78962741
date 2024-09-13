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

void makeUnique()
{
    std::vector<std::string> vus;
    char vc[] = {'A', 'B', 'C'};
    do
    {
        // std::cout << vc[0] << ' ' << vc[1] << ' ' << vc[2] << '\n';
        std::string us = "xxx";
        us[0] = vc[0];
        us[1] = vc[1];
        us[2] = vc[2];
        vus.push_back(us);
    } while (std::next_permutation(vc, vc + 3));
    for (int i = 0; i < 2*N; i++)
    {
        vcodes[i] += vus[i];
    }
}

void displayCodes()
{
    for (auto &c : vcodes)
        std::cout << c << "\n";
}

main()
{
    generate(3);
    zerobase();
    link();
    makeUnique();
    displayCodes();
    return 0;
}
