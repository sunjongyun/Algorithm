//
// Created by SUN on 2018-12-20.
//

#include <iostream>

using namespace std;

struct tree {
    char val;

    tree *child1 = NULL;
    tree *child2 = NULL;
    tree *child3 = NULL;
    tree *child4 = NULL;
};

void makeTree(tree *root, const string &input, int *index) {
    char now = input[*index];
    (*index)++;
    if (now == 'x') {
        root->val = 'x';
        root->child1 = new tree;
        root->child2 = new tree;
        root->child3 = new tree;
        root->child4 = new tree;
        makeTree(root->child1, input, index);
        makeTree(root->child2, input, index);
        makeTree(root->child3, input, index);
        makeTree(root->child4, input, index);
    } else if (now == 'w') {
        root->val = 'w';
    } else if (now == 'b') {
        root->val = 'b';
    }
}

void makeAns(tree *root, string *ans) {

    (*ans) += (root->val);
    if (root->child3 != NULL) makeAns(root->child3, ans);
    if (root->child4 != NULL) makeAns(root->child4, ans);
    if (root->child1 != NULL) makeAns(root->child1, ans);
    if (root->child2 != NULL) makeAns(root->child2, ans);

}

string solution(string input) {
    string answer = "";

    int index = 0;
    tree *root = new tree;
    makeTree(root, input, &index);

    makeAns(root, &answer);


    return answer;
}


int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        string input;
        cin >> input;

        string ans = solution(input);
        cout << ans << '\n';
    }

    return 0;
}