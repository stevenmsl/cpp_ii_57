#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "interval.h"
#include "util.h"

using namespace std;
using namespace sol56;

/* Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/
tuple<vector<Interval>, Interval, vector<Interval>>
testFixture1()
{
  auto input = vector<Interval>{
      {1, 3}, {6, 9}};

  auto output = vector<Interval>{
      {1, 5}, {6, 9}};

  return make_tuple(input, Interval(2, 5), output);
}

/* Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/
tuple<vector<Interval>, Interval, vector<Interval>>
testFixture2()
{
  auto input = vector<Interval>{
      {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};

  auto output = vector<Interval>{
      {1, 2}, {3, 10}, {12, 16}};

  return make_tuple(input, Interval(4, 8), output);
}
void test1()
{
  auto f = testFixture1();
  auto input = get<2>(f);
  auto iv = vector<vector<int>>();
  for (auto i : input)
    iv.push_back(vector<int>{i.start, i.end});

  cout << "Expect to see: " << Util::toString(iv) << endl;

  Solution sol;
  auto output = sol.insert(input, get<1>(f));

  auto ov = vector<vector<int>>();
  for (auto o : output)
    ov.push_back(vector<int>{o.start, o.end});

  cout << Util::toString(ov) << endl;
}

void test2()
{
  auto f = testFixture2();
  auto input = get<2>(f);
  auto iv = vector<vector<int>>();
  for (auto i : input)
    iv.push_back(vector<int>{i.start, i.end});

  cout << "Expect to see: " << Util::toString(iv) << endl;

  Solution sol;
  auto output = sol.insert(input, get<1>(f));

  auto ov = vector<vector<int>>();
  for (auto o : output)
    ov.push_back(vector<int>{o.start, o.end});

  cout << Util::toString(ov) << endl;
}

main()
{
  test1();
  test2();

  return 0;
}