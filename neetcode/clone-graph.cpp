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

//BFS IMPLEMENTATION BELOW
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> visited;
        Node* clone = new Node(node->val);
        visited[node] = clone;
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* first = q.front();
            Node* second = visited[first];
            q.pop();
            for(auto x: first->neighbors){
                if(visited.find(x) == visited.end()){
                    Node* child = new Node(x->val);
                    visited[x] = child;
                    second->neighbors.push_back(child);
                    q.push(x);
                }
                else{
                    second->neighbors.push_back(visited[x]);
                }
            }
        }

        return clone;
    }
};


//DFS IMPLEMENTATION BELOW
class Solution {
public:
    Node* make_clone(Node* node,unordered_map<Node*,Node*>& visited){
        Node* copy = new Node(node->val);
        visited[node] = copy;
        for(auto x: node->neighbors){
            if(visited.find(x) == visited.end()){
                Node* child = make_clone(x,visited);
                copy->neighbors.push_back(child);
            }
            else{
                copy->neighbors.push_back(visited[x]);
            }
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> visited;
        Node* clone = make_clone(node,visited);
        return clone;
    }
};