//
// Created by SUN on 2018-12-10.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 123456789;

struct Node {
    int x;
    int y;
    int left;
    int right;
    int label;

    Node *leftchild = NULL;
    Node *rightchild = NULL;

    Node(int x, int y, int left, int right, int label) : x(x), y(y), left(left), right(right), label(label) {};
};

void makeTree(Node *root, const vector<int> &node) {

    int x = node[0];
    int y = node[1];
    int label = node[2];
    //leftCihld로 가는 경우
    if (root->left < x && x < root->x) {
        if (root->leftchild == NULL) {
            root->leftchild = new Node(x, y, root->left, root->x, label);
        } else {
            makeTree(root->leftchild, node);
        }
    }
    //rightChild로 가는 경우
    if (root->x < x && x < root->right) {
        if (root->rightchild == NULL) {
            root->rightchild = new Node(x, y, root->x, root->right, label);
        } else {
            makeTree(root->rightchild, node);
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
    int n = nodeinfo.size();
    for (int i = 0; i < n; i++) {
        nodeinfo[i].push_back(i + 1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), [](const vector<int> &u, const vector<int> &v) {
        if (u[1] > v[1]) {
            return true;
        } else {
            return false;
        }
    });

    int rootX = nodeinfo[0][0];
    int rootY = nodeinfo[0][1];
    int rootLabel = nodeinfo[0][2];
    Node *root = new Node(rootX, rootY, -INF, INF, rootLabel);

    for (int i = 1; i < n; i++) {
        makeTree(root, nodeinfo[i]);
    }

    vector<int> v;
    preOrder(root, v);
    answer.push_back(v);
    v.clear();
    postOrder(root, v);
    answer.push_back(v);


    return answer;
}

int main() {
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

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}