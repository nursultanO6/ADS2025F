#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = nullptr;
    }
};
int main(){
    int n; cin >> n;
    ListNode* head = new ListNode(0);
    ListNode* dum = head;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        dum ->next = new ListNode(k);
        dum = dum -> next;
    }
    int d, p; cin >> d >> p;
    dum = head;
    for(int i = 0; i<p; i++){
        dum = dum->next;
    }
    ListNode* temp = dum->next;
    dum -> next = new ListNode(d);
    dum ->next->next = temp;

    ListNode* start = head->next;
    while(start){
        cout << start->val << " ";
        start = start -> next;
    }
}