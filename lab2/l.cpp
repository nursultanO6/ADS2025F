# include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, ListNode *head) {
	int sum = 0,maxs = 0;
    ListNode* sums = head;
    ListNode* maxsums = head;
    while(sums ->next){
        sum += sums->val;
        sums = sums->next;
    }
    while(maxsums){
        ListNode* temp = maxsums;
        maxs = 0;
        while(temp){
            maxs += temp ->val;
            temp = temp ->next;
            sum = max(sum,maxs);
        }
        maxsums= maxsums -> next;
        
    }
    return sum;
}

int main() {
  int n;
  cin >> n;

  ListNode *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ListNode *cur = new ListNode();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
