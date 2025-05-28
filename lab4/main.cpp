//Itsko Andri K-16
//var 6

#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    bool is_end;
    TreeNode* left;
    TreeNode* right;
    string pref;

    TreeNode(): is_end(false), left(nullptr), right(nullptr), pref("") {}
};
void delete_TreeNode(TreeNode* root)
{
    if(!root){
        return;
    }
    delete_TreeNode(root->left);
    delete_TreeNode(root->right);
    delete root;
}
TreeNode* insert(TreeNode* root, const string& code)
{
    TreeNode* curr = root;
    string curr_pref;
    for(char i: code){
        curr_pref += i;
        if(curr->is_end){
            return curr;
        }
        if(i == '0'){
            if(!curr->left){
                curr->left = new TreeNode();
                curr->left->pref = curr_pref;
            }
            curr = curr->left;
        }
        else{
            if(!curr->right){
                curr->right = new TreeNode();
                curr->right->pref = curr_pref;
            }
            curr = curr->right;
        }
    }
    if(curr->is_end || curr->left || curr->right){
        return curr;
    }
    curr->is_end = true;
    return nullptr;
}
bool is_valid(const string& code){
    for(char i: code){
        if(i != '0' && i != '1'){
            return false;
        }
    }
    return true;
}
TreeNode* find_longest(TreeNode* node){
    while(node){
        if(node->is_end){
            return node;
        }
        if(node->left){
            node = node->left;
        }
        else{
            node = node->right;                 
        }
    }
    return nullptr;
}
void input_data_processing()
{
    TreeNode* root = new TreeNode();
    string x;
    int count = 0;
    string short_code, long_code;
    while(cin >> x){
        if(!is_valid(x)){
            break;
        }
        TreeNode* current_code = insert(root, x);
        if(current_code){
            if(current_code->is_end){
                short_code = current_code->pref;
                long_code = x;
            }
            else{
                short_code = x;

                TreeNode* found = find_longest(current_code);
                if(found){
                    long_code = found->pref;
                }
            }
            break;
        }
        count++;
    }
    cout << "\n*****" << endl;
    cout << count << endl;
    if(!long_code.empty()){
        cout << short_code << " " << long_code << endl;
    }
    else{
        cout << "2" << endl;
    }
    delete_TreeNode(root);
}

int main(){
    input_data_processing();
    return 0;
}