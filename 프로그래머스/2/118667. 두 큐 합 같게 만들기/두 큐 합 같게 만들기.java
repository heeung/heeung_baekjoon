import java.io.*;
import java.util.*;

class Solution {
    static int goal;
    static long sum1, sum2;
    
    public int solution(int[] queue1, int[] queue2) {
        int cnt = 0;
        
        // 투포인터
        int[] arr = new int[queue1.length * 2];
        for (int i = 0; i < queue1.length; i++) {
            arr[i] = queue1[i];
            arr[i + queue1.length] = queue2[i];
            sum1 += (long) queue1[i];
            sum2 += (long) queue2[i];
        }
        
        long goal = sum1 + sum2 / 2;
        
        int left = 0;
        int right = queue1.length - 1;
        
        while (left < arr.length && right < arr.length && left <= right) {
            if (sum1 == sum2) {
                return cnt;
            }
            if (sum1 < sum2 && right < arr.length - 1) {
                right++;
                sum1 += arr[right];
                sum2 -= arr[right];
            }
            else {
                sum1 -= arr[left];
                sum2 += arr[left];
                left++;
            }
            cnt++;
        }
        
        return -1;
    }
}


// class Solution {
//     static int goal, cnt;
//     static long sum1, sum2;
//     static Queue<Integer> q1, q2;
    
//     public int solution(int[] queue1, int[] queue2) {
//         // int answer = -2;
        
//         q1 = new LinkedList<>();
//         q2 = new LinkedList<>();
//         // 총 합 구하기
//         for (int i = 0; i < queue1.length; i++) {
//             goal += queue1[i];
//             goal += queue2[i];
//             sum1 += (long) queue1[i];
//             sum2 += (long) queue2[i];
//             q1.offer(queue1[i]);
//             q2.offer(queue2[i]);
//         }
//         if (goal % 2 == 1) {
//             return -1;
//         }
//         goal = goal / 2;
        
//         while (sum1 != sum2) {
//             if (sum1 > sum2) {
//                 int tmp = q1.poll();
//                 q2.offer(tmp);
//                 sum1 = sum1 - tmp;
//                 sum2 = sum2 + tmp;
//                 cnt++;
//             }
//             else if (sum1 < sum2) {
//                 int tmp = q2.poll();
//                 q1.offer(tmp);
//                 sum1 = sum1 + tmp;
//                 sum2 = sum2 - tmp;
//                 cnt++;
//             }
//             if (sum1 == 0 || sum2 == 0) {
//                 return -1;
//             }
//         }
        
//         return cnt;
//     }
// }