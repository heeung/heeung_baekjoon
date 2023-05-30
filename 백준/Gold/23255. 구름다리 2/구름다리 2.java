import java.io.*;
import java.util.*;

public class Main {
	static int node, edge;
	static int[] ret;
	static boolean[] visited;
	static PriorityQueue<Integer> tmpQ;
	static ArrayList<Integer>[] graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		node = Integer.parseInt(st.nextToken());
		edge = Integer.parseInt(st.nextToken());

		graph = new ArrayList[node + 1];
		visited = new boolean[node + 1];
		ret = new int[node + 1];
		for (int i = 1; i <= node; i++) {
			graph[i] = new ArrayList<>();
			graph[i].add(i);
		}

		for (int i = 0; i < edge; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			graph[from].add(to);
			graph[to].add(from);
		}

		tmpQ = new PriorityQueue<>();
		for (int i = 1; i <= node; i++) {
			Collections.sort(graph[i]);
			bfs(i);
		}

		for (int i = 1; i < ret.length; i++) {
			System.out.print(ret[i] + " ");
		}
	}

	static void bfs(int start) {
		HashSet<Integer> set = new HashSet<>();

		for (int n : graph[start]) {
			if (ret[n] != 0) {
				set.add(ret[n]);
			}
		}
		int num = 1;
		while (set.size() != 0) {
			if (set.contains(num)) {
				set.remove(num);
				num++;
			} else
				break;
		}
		ret[start] = num;
	}
}