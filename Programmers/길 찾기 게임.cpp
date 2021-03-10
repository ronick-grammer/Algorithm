#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/42892

class TreeNode{
public:
    int x; 
    int y; 
    int number; // 본인 번호
    TreeNode* left; // 왼쪽 자식
    TreeNode* right; // 오른쪽 자식

    TreeNode(int x, int y, int number){
        this->x = x;
        this->y = y;
        this->number = number;
        this->left = NULL; 
        this->right = NULL;
    }
};

bool compare(TreeNode* a, TreeNode* b){
    return a->y > b->y; // 내림 차순으로 정렬(y값이 가장 높은게 루트가 되도록)
}

void addNode(TreeNode* node, TreeNode* newNode){
    if(node->x > newNode->x){ // 부모의 x좌표가 자식의 x좌표보다 크다면
        if(node->left == NULL){ // 부모의 왼쪽 자식이 없을 경우 
            node->left = newNode; // 부모의 왼쪽 자식으로 만든다
        }
        else{ // 이미 있다면 그 왼쪽 자식의 자식을 확인한다
            addNode(node->left, newNode);
        }
    }
    else if(node->x < newNode->x){ // 부모의 x좌표가 자식의 x좌표보다 작다면 
        if(node->right == NULL){ // 부모의 오른쪽 자식이 없을 경우
            node->right = newNode; // 부모의 오른쪽 자식으로 만든다
        }
        else{ // 이미 있다면 그 오른쪽 자식의 자식을 확인한다.
            addNode(node->right, newNode);
        }
    }
}

void preOrder(TreeNode* node, vector<int>& pre){
    if(node != NULL){
        pre.push_back(node->number);
        preOrder(node->left, pre);
        preOrder(node->right, pre);
    }
}

void postOrder(TreeNode* node, vector<int>& post){
    if(node != NULL){
        postOrder(node->left, post);
        postOrder(node->right, post);
        post.push_back(node->number);
    }
}

vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    vector<vector<int> > answer(2); // 전위순회와 후위순회
    vector<TreeNode*> treeNodes;

    for(int i = 0; i < nodeinfo.size(); i++){
        treeNodes.push_back(new TreeNode(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    }

    sort(treeNodes.begin(), treeNodes.end(), compare); // y값 기준으로 내림차순 정렬하여 레벨을 나눈다

    for(int i = 1; i < treeNodes.size(); i++){
        addNode(treeNodes[0], treeNodes[i]); // 루트 노드부터 내려가면서 차레차례 자식노드들을 추가해준다
    }

    preOrder(treeNodes[0], answer[0]); // 전위순회
    postOrder(treeNodes[0], answer[1]); // 후외순회

    return answer;
}
