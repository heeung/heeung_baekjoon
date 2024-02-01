import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static String[] arr;
    static HashSet<String> set;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new String[N];
        set = new HashSet<>();
        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine();
        }

        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o2.length() - o1.length();
            }
        });

        loop:
        for (String s: arr) {
            if (set.isEmpty()) {
                set.add(s);
            } else {
                for (String dest : set) {
                    if (dest.indexOf(s) == 0) { //접두사가 된다는 뜻
                        continue loop;
                    }
                }

                set.add(s);
            }
        }
        System.out.println(set.size());
    }
}