#include <bits/stdc++.h>

using namespace std;

char s1[10000], s2[10000];

int posi(char ch) {
    for(int i = 0; i < strlen(s2); i++) {
        if(ch == s2[i])
            return i;
    }
}

// �ݹ��������������
void tryit(int l1, int r1, int l2, int r2) {
    // �� s1 �����ַ��� s2 �е�λ��
    int m = posi(s1[l1]);
    // ������ m ��������
    if(m > l2) {
        tryit(l1 + 1, l1 + m - l2, l2, m - 1);
    }
    // ������ m �����Ұ��
    if(m < r2) {
        tryit(l1 + m - l2 + 1, r1, m + 1, r2);
    }
    printf("%c", s1[l1]);
}

int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    tryit(0, strlen(s1) - 1, 0, strlen(s2) - 1);
    return 0;
}
