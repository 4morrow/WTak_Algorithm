#include <cstdio>
int main() {
    int N, d[10005] = { 0, },num;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &num);
        d[num]++;
    }
    for (int i = 1; i <= 10000; i++) {
        while (d[i]--) {
            printf("%d\n", i);
        }
    }
    return 0;
}
