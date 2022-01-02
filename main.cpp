#include <iostream>
#include <unordered_set>

 using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
    if (a == b) { return a; }

    unordered_set<ListNode*> a_visited, b_visited;
    while (a and b) {
      // for symmetric intersection
      if (a->next == b->next) { return a->next; }

      // for asymmetric intersection
      a_visited.insert(a);
      b_visited.insert(b);
      if (a_visited.count(b->next)) { return b->next; }
      if (b_visited.count(a->next)) { return a->next; }

      a = a->next;
      b = b->next;
    }
    while (a) {
      if (b_visited.count(a->next)) { return a->next; }
      a = a->next;
    }
    while (b) {
      if (a_visited.count(b->next)) { return b->next; }
      b = b->next;
    }

    return nullptr;
  }
};

int main() {
  std::cout << "Ok!" << std::endl;
  return 0;
}
