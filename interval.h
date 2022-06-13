
#ifndef INTERVAL_H
#define INTERVAL_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol56
{
    struct Interval
    {
        int start;
        int end;
        Interval(int start, int end) : start(start), end(end){};
    };
}
#endif