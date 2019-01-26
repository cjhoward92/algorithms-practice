#include <limits.h>
#include <stdio.h>
#include <stddef.h>

typedef struct {
  int max_left;
  int max_right;
  int sum;
} subarray_t;

subarray_t find_max_crossing(int arr[], int low, int mid, int high) {
  subarray_t sub = { 0, 0, 0 };
  
  int left_sum = -100000;
  int sum = 0;

  int i;
  for (i = mid; i >= low; i--) {
    sum += arr[i];
    if (sum > left_sum) {
      left_sum = sum;
      sub.max_left = i;
    }
  }

  int right_sum = -100000;
  sum = 0;

  for (i = mid + 1; i <= high; i++) {
    sum += arr[i];
    if (sum > right_sum) {
      right_sum = sum;
      sub.max_right = i;
    }
  }

  sub.sum = left_sum + right_sum;

  return sub;
}

subarray_t find_max_subarray(int arr[], int low, int high) {
  subarray_t sub = { low, high, arr[low] };

  if (high == low)
    return sub;
  
  int mid = (low + high) / 2;
  subarray_t sub_low = find_max_subarray(arr, low, mid);
  subarray_t sub_high = find_max_subarray(arr, mid + 1, high);
  subarray_t cross = find_max_crossing(arr, low, mid, high);

  if (sub_low.sum >= sub_high.sum && sub_low.sum >= cross.sum)
    return sub_low;
  else if (sub_high.sum >= sub_low.sum && sub_high.sum >= cross.sum)
    return sub_high;
  else
    return cross;
}

int main() {
  int arr[10];
  arr[0] = -10;
  arr[1] = -10;
  arr[2] = -2;
  arr[3] = 0;
  arr[4] = 5;
  arr[5] = 30;
  arr[6] = -9;
  arr[7] = 3;
  arr[8] = -8;
  arr[9] = 1;

  subarray_t sub = find_max_subarray(arr, 0, 9);

  printf("left: %d; right: %d; sum: %d\n", sub.max_left, sub.max_right, sub.sum);

  return 0;
}
