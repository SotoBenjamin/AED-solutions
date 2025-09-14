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
	ListNode* first_less(ListNode* head, int x){
        ListNode* ans = nullptr;
        auto curr = head;
        while(curr){
            if(curr->val < x){
                ans = curr;
                break;
            }
            curr = curr->next;
        }
        return ans;
    }
    ListNode* first_greater(ListNode* head,int x){
        ListNode* ans = nullptr;
        auto curr = head;
        while(curr){
            if(curr->val >= x){
                ans = curr;
                break;
            }
            curr = curr->next;
        }
        return ans;
    }
    ListNode* solucion(ListNode* head, int x) {
		if(!head) return nullptr;
        auto head_less = first_less(head,x);
        auto head_greater = first_greater(head,x);
        auto end_less = head_less;
        auto end_greater = head_greater;
        auto curr = head;
        //cout<<head_less->val<<"\n";
        //cout<<head_greater->val<<"\n";
        ListNode* temp = nullptr;
        while(curr){
            if(curr == head_less || curr == head_greater){
                curr = curr->next;
                continue;
            }
            if(curr->val < x){
                temp = curr->next;
                curr->next = nullptr;
                end_less->next = curr;
                curr = temp;
                end_less = end_less->next;
            }
            else{
                temp = curr->next;
                curr->next = nullptr;
                end_greater->next = curr;
                curr = temp;
                end_greater = end_greater->next;
            }
        }
        if(head_less){
            if(end_less) end_less->next = head_greater;
            if(end_greater) end_greater->next = nullptr;
            return head_less;
        }
        return head_greater;
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
template <class It, class Pred>
vector<typename iterator_traits<It>::value_type> subseq(It b, It e, Pred pred) {
    using T = typename iterator_traits<It>::value_type;
    vector<T> out; for (; b != e; ++b) if (pred(*b)) out.push_back(*b);
    return out;
}

void validate_partition(const vector<int>& original, int x, ListNode* result) {
    vector<int> res = listToVec(result);

    bool seen_ge = false;
    for (int v : res) {
        if (v >= x) seen_ge = true;
        if (seen_ge && v < x) assert(false && "Aparece un <x después de >=x");
    }

    auto orig_lt = subseq(original.begin(), original.end(), [&](int v){return v < x;});
    auto orig_ge = subseq(original.begin(), original.end(), [&](int v){return v >= x;});
    auto res_lt  = subseq(res.begin(),      res.end(),      [&](int v){return v < x;});
    auto res_ge  = subseq(res.begin(),      res.end(),      [&](int v){return v >= x;});
    assert(orig_lt == res_lt);
    assert(orig_ge == res_ge);

    auto A = original, B = res;
    sort(A.begin(), A.end()); sort(B.begin(), B.end());
    assert(A == B);
    assert(original.size() == res.size());
}

void expect_exact(ListNode* head, const vector<int>& expected) {
    assert(listToVec(head) == expected);
}

void run_test(int id, const vector<int>& input, int x, const vector<int>& expected) {
    ListNode* head = buildList(input);
    Solution sol;
    ListNode* out = sol.solucion(head, x);
    cout << "Test " << id << " ... ";
    validate_partition(input, x, out);
    expect_exact(out, expected);
    cout << "OK\n";
    freeList(out);
}

/* -------- 10 tests -------- */
int main() {
    // 1) Caso clásico
    run_test(1, {1,4,3,2,5,2}, 3, {1,2,2,4,3,5});

    // 2) Lista vacía
    run_test(2, {}, 1, {});

    // 3) Un nodo < x
    run_test(3, {1}, 2, {1});

    // 4) Un nodo >= x
    run_test(4, {2}, 2, {2});

    // 5) Duplicados alrededor del pivote
    run_test(5, {3,3,2,2,3}, 3, {2,2,3,3,3});

    // 6) Alternando valores
    run_test(6, {5,1,6,2,7,3}, 4, {1,2,3,5,6,7});

    // 7) Mezcla con negativos y 0 como pivote
    run_test(7, {0,-1,2}, 0, {-1,0,2});

    // 8) Cambio de cabeza
    run_test(8, {4,1}, 3, {1,4});

    // 9) Descendente largo
    run_test(9, {9,8,7,6,5,4,3,2,1,0}, 5, {4,3,2,1,0,9,8,7,6,5});

    // 10) Extremos de int
    run_test(10, {100000000, -100000, 0}, 1, {-100000,0,100000000});

    cout << "Todos los tests pasaron. \n";
    return 0;
}
