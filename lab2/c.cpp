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
    
    ListNode* text = new ListNode(0);
    ListNode* dum = text;

    for(int i = 0; i<n;i++){
        int b; cin >> b;
        dum ->next = new ListNode(b);
        dum = dum -> next;
    }

    ListNode* head = text ->next;
    while(head && head->next){
        cout << head->val << " ";
        head = head->next->next;
    }
    // if(head){
    //     cout << head->val;
    // }

}