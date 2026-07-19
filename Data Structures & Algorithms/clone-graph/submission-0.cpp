/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node * dfsCloning(Node * node, map<Node*, Node*>mpp_old_node_to_new){
        if(node == nullptr) return nullptr;
        if(mpp_old_node_to_new.find(node) != mpp_old_node_to_new.end()){
            return mpp_old_node_to_new[node];
        }

        Node * copy = new Node(node->val);
        mpp_old_node_to_new[node] = copy;

        for(Node * nbr : node->neighbors){
            copy->neighbors.push_back(dfsCloning(nbr, mpp_old_node_to_new));
        }

        return copy; 
    }

public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>mpp_old_node_to_new;
        return dfsCloning(node, mpp_old_node_to_new);
    }
};
