#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

struct Card
{
    string shape;
    string num;
};

int main()
{
    vector<string> shapes = {"S1", "S2", "S3", "S4"};
    vector<string> nums = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    // 创建一副牌
    vector<Card> cards;
    for (const auto &shape : shapes)
    {
        for (const auto &num : nums)
        {
            cards.push_back(Card{shape, num});
        }
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);

    for (const auto &card : cards)
    {
        cout << card.shape << " " << card.num << endl;
    }

    return 0;
}
