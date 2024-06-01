import java.io.*;
import java.util.*;
import java.math.*;

//210222120001110000210201012001011012201120201112002000101
//210222120001110000210201012001011012201120201112002000101
//210222120001110000210201012001011012201120201112002000101

//1111202111022020201111102100020212100110222100010220010222221101120200101010211110021020222222222202220200022110210221000211110110202111210202201120200211201011110021011011222110101210010111112120122222211200120100102221202201201021102211200222011102102021110012002120121011220222202221222020222
//1111202111022020201111102100020212100110222100010220010222221101120200101010211110021020222222222202220200022110210221000211110110202111210202201120200211201011110021011011222110101210010111112120122222211200120100102221202201201021102211200222011102102021110012002120121011220222202221222020222
//1111202111022020201111102100020212100110222100010220010222221101120200101010211110021020222222222202220200022110210221000211110110202111210202201120200211201011110021011011222110101210010111112120122222211200120100102221202201201021102211200222011102102021110012002120121011220222202221222020222

public class eric{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");
	static int MOD = 1000000007;
	public static void main(String[] args) throws IOException{
		String S = br.readLine();
		BigInteger Z = new BigInteger(S);
		String Z3 = Z.toString(3);
		int[] z = new int[Z3.length()];
		for(int i = 0; i < z.length; i++){
			z[i] = Z3.charAt(i)-'0';
		}
		int N = z.length;
		long dp[][][] = new long[N][3][2]; // digit#, number, isprefix
		long ex[][][] = new long[N][3][2];
		for(int i = 0; i < N; i++){
			if(i == 0){
				for(int j = 1; j < 3; j++){
					if(j < z[i]){
						dp[i][j][0] = j;
						ex[i][j][0] = 1;
					}
					if(j == z[i]){
						dp[i][j][1] = j;
						ex[i][j][1] = 1;
					}
				}
				continue;
			}
			for(int j = 0; j < 3; j++){
				if(j != 0){
					dp[i][j][0] += j;
					ex[i][j][0]++;
				}
				if(j > z[i]){ // can't use isprefix, only use nonprefix
					for(int k = 0; k < 3; k++){
						dp[i][j][0] += dp[i-1][k][0] + (j+1) * ex[i-1][k][0] % MOD;
						ex[i][j][0] += ex[i-1][k][0];
						dp[i][j][0] %= MOD;
						ex[i][j][0] %= MOD;
					}
				}else if(j == z[i]){ // isprefix -> isprefix, nonprefix -> nonprefix
					for(int k = 0; k < 3; k++){
						dp[i][j][0] += dp[i-1][k][0] + (j+1) * ex[i-1][k][0] % MOD;
						ex[i][j][0] += ex[i-1][k][0];
						dp[i][j][0] %= MOD;
						ex[i][j][0] %= MOD;
						dp[i][j][1] += dp[i-1][k][1] + (j+1) * ex[i-1][k][1] % MOD;
						ex[i][j][1] += ex[i-1][k][1];
						dp[i][j][1] %= MOD;
						ex[i][j][1] %= MOD;
					}
				}else{
					for(int k = 0; k < 3; k++){
						dp[i][j][0] += dp[i-1][k][0] + (j+1) * ex[i-1][k][0] % MOD;
						ex[i][j][0] += ex[i-1][k][0];
						dp[i][j][0] %= MOD;
						ex[i][j][0] %= MOD;
						dp[i][j][0] += dp[i-1][k][1] + (j+1) * ex[i-1][k][1] % MOD;
						ex[i][j][0] += ex[i-1][k][1];
						dp[i][j][0] %= MOD;
						ex[i][j][0] %= MOD;
					}
				}
			}
		}
		long ans = 0;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 2; j++){
				ans = (ans + dp[N-1][i][j]) % MOD;
			}
		}
		pw.println(ans);
		/*for(int i = 0; i < z.length; i++){
			pw.print(z[i]);
		}
		pw.println();*/
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