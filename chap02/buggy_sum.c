#include <stdio.h>

float sum(float a[], unsigned length) {
    int i;
    float result = 0;
    //当length=0时，由于length为unsigned, 
    //隐式类型转换会将 length - 1 结果会转换为unsigned,
    //-1对应为int的最大值, 那么很明显导致内存访问出错
    for (i = 0; i < length - 1; i++) {
        printf("array[%d]=%f\n", i, a[i]);
        result += a[i];
    }

    return result;
}

int main() {
    float a[] = {1,2,3};
    float b = 1;
    //正常调用
    //sum(a, 3);
    printf(">>sum start, sizeof(float)=%d\n", sizeof(b));
    //有bug的调用
    sum(a, 0);
    return 0;
}
