//
// Created by SUN on 2018-12-08.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct Node {
    int x;
    int y;
    int left;
    int right;
    int label;

    Node *leftchild = NULL;
    Node *rightchild = NULL;

    Node(int x, int y, int left, int right, int label) : x(x), y(y), left(left), right(right), label(label) {}
};

bool cmp(const vector<int> &u, const vector<int> &v) {
    if (u[1] > v[1]) {
        return true;
    } else {
        return false;
    }
}

void makeTree(Node *root, const vector<int> &nodeinfo) {
    int x = nodeinfo[0];
    int y = nodeinfo[1];
    int label = nodeinfo[2];

    if (root->left < x && x < root->x) {
        if (root->leftchild) {
            makeTree(root->leftchild, nodeinfo);
        } else {
            root->leftchild = new Node(x, y, root->left, root->x, label);
        }
    }
    if (root->x < x && x < root->right) {
        if (root->rightchild) {
            makeTree(root->rightchild, nodeinfo);
        } else {
            root->rightchild = new Node(x, y, root->x, root->right, label);
        }
    }

}

void preOrder(Node *root, vector<int> &v) {

    if (root == NULL) {
        return;
    }

    v.push_back(root->label);
    preOrder(root->leftchild, v);
    preOrder(root->rightchild, v);


}

void postOrder(Node *root, vector<int> &v) {

    if (root == NULL) {
        return;
    }

    postOrder(root->leftchild, v);
    postOrder(root->rightchild, v);
    v.push_back(root->label);

}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i + 1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), cmp);

    vector<int> first = nodeinfo[0];


    Node root(first[0], first[1], -INF, INF, first[2]);


    for (int i = 1; i < nodeinfo.size(); i++) {
        makeTree(&root, nodeinfo[i]);
    }

    vector<int> v1;
    vector<int> v2;
    preOrder(&root, v1);
    answer.push_back(v1);
    postOrder(&root, v2);
    answer.push_back(v2);

    return answer;
}

int main() {

    // example
    vector<vector<int>> nodeinfo;
    nodeinfo.push_back({5, 3});
    nodeinfo.push_back({11, 5});
    nodeinfo.push_back({13, 3});
    nodeinfo.push_back({3, 5});
    nodeinfo.push_back({6, 1});
    nodeinfo.push_back({1, 3});
    nodeinfo.push_back({8, 6});
    nodeinfo.push_back({7, 2});
    nodeinfo.push_back({2, 2});

    vector<vector<int>> ans = solution(nodeinfo);

    //print
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}