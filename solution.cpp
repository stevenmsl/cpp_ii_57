#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm> //lower_bound
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

#include "Interval.h"
using namespace sol56;
using namespace std;

/*takeaways
  - insert the new interval into the intervals
    while maintaining it sorted
  - merge the intervals to remove overlappings
*/

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{
  auto it = begin(intervals);
  while (newInterval.start > it->start)
    it++;
  intervals.insert(it, newInterval);

  auto result = vector<Interval>();

  /* merge - refer to question 56 for more information */
  for (auto i : intervals)
  {
    if (result.empty() || result.back().end < i.start)
      result.push_back(i);
    else
      result.back().end = max(result.back().end, i.end);
  }

  return result;
}