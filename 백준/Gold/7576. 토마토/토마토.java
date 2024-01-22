import java.io.*;
import java.util.*;

public class Main {
    static class Point {
        int i, j;
        public Point(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    static int N, M, numTomato, cntTomato, ret;
    static int[][] map;
    static int[] di = {-1, 0, 1, 0};
    static int[] dj = {0, 1, 0, -1};
    static Queue<Point> q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        q = new LinkedList<>();
        map = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == -1) {
//                    numTomato--;
                } else {
                    numTomato++;
                    if (map[i][j] == 1) {
                        cntTomato++;
                        q.offer(new Point(i, j));
                    }
                }
            }
        }
        if (numTomato == q.size()) {
            System.out.println("0");
            return ;
        }
        bfs();
        if (cntTomato == numTomato) {
            System.out.println(ret - 1);
        } else {
            System.out.println("-1");
        }
    }

    static void bfs() {
        while (!q.isEmpty()) {
            ArrayList<Point> arr = new ArrayList<>();

            while (!q.isEmpty()) {
                arr.add(q.poll());
            }

            for (int i = 0; i < arr.size(); i++) {
                Point cur = arr.get(i);

                for (int d = 0; d < 4; d++) {
                    int ni = cur.i + di[d];
                    int nj = cur.j + dj[d];

                    if (ni >= 0 && nj >= 0 && ni < N && nj < M && map[ni][nj] == 0) {
                        cntTomato++;
                        map[ni][nj] = 1;
                        q.offer(new Point(ni, nj));
                    }
                }
            }
            ret++;
        }
    }
}