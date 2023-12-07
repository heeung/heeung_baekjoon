import java.io.*;
import java.util.*;

public class Main {
    static class Time implements Comparable<Time> {
        int start, end;
        public Time(int start, int end) {
            this.start = start;
            this.end = end;
        }
        @Override
        public String toString() {
            return "Time{" +
                    "start=" + start +
                    ", end=" + end +
                    '}';
        }
        @Override
        public int compareTo(Time o) {
            return this.end - o.end;
        }
    }
    static int N;
    static Time[] times;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        times = new Time[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            times[i] = new Time(start, end);
        }
        Arrays.sort(times, new Comparator<Time>() {
            @Override
            public int compare(Time o1, Time o2) {
                if (o1.start == o2.start) {
                    return o1.end - o2.end;
                }
                return o1.start - o2.start;
            }
        });

//        for (int i = 0; i < N; i++) {
//            System.out.println(times[i]);
//        }

        PriorityQueue<Time> pq = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            Time cur = times[i];
            if (i == 0) { // 초기에는 그냥 넣기
                pq.offer(cur);
                continue ;
            }
            if (cur.start >= pq.peek().end) { // 만약 겹치지 않는 시간이라면? 뺴고 넣기
                pq.poll();
                pq.offer(cur);
            } else { // 겹치는 시간이라면 그냥 넣어서 추가
                pq.offer(cur);
            }
        }
        System.out.println(pq.size());

//        for (Time t : pq) {
//            System.out.println(t);
//        }
    }
}