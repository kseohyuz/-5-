#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> inOrder, postOrder;
unordered_map<int, int> indexMap; // 인오더에서 각 값의 인덱스를 저장하는 맵
int n;

void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    // 포스트오더의 마지막 값이 루트
    int root = postOrder[postEnd];
    cout << root << " ";

    // 인오더에서 루트의 위치 찾기
    int rootIndex = indexMap[root];
    int leftSize = rootIndex - inStart;

    // 왼쪽 서브트리
    preOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    // 오른쪽 서브트리
    preOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
   

    // 입력 받기
    int n; 
    cin >> n;
    inOrder.resize(n);
    postOrder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
        indexMap[inOrder[i]] = i;  // 인오더에서의 위치를 맵에 저장
    }

    for (int i = 0; i < n; i++) {
        cin >> postOrder[i];
    }

    // 프리오더 출력
    preOrder(0, n - 1, 0, n - 1);

    return 0;
}
