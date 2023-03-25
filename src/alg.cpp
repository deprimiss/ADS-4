// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1;j < len;j++) {
            if (*(arr + i) + *(arr + j) == value) count++;
            }
        }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    while (*(arr + (len - 1)) > value) len--;
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (*(arr + i) + *(arr + j) == value) count++;
        }
    }
    return count;
}
int cbinsearch(int* arr, int size, int value, int n) {
    int l = n;
    int r = size;
    int count = 0;
    while (l < r - 1) {
        int sr = (l + r) / 2;
        if (*(arr + n) * (arr + sr) == value) {
            count++;
            for (int i = 1; *(arr + sr) == *(arr + (sr - i)); i++)
                count++;
            for (int i = 0; *(arr + sr) == *(arr + (sr + i)); i++)
                count++;
        }
        if (*(arr + n) + *(arr + sr) > value) {
            r = sr;
        }
        else {
            l = sr;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        count += cbinsearch(arr, len, value, i);
    }
    return count;
}
