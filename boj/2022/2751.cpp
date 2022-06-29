//
// Created by Kim So Hee on 2022/06/29.
//
#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

void merge(int start, int mid, int end) {
    /*
     * @description
     *   leftPoint : merge 대상 왼쪽 배열
     *   rightPoint : merge 대상 오른쪽 배열
     *   mergePoint : 임시 배열에 삽입할 인덱스
     * */
    int leftPoint = start;
    int rightPoint = mid + 1;
    int mergePoint = 0;

    // 임시 배열 생성
    int *temp = new int[end - start + 1];

    // merge 대상 배열의 앞부분 비교
    while (leftPoint <= mid && rightPoint <= end) {
        if (arr[leftPoint] < arr[rightPoint]) temp[mergePoint++] = arr[leftPoint++];
        else temp[mergePoint++] = arr[rightPoint++];
    }

    // 남은 배열 삽입
    while (leftPoint <= mid) temp[mergePoint++] = arr[leftPoint++];
    while (rightPoint <= end) temp[mergePoint++] = arr[rightPoint++];

    for (int i = 0; i <= end - start; ++i) {
        arr[start + i] = temp[i];
    }
    delete[] temp;
}

void mergeSort(int start, int end) {
    if (start > end) return;
    else if (start <= end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    mergeSort(0, N - 1);
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << '\n';
    }
}