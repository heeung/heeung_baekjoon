import java.io.*;
import java.util.*;

class Solution {
    static ArrayList<Integer>[] graph;
    static int[] arr;
    
    public static void main(String[] args) {
        // System.out.println("a");
    }
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        
        graph = new ArrayList[n + 1];
        
        arr = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            graph[i] = new ArrayList<>();
            arr[i] = Integer.MAX_VALUE;
        }
        
        // arr = new int[n + 1];
        for (int i = 0; i < roads.length; i++) {
            int from = roads[i][0];
            int to = roads[i][1];
            
            graph[from].add(to);
            graph[to].add(from);
        }
        
        bfs(destination);
        
        // System.out.println(Arrays.toString(arr));
        for (int i = 0; i < sources.length; i++) {
            if (arr[sources[i]] == Integer.MAX_VALUE) {
                answer[i] = -1;
            } else if (sources[i] == destination) {
                answer[i] = 0;
            } else {
                answer[i] = arr[sources[i]];
            }
        }
        
        return answer;
    }
    
    static void bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        int cnt = 1;
        
        q.offer(start);
        while (!q.isEmpty()) {
            ArrayList<Integer> list = new ArrayList<>();
            
            while (!q.isEmpty()) {
                list.add(q.poll());
            }
            
            for (int now : list) {
                for (int next : graph[now]) {
                    if (cnt < arr[next]) {
                        arr[next] = cnt;
                        q.offer(next);
                    }
                    // q.offer(next);
                }
            }
            cnt++;
        }
    }
}