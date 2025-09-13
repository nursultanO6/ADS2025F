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
        dum = dum->next;
    }
    ListNode* temp = head->next;
    while(temp && temp->next){
        cout << temp-> val << " ";
        temp = temp -> next -> next;
    }
    if(temp){
      cout << temp->val;
    }

}