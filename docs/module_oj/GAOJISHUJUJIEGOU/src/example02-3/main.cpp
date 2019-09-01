#include <bits/stdc++.h>

using namespace std;

const long maxn = 1000;
long link[maxn];
long data[maxn];
long full[2 * maxn];
long ftop, length, i, j;

// ���ݸ�������������Ĳ��ֽ�����˳����������������
void build() {
    long _stack[maxn];
    long stop = 0;
    for(i = 2; i <= length; i++) {
        // ��������������������������ĸ��������ջ
        if((full[ftop] - data[i]) > 0) {
            stop++;
            _stack[stop] = full[ftop] - data[i];
        }
        ftop++;
        full[ftop] = data[i];
        link[i] = ftop;
        // �����ǰ�����Ҷ�ӽ�㣬�����������ĸ�����ջ��
        while(full[ftop] == 1) {
            ftop++;
            full[ftop] = _stack[stop];
            stop--;
        }
    }
}

// ��Ⲣ���
void solve() {
    i = length;
    while((full[link[i] - 1] - full[link[i]]) < 2 && (i > 1)) {
        i--;
    }
    if(i == 1) {
        cout << 0;
    } else {
        for(j = 1; j <= i - 1; j++) {
            // ���ҵ��Ľ���ֵ��1�����Ľ���ֵ����Ϊ1
            cout << data[j] << " ";
        }
        cout << data[i] + 1;
        for(j = i + 1; j <= length; j++) {
            cout << " 1";
        }
    }
}

int main() {
    cin >> length;
    for(i = 1; i <= length; i++) {
        cin >> data[i];
    }
    /*
    printf("%d\n", length);
    for(int i = 1; i <= length; i++) {
        printf("%d\n", data[i]);
    }
    */
    full[1] = data[1];
    link[1] = 1;
    ftop = 1;
    build();
    solve();
    return 0;
}
