import java.io.*;
import java.util.*;

public class Main {
    static int N, cnt;
    static String str;
    static HashMap<Character, Integer> map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        str = br.readLine();
        if (str.length() == 1) {
            System.out.println("1");
            return ;
        }
        // 무조건 2글자 이상
        int left = 0;
        int right = 0;

        map = new HashMap<>();

        map.put(str.charAt(left), 1);
        map.put(str.charAt(right), 1);

        while (right < str.length()) {

            if (map.size() <= N) {
                cnt = Math.max(cnt, right - left);

                right++;

                if (right == str.length()) {
                    continue ;
                }

                if (map.containsKey(str.charAt(right))) {
                    map.put(str.charAt(right), map.get(str.charAt(right)) + 1);
                } else {
                    map.put(str.charAt(right), 1);
                }

//                cnt = Math.max(cnt, right - left);

            } else {
                if (map.get(str.charAt(left)) == 1) {
                    map.remove(str.charAt(left));
                } else {
                    map.put(str.charAt(left), map.get(str.charAt(left)) - 1);
                }
                left++;
            }
        }

        System.out.println(cnt + 1);
    }
}