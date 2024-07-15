#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }
    TreeNode* deserialize(const string& data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (node) {
            out << node->val << ' ';
            serializeHelper(node->left, out);
            serializeHelper(node->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(stoi(val));
            node->left = deserializeHelper(in);
            node->right = deserializeHelper(in);
            return node;
        }
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "# ";
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serializedData = codec.serialize(root);
    cout << "Serialized tree: " << serializedData << endl;

    TreeNode* deserializedTree = codec.deserialize(serializedData);
    cout << "Deserialized tree (level-order): ";
    printTree(deserializedTree);

    return 0;
}