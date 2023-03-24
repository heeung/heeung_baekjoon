
import java.util.*;
import java.io.*;


public class Main {

	static String data;
	static String pattern;
	static int dlen;
	static int plen;
	static int[] table;
	static int cnt;
	static String idxs;
	static StringBuffer sb;
	
	public static void main(String[] args) throws Exception{
		init();
		makeTable();
		KMP();
		System.out.println(cnt);
		System.out.println(sb);
	}
	
	static void KMP() {
		int k=0;
		for(int i=0;i<dlen;i++) {
			while(k>0 && data.charAt(i)!=pattern.charAt(k)) {
				k = table[k-1];
			}
			if(data.charAt(i) == pattern.charAt(k)) {
				if(k==plen-1) {
//					if(cnt==0) idxs += i-plen+2;
//					else idxs += " "+(i-plen+2);
					if(cnt==0) sb.append(i-plen+2);
					else sb.append(" "+(i-plen+2));
					cnt ++;
					k = table[k];
				}else {
					k++;
				}
			}
		}
	}
	
	static void makeTable() {
		int k=0;
		for(int i=1;i<plen;i++) {
			while(k>0 && pattern.charAt(i)!=pattern.charAt(k)) {
				k = table[k-1];
			}
			if(pattern.charAt(i)==pattern.charAt(k)) table[i] += ++k;
		}
	}
	
	
	static void init() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		data = br.readLine();
		pattern = br.readLine();
		dlen = data.length();
		plen = pattern.length();
		table = new int[plen];
		cnt = 0;
		idxs = "";
		sb = new StringBuffer();
	}
}
