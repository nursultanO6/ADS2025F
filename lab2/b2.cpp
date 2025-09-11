#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    string val;
    ListNode* next;

    ListNode(string x){
        val = x;
        next = nullptr;
    }
};

int main(){
    int n, k; cin >> n >> k;

    ListNode* head = new ListNode("a");
    ListNode* dum = head;

    for(int i = 0; i<n; i++){
        string s; cin >> s;
        dum->next = new ListNode(s);
        dum = dum->next;
    }

    ListNode* prev = head;

    while(k--){
        prev = prev->next;
    }
    ListNode* half = prev ->next;
    prev-> next= nullptr;
    dum->next = head->next;
    head->next = half;

    ListNode*temp = head->next;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    

}