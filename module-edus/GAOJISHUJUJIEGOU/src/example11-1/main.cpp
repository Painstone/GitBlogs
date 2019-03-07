#include <bits/stdc++.h>

using namespace std;

// ==> DC3 �㷨
#define getRealPos() (SA12[pos12] < n0 ? SA12[pos12] * 3 + 1 : (SA12[pos12] - n0) * 3 + 2)
// ��Ԫ������ıȽϺ���
inline bool cmp(int a1, int a2, int b1, int b2) {
    return (a1 < b1 || (a1 == b1 && a2 <= b2));
}
// ��Ԫ������ıȽϺ���
inline bool cmp(int a1, int a2, int a3, int b1, int b2, int b3) {
    return (a1 < b1 || (a1 == b1 && cmp(a2, a3, b2, b3)));
}
// �������򣨶��ض�λ�ģ�
// oldIdx��ԭ��׺����ָ��
// newIdx������������ָ��
// origin����Ӧ�ַ�����ָ��
// n���������
// upperBound�����ַ�����ɢ��֮��ķ�Χ
void radixSort(int *oldIdx, int *newIdx, int *origin, int n, int upperBound) {
    // ����Ͱ�������
    int *cnt = new int[upperBound + 1];
    for(int i = 0; i <= upperBound; ++i) {
        cnt[i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        cnt[origin[oldIdx[i]]]++;
    }
    for(int i = 0, sum = 0; i <= upperBound; ++i) {
        int tmp = cnt[i];
        cnt[i] = sum;
        sum += tmp;
    }
    for(int i = 0; i < n; ++i) {
        newIdx[cnt[origin[oldIdx[i]]]++] = oldIdx[i];
    }
    delete []cnt;
}
// �����׺����������
void suffixArray(int *st, int *SA, int n, int upperBound) {
    // ���� 3 �������ֱ�Ϊģ 3 �� 0��1��2 �ĺ�׺λ�ø���
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n12 = n0 + n2;
    // �������ĺ�׺����λ��ģ 3 ����Ϊ 0 ����Щ��׺��
    int *s12 = new int[n12 + 3];
    s12[n12] = s12[n12 + 1] = s12[n12 + 2] = 0;
    // ��������׺�ĺ�׺����
    int *SA12 = new int[n12 + 3];
    SA12[n12] = SA12[n12 + 1] = SA12[n12 + 2] = 0;
    // δ��������׺�����׺���飨��λ��ģ 3 ��Ϊ 0 ����Щ��׺��
    int *s0 = new int [n0];
    int *SA0 = new int[n0];
    // ��ʼ����������׺
    for(int i = 0, j = 0; i < n + (n % 3 == 1); ++i) {
        if(i % 3) {
            s12[j++] = i;
        }
    }
    // �Ա�������׺���յ�һ�����ַ������л�������
    radixSort(s12, SA12, st + 2, n12, upperBound);
    radixSort(SA12, s12, st + 1, n12, upperBound);
    radixSort(s12, SA12, st, n12, upperBound);
    // ����Ϊ�ԡ��ַ���������ɢ���Ĺ���
    int cnt = 0, pre0 = -1, pre1 = -1, pre2 = -1;
    for (int i = 0; i < n12; ++i) {
        if(st[SA12[i]] != pre0 || st[SA12[i] + 1] != pre1 || st[SA12[i] + 2] != pre2) {
            cnt++;
            pre0 = st[SA12[i]];
            pre1 = st[SA12[i] + 1];
            pre2 = st[SA12[i] + 2];
        }
        if(SA12[i] % 3 == 1) {
            s12[SA12[i] / 3] = cnt;
        } else {
            s12[SA12[i] / 3 + n0] = cnt;
        }
    }
    // ���������ͬ�ַ�����ô��Ҫ�ݹ鹹���׺����
    if(cnt < n12) {
        // �ݹ鴦��
        suffixArray(s12, SA12, n12, cnt);
        for(int i = 0; i < n12; ++i) {
            s12[SA12[i]] = i + 1;
        }
    }
    // �����������������ַ�������ͬ������ֱ�ӵõ���׺����
    else {
        for(int i = 0; i < n12; ++i) {
            SA12[s12[i] - 1] = i;
        }
    }
    // ����δ��������׺�ĺ�׺����
    for(int i = 0, j = 0; i < n12; ++i) {
        if(SA12[i] < n0) {
            s0[j++] = 3 * SA12[i];
        }
    }
    radixSort(s0, SA0, st, n0, upperBound);
    // ���¹��̽����ι���ĺ�׺����ϲ�Ϊ���ս��
    for(int pos0 = 0, pos12 = n0 - n1, k = 0; k < n; ++k) {
        int i = getRealPos();
        int j = SA0[pos0];
        // i Ϊ��������׺�����е�ǰ��С��׺��j Ϊδ��������׺�е�ǰ��С��׺
        bool is12First;
        if(SA12[pos12] < n0) {
            is12First = cmp(st[i], s12[SA12[pos12] + n0], st[j], s12[j / 3]);
        } else {
            is12First = cmp(st[i], st[i + 1], s12[SA12[pos12] - n0 + 1], st[j], st[j + 1], s12[j / 3 + n0]);
        }
        // ���������еıȽϹ���������߽��бȽϣ�ȡ��С�����ȼ����׺����
        if(is12First) {
            SA[k] = i;
            pos12++;
            if(pos12 == n12) {
                for(k++; pos0 < n0; pos0++, k++) {
                    SA[k] = SA0[pos0];
                }
            }
        } else {
            SA[k] = j;
            pos0++;
            if(pos0 == n0) {
                for(k++; pos12 < n12; pos12++, k++) {
                    SA[k] = getRealPos();
                }
            }
        }
    }
    // �ͷ��ڴ�
    delete [] s12;
    delete [] SA12;
    delete [] SA0;
    delete [] s0;
}
// <== DC3 �㷨

void getHeight(int *st, int *SA, int *_rank, int *height, int n) {
    int l = 0;
    height[0] = 0;
    for(int i = 0; i < n; ++i) {
        if(_rank[i] > 0) {
            int j = SA[_rank[i] - 1];
            while((i + 1 < n) && (j + 1 < n) && (st[i + l] == st[j + l])) {
                l++;
            }
            height[_rank[i]] = l;
            if(l > 0) {
                l--;
            }
        }
    }
}

const int maxn = 200000;
char s[maxn];
int st[maxn], SA[maxn], _rank[maxn], height[maxn];

bool isDebug = false;
void log(string str){
    if(isDebug){
        cout << str << endl;
    }
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    memset(st, 0, sizeof(st));
    for(int i = 0; i < n; ++i) {
        st[i] = s[i];
    }
    log("==>suffixArray()");
    suffixArray(st, SA, n, 150);
    log("<==suffixArray()");
    for(int i = 0; i < n; ++i) {
        _rank[SA[i]] = i;
    }
    log("==>getHeight()");
    getHeight(st, SA, _rank, height, n);
    log("<==getHeight()");
    long long ans = n;
    ans = ans * (ans + 1) / 2;
    for(int i = 0; i < n; ++i) {
        ans -= height[i];
    }
    cout << ans << endl;
    return 0;
}
