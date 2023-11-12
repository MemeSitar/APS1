#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <assert.h>
using namespace std;

class AVLNode {
public:
    int value;
    AVLNode *left, *right;
    int height;
    AVLNode(int v) : value(v), left(NULL), right(NULL), height(1) {}
};

class AVLTree {
public: 
    AVLNode* root = NULL;

    bool contains(int x) {
        return contains(x, root);
    }
    bool contains(int x, AVLNode* node) {
        if(node == NULL) return false;
        if (node->value == x) return true;
        else if (x < node->value) return contains(x, node->left);
        else return contains(x, node->right);
    }
    void insert(int x){
        root = insert(x, root);
    }
    AVLNode* insert(int x, AVLNode* node){
        if (node == NULL) return new AVLNode(x);
        if (x <= node->value) {
            node->left = insert(x, node->left);
        } else {
            node->right = insert(x, node->right);
        }
        return node;
    }
    AVLNode* rotateLeft(AVLNode* node){
        AVLNode *R = node->right;
        node->right = R->left;
        R->left = node;
        update(node); update(R);
        return R;
    }
    AVLNode* rotateRight(AVLNode* node){
        AVLNode *L = node->left;
        node->left = L->right;
        L->right = node;
        update(node); update(L);
        return L;
    }
};

int main() {
    default_random_engine rnd(1234);
    AVLTree avl;
    int n=100000;
    for (int i=0; i<n; i++){
        avl.insert(i);
        assert(avl.contains(i) && !avl.contains(i+1));
    }
    return 0;
}