#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;
// Question -https://techdevguide.withgoogle.com/resources/former-interview-question-flatten-iterators/#!

class userIterator
{
public:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> iterQue;
    userIterator(vector<vector<int>::iterator> iters, vector<vector<int>::iterator> ends)
    {
        int i;
        int len = iters.size();
        for (i = 0; i < len; i++)
        {
            if (iters[i] != ends[i])
            {
                iterQue.push({iters[i], ends[i]});
            }
        }
    }
    bool hasNext()
    {
        return (!iterQue.empty());
    }
    vector<int>::iterator next()
    {
        auto x = iterQue.front();
        iterQue.pop();
        if (x.first + 1 != x.second)
            iterQue.push({x.first + 1, x.second});
        return x.first;
    }
};

int main()
{
    vector<int> a = {1, 2, 3}, b = {}, c = {7, 8, 9, 10, 11};
    userIterator myitr = userIterator({a.begin(), b.begin(), c.begin()}, {a.end(), b.end(), c.end()});
    while (myitr.hasNext())
    {
        cout << *(myitr.next()) << " ";
    }
    return 0;
}