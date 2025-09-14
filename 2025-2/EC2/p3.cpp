#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *_next) : val(x), next(_next) {}
};

class Solution {
public:
    ListNode* solucion(ListNode* head) {
		if(!head) return nullptr;
        if(!head->next) return head;
        auto head_odd = head;
        auto head_even = head->next;
        auto end_odd = head_odd;
        auto end_even = head_even;
        int cnt = 1;
        auto curr = head;
        ListNode* temp = nullptr;
        while(curr){
            if(cnt % 2 != 0){
                //impar
                temp = curr->next;
                end_odd->next = curr;
                curr = temp;
                end_odd = end_odd->next;
                end_odd->next = nullptr;
            }
            else{
                temp = curr->next;
                end_even->next = curr;
                curr = temp;
                end_even = end_even->next;
                end_even->next = nullptr;                
            }
            cnt++;
        }
        if(head_odd){
            if(end_odd) end_odd->next = head_even;
            if(end_even) end_even->next = nullptr;
            return head_odd;
        }
        return head_even;
    }
};

ListNode* buildList(const vector<int>& a) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : a) { tail->next = new ListNode(v); tail = tail->next; }
    return dummy.next;
}
vector<int> listToVec(ListNode* head) {
    vector<int> v; for (auto* p = head; p; p = p->next) v.push_back(p->val);
    return v;
}
void freeList(ListNode* head) {
    while (head) { auto* q = head->next; delete head; head = q; }
}

vector<int> expectedOddEven(const vector<int>& a) {
    vector<int> odds, evens;
    for (int i = 0; i <  (int)a.size(); ++i) {
        if (i % 2 == 0) odds.push_back(a[i]);  
        else evens.push_back(a[i]);            
    }
    odds.insert(odds.end(), evens.begin(), evens.end());
    return odds;
}

void validate_odd_even(const vector<int>& original, ListNode* out) {
    vector<int> got = listToVec(out);
    vector<int> exp = expectedOddEven(original);
    assert(got == exp);

    vector<int> origOdds, origEvens;
    for (int i = 0; i < (int)original.size(); ++i)
        (i % 2 == 0 ? origOdds : origEvens).push_back(original[i]);

    int k = (int) origOdds.size();
    vector<int> gotOdds(got.begin(), got.begin() + ( (int) got.size() >= k ? k : 0));
    vector<int> gotEvens(got.begin() + ((int)got.size() >= k ? k : 0), got.end());
    assert(gotOdds == origOdds);
    assert(gotEvens == origEvens);
}

void run_test(int id, const vector<int>& input) {
    ListNode* head = buildList(input);
    Solution sol;
    ListNode* out = sol.solucion(head);
    cout << "Test " << id << " ... ";
    validate_odd_even(input, out);
    cout << "OK\n";
    freeList(out);
}

int main() {
    run_test(1, {1,2,3,4,5});               
    run_test(2, {2,1,3,5,6,4,7});          
    run_test(3, {});                        
    run_test(4, {42});                      
    run_test(5, {1,2});                     
    run_test(6, {1,2,3});                    
    run_test(7, {-1,-2,-3,-4,-5,-6});       
    run_test(8, {10,20,30,40,50,60,70,80,90,100}); 
    run_test(9, {5,5,5,5,5});               
    run_test(10, {1,3,5,2,4,6});             
    cout << "Todos los tests pasaron. \n";
    return 0;
}
