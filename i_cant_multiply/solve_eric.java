import java.io.*;
import java.util.*;
import java.math.*;

public class solve_eric{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");
	public static void main(String[] args) throws IOException{
		int N = nextInt(), K = nextInt();
		int A[] = new int[N];
		int nN = 0, nP = 0;
		for(int i = 0; i < N; i++){
			A[i] = nextInt();
			if(A[i] >= 0) nP++;
			if(A[i] < 0) nN++;
		}
		int ps[] = new int[nP], ng[] = new int[nN];
		int zn = 0, zp = 0;
		for(int i = 0; i < N; i++){
			if(A[i] >= 0) ps[zp++] = A[i];
			else ng[zn++] = -A[i];
		}
		Arrays.sort(ps);
		Arrays.sort(ng);
		BigInteger ans = BigInteger.ONE;
		for(int i = 0; i < K; i++){
			ans = ans.multiply(BigInteger.valueOf(A[i]));
		}
		for(int i = 0; i <= K; i++){
			int cN = i;
			int cP = K-i;
			if(cP > nP || cN > nN) continue;
			BigInteger cur = BigInteger.ONE;
			if(i % 2 == 0){
				for(int j = nP-1; j > nP-cP-1; j--){
					cur = cur.multiply(BigInteger.valueOf(ps[j]));
				}
				for(int j = nN-1; j > nN-cN-1; j--){
					cur = cur.multiply(BigInteger.valueOf(-ng[j]));
				}
			}else{
				for(int j = 0; j < cP; j++){
					cur = cur.multiply(BigInteger.valueOf(ps[j]));
				}
				for(int j = 0; j < cN; j++){
					cur = cur.multiply(BigInteger.valueOf(-ng[j]));
				}
			}
			ans = ans.max(cur);
		}
		pw.println(ans);
		br.close(); pw.close();
	}
	static String next() throws IOException{
		while(!st.hasMoreTokens()){
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
	static int nextInt() throws IOException{
		return Integer.parseInt(next());
	}
}