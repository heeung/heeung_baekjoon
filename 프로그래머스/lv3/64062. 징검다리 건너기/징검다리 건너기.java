import java.io.*;
import java.util.*;

class Solution {
    static class Number implements Comparable<Number> {
        int num, idx;
        public Number(int num, int idx) {
            this.num = num;
            this.idx = idx;
        }
        @Override
        public int compareTo(Number o) {
            return o.num - this.num;
        }
    }
    public int solution(int[] stones, int k) {
        PriorityQueue<Number> pq = new PriorityQueue<>();
        ArrayList<Integer> arr = new ArrayList<>();
        
        for (int i = 0; i < stones.length; i++) {
            pq.add(new Number(stones[i], i));
            
            if (i - k + 1 < 0) continue ;
            
            while (pq.peek().idx <= i - k) {
                pq.poll();
            }
            arr.add(pq.peek().num);
        }
        
        int[] answer = new int[arr.size()];
        
        int index = 0;
        int min = Integer.MAX_VALUE;
        for (int num : arr) {
            // answer[index++] = num;
            min = Math.min(min, num);
        }
        
        return min;
    }
}