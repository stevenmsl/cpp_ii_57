#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include "interval.h"

using namespace std;
namespace sol56
{

  class Solution
  {
  private:
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
  };
}
#endif