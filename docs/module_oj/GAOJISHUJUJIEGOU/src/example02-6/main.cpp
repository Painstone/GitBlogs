#include <bits/stdc++.h>

using namespace std;

// ��������
const int maxstars = 100000;
// ��������
int st1_x[maxstars], st1_y[maxstars];
int st2_x[maxstars], st2_y[maxstars];
// ��¼ÿ���ǵĸ���
int st[maxstars + 1];
// ���������
int c[maxstars + 1];
// ��������
int n;

// �ж� n1��n2 �Ƿ�Ϊ x-y ����
bool smaller(int n1_x, int n1_y, int n2_x, int n2_y) {
    if(n1_x < n2_x | (n1_x == n2_x && n1_y < n2_y))
        return true;
    else
        return false;
}

// ����������̣�x-y ����
void qsort(int l, int r) {
    int i, j;
    int x_x, x_y;
    int temp_x, temp_y;
    int mid = (l + r) / 2;
    i = l;
    j = r;
    x_x = st2_x[mid];
    x_y = st2_y[mid];
    while(i <= j) {
        while(smaller(st2_x[i], st2_y[i], x_x, x_y) == true)
            i++;
        while(smaller(x_x, x_y, st2_x[j], st2_y[j]) == true)
            j--;
        if(i <= j) {
            temp_x = st2_x[i];
            temp_y = st2_y[i];
            st2_x[i] = st2_x[j];
            st2_y[i] = st2_y[j];
            st2_x[j] = temp_x;
            st2_y[j] = temp_y;
            i++;
            j--;
        }
    }
    if(l < j)
        qsort(l, j);
    if(i < r)
        qsort(i, r);
}

void initialize() {
    int i;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> st1_x[i] >> st1_y[i];
        st2_x[i] = st1_x[i];
        st2_y[i] = st1_y[i];
    }
    qsort(1, n);
}

// ͳ�ƹ���
void solve() {
    int i, l, r, m, ld, temp;
    temp = n;
    for(i = 0; i < maxstars; i++) {
        st[i + 1] = 0;
        c[i + 1] = 0;
    }
    n = temp;
    for(i = 1; i <= n; i++) {
        l = 1;
        r = n;
        ld = 0;
        // ���ֲ���
        while(l < r) {
            m = (l + r) / 2;
            if(smaller(st2_x[m], st2_y[m], st1_x[i], st1_y[i])) {
                ld = ld + c[m + 1];
                l = m + 1;
            } else {
                c[m + 1]++;
                r = m;
            }
        }
        st[ld + 1]++;
    }
    for(i = 0; i < n; i++) {
        cout << st[i + 1] << endl;
    }
}

int main() {
    initialize();
    solve();
    return 0;
}
