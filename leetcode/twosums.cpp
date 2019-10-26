#include <vector>
#include <string>
#include <map>

using namespace std;

class TwoSum {
public:
    vector<int> brute_force(vector<int>& nums, int target) {
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i){
            for(int j = 0;j < nums.size()-1; ++j){
                if(nums[i]+nums[j] and i != j){
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        v.push_back(-1);
        return v;
    }

};

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class AddTwoNums {
public:
    ListNode* firstSolution(ListNode* l1, ListNode* l2) {
        ListNode* current1 = l1;
        ListNode* current2 = l2;
        ListNode* num = new ListNode(0);
        ListNode* result = num;
        bool carry = false;
        int digit;
        while(current1 || current2){

            if (carry) num->val = 1; /// make this better by setting digit = sum/10 where sum = current1 + current 2 = carry
            digit = current1->val + current2->val;
            if (digit <= 9){
                num->val += current1->val + current2->val;
                carry = 0;
            } else {
                num->val = 0;
                carry = 1;
            }

            current1 = current1 -> next;
            current2 = current2 -> next;
            if (current1){
                num->next = new ListNode(0);
            }
            num = num->next;
        }
        return result;
    }
};

class LongestSubString {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> letters;
        int result = 0;

        for (int i=0; i < s.length();++i){
            if(letters.count(s[i]) == 0){
                letters.insert(pair<char, int>(s[i], 1));
                result++;
            }else{
                break;
            }
        }
        return result;
    }
};