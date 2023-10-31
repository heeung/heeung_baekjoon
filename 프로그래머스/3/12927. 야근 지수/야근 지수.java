import java.util.*;
import java.io.*;

class Solution {
    public long solution(int n, int[] works) {
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
        for (int cur : works) { // 다 넣고보기
            q.offer(cur);
        }

        for (int i = 0; i < n; i++) {
            int cur = q.poll();
            cur--;
            q.offer(cur);
        }

        long result = 0;
        for (int cur : q) {
            if (cur > 0) {
                result += (long) cur * cur;
            }
        }

        return result;
    }
}