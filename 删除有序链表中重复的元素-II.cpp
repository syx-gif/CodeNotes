/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if (head == nullptr) return nullptr;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slow = dummy;   // 指向「已确认无重复」的最后一个节点（守门员）
    ListNode* fast = head;    // 当前扫描位置（侦察兵）

    while (fast != nullptr && fast->next != nullptr) {
        if (fast->val == fast->next->val) {
            int dup = fast->val;
            // 整段跳过所有值等于 dup 的节点
            while (fast != nullptr && fast->val == dup) {
                fast = fast->next;
            }
            slow->next = fast;   // slow 接到跳过重复后的位置（slow 不动）
        } else {
            slow = fast;         // fast 安全，slow 跟上
            fast = fast->next;
        }
    }

    return dummy->next;
        
    }
};