#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> inOrder, postOrder;
unordered_map<int, int> indexMap; // �ο������� �� ���� �ε����� �����ϴ� ��
int n;

void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    // ����Ʈ������ ������ ���� ��Ʈ
    int root = postOrder[postEnd];
    cout << root << " ";

    // �ο������� ��Ʈ�� ��ġ ã��
    int rootIndex = indexMap[root];
    int leftSize = rootIndex - inStart;

    // ���� ����Ʈ��
    preOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    // ������ ����Ʈ��
    preOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
   

    // �Է� �ޱ�
    int n; 
    cin >> n;
    inOrder.resize(n);
    postOrder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
        indexMap[inOrder[i]] = i;  // �ο��������� ��ġ�� �ʿ� ����
    }

    for (int i = 0; i < n; i++) {
        cin >> postOrder[i];
    }

    // �������� ���
    preOrder(0, n - 1, 0, n - 1);

    return 0;
}
