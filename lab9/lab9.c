#include <stdio.h>

const int I0 = 13;
const int J0 = 19;
const int L0 = 14;

int abs(int num) {
    if (num < 0) {
        return -1 * num;
    }
    return num;
}

int min(int num1, int num2){
    if (num1 > num2) {
        return num2;
    }
    return num1;
}

int max(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    }
    return num2;
    
}
    
int sign(int x) {
    return (x > 0) - (x < 0);
}



char checkPlace(int i, int j) {
    if (i + j + 20 <= 0 && i + j + 10 >= 0) {
        return 1;
    }
    return 0;
}

int main() {

    int iOld = I0;
    int jOld = J0;
    int lOld = L0;

    int iNew, jNew, lNew;

    if (checkPlace(I0, J0) == 1) {
        printf("Point in the place; i = %d, j = %d, l = %d, k = 1\n", I0, J0, L0);
        return 0;
    }

    for (int k = 0; k < 50; k++) {
        iNew = sign(jOld + 1) * abs(abs(k - jOld) - abs(iOld - lOld));
        jNew = jOld % 20 + max(iOld % 20, min(jOld - k, lOld - k)) - 10;
        lNew = (iOld + 1) * (jOld + 2) * (lOld + 1) % 20;

        printf("i = %d, j = %d\n", iNew, jNew);

        if (checkPlace(iNew, jNew) == 1) {
            printf("Point in the place; i = %d, j = %d, l = %d, k = %d\n", iNew, jNew, lNew, k + 1);
            return 0;
        }

        iOld = iNew;
        jOld = jNew;
        lOld = lNew;
    }

    printf("Point not in the place; i = %d, j = %d, l = %d\n", iNew, jNew, lNew);
    return 0;


}
    
