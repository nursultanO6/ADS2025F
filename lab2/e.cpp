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

ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr;
    while(head){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return prev;
}
int main(){
    int n, sum = 0; cin >> n;
    ListNode* head = new ListNode("");
    ListNode* dum = head;
    for(int i = 0;i<n;i++){
        string s; cin >> s;
        if(dum ->val == s){
            continue;
        }
        sum++;
        dum->next = new ListNode(s);
        dum = dum->next;
    }

    head = reverse(head);

    cout << "All in all: " << sum << endl;
    cout << "Students: " << endl;

    dum = head;

    while(dum){
        cout << dum->val << endl;
        dum = dum->next;
    }


    
}