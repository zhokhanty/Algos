#include<iostream>
#include<map>
using namespace std;

struct ListNode{
    char val;
    ListNode* next;
    ListNode* tail;
    ListNode(char x){
        this->val = x;
        this->next = NULL;
        this->tail = NULL;
    }
};

struct LinkedList{
    ListNode* head;
    ListNode* tail;
    int size;
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertNode(char x){
        bool checking = 0;
        ListNode* newOne = new ListNode(x);
        if(head==NULL){
            head = tail = newOne;
        }
        else{
            tail->next = newOne;
            tail = tail->next;
        }
        size++;
    }

    void firstNon(map<char,bool>mp){
        ListNode* temp = head;
        while(temp){
            if(mp[temp->val]==true){
                cout<<temp->val<<" ";
                return;
            }
            temp = temp->next;
        }
        cout<<"-1"<<" ";
    }
};

int main(){
    LinkedList ll;
    bool checking = 0;
    long long n;cin>>n;
    for(int i = 0;i<n;i++){
        map<char, bool>mp;
        map<char, int>mp_1;
        long long num;cin>>num;
        int cnt = 0;
        for(int j = 0;j<num;j++){
            char a;cin>>a;
            ll.insertNode(a);
            if(mp_1[a]==1){
                mp[a] = false;
            }
            else{
                mp_1[a]++;
                mp[a] = true;
            }
            ll.firstNon(mp);
        }
        cout<<endl;
        ll.head = NULL;
    }
}