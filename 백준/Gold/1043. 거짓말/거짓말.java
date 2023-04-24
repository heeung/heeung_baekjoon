import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N, M, know;
	static int[] knownPeople;
	static ArrayList<Integer>[] graph;
	static HashMap<Integer, Integer> truth;
	static ArrayList<int[]> party;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		know = Integer.parseInt(st.nextToken());
		if (know == 0) {
			System.out.println(M);
			return ;
		}
		knownPeople = new int[know];
		for (int i = 0; i < know; i++) {
			knownPeople[i] = Integer.parseInt(st.nextToken());
		}
		
		graph = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			graph[i] = new ArrayList<>();
		}
		
		party = new ArrayList<>();
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			
			int[] tmp = new int[num];
			for (int n = 0; n < num; n++) { // 일단 배열에 넣고
				tmp[n] = Integer.parseInt(st.nextToken());
			}
			if (num == 1) { // 한개면 볼것도 없음
				party.add(tmp);
				continue ;
			}
			for (int j = 0; j < num - 1; j++) { // 그래프 형성하기
				int from = tmp[j];
				int to = tmp[j + 1];
				
				graph[from].add(to);
				graph[to].add(from);
			}
			party.add(tmp);
		}
		truth = new HashMap<>();
		for (int i = 0; i < know; i++) {
			bfs(knownPeople[i]);
		}
//		System.out.println(truth.size());
		
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			int[] cur = party.get(i);
			for (int j = 0; j < cur.length; j++) {
				if (truth.containsKey(cur[j])) {
					cnt++;
					break ;
				}
			}
		}
		System.out.println(M - cnt);
		
	}
	public static void bfs(int start) {
		Queue<Integer> q = new LinkedList<>();
		boolean[] visited = new boolean[N + 1];
		truth.put(start, start);
		
		q.offer(start);
		while (!q.isEmpty()) {
			int cur = q.poll();
			
			for (int n : graph[cur]) {
				if (!visited[n]) {
					truth.put(n, n);
					visited[n] = true;
					q.offer(n);
				}
			}
		}
	}

}