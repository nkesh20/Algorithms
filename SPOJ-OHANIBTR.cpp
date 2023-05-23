#include <bits/stdc++.h>

using namespace std;


int arr[1000000];

struct Node {
    int val;
    Node *left;
    Node *right;
};

Node *fillTree(Node *root, int &index) {
    if (root == NULL) {
        return NULL;
    }

    fillTree(root->left, index);
    root->val = arr[index];
    index++;
    fillTree(root->right, index);

    return root;
}

int lis(int numElems) {
    if (numElems == 0) {
        return 0;
    }

    std::vector<int> tailVec(numElems, 0);
    int len = 1;

    tailVec[0] = arr[0];

    for (int j = 1; j < numElems; j++) {

        auto bb = tailVec.begin(), e = tailVec.begin() + len;
        auto iter = lower_bound(bb, e, arr[j]);

        if (iter == tailVec.begin() + len)
            tailVec[len++] = arr[j];
        else
            *iter = arr[j];
    }

    return len;
}

Node *buildTree(int index, int numElems) {
    Node *root = NULL;
    if (index < numElems) {
        root = new Node;
        root->val = 0;
        root->left = buildTree(2 * index + 1, numElems);
        root->right = buildTree(2 * (index + 1), numElems);
    }

    return root;
}


void printTree(Node *root, int parent, int lastElem) {
    if (root == NULL) {
        return;
    }
    printTree(root->left, root->val, lastElem);
    if (root->val == lastElem) {
        cout << parent;
    } else {
        cout << parent << " ";
    }
    printTree(root->right, root->val, lastElem);


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTests, numElems, i, j, index;
    cin >> numTests;
    for (i = 1; i <= numTests; i++) {
        cin >> numElems;
        for (j = 0; j < numElems; j++) {
            cin >> arr[j];
        }
        cout << "Case " << i << ":" << endl;
        cout << "Minimum Move: " << numElems - lis(numElems) << endl;
        sort(arr, arr + numElems);
        Node *root = buildTree(0, numElems);
        index = 0;
        root = fillTree(root, index);
        printTree(root, -1, arr[numElems - 1]);
        cout << endl;
    }

    return 0;
}