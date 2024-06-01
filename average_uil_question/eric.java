import java.io.*;
import java.util.*;
import java.math.*;

public class eric{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");

	public static void main(String[] args) throws IOException{
		int T = nextInt();
		while(T --> 0){
			String P = next();
			char[] C = P.toCharArray();
			int L = C.length;
			BigInteger Pi = new BigInteger(P);

			double score = 0;

			// Task 01
			if(Pi.remainder(BigInteger.valueOf(3)).equals(BigInteger.ZERO)){
				score += 10;
			}

			// Task 02
			if(Pi.remainder(BigInteger.valueOf(9)).equals(BigInteger.ZERO)){
				score += 13;
			}

			// Task 03
			if(Pi.remainder(BigInteger.valueOf(11)).equals(BigInteger.ZERO)){
				score += 20;
			}

			// Task 04
			if(Pi.remainder(BigInteger.valueOf(5)).equals(BigInteger.ZERO)){
				score -= 2;
			}

			// Task 05
			if(Pi.remainder(BigInteger.valueOf(10)).equals(BigInteger.ZERO)){
				score -= 5;
			}

			// Task 06
			for(int i = 2; i < L; i++){
				if(C[i-2] == C[i-1] && C[i-1] == C[i]){
					score -= 4;
				}
			}

			// Task 07
			int occ[] = new int[10];
			for(int i = 0; i < L; i++){
				occ[C[i]-'0']++;
			}
			for(int i = 0; i < 10; i++){
				if(occ[i] > L/2){
					score -= i;
				}
			}

			// Task 08
			boolean isPalindrome = true;
			for(int i = 0; i < L; i++){
				if(C[i] != C[L-i-1]){
					isPalindrome = false;
					break;
				}
			}
			if(isPalindrome){
				score -= 10;
			}

			// Task 09
			if(L < 5){
				pw.println(0);
				continue;
			}

			// Task 10
			if(L > 10){
				score += L - 10;
			}

			// Task 11
			int nDistinct = 0;
			for(int i = 0; i < 10; i++){
				if(occ[i] > 0) nDistinct++;
			}
			if(nDistinct == 10){
				score += 20;
			}

			// Task 12
			if(nDistinct < 4){
				score -= 10;
			}

			// Task 13
			int sumOfDigits = 0;
			for(int i = 0; i < L; i++){
				sumOfDigits += C[i] - '0';
			}
			boolean isPrime = true;
			for(int i = 2; i * i <= sumOfDigits; i++){
				if(sumOfDigits % i == 0){
					isPrime = false;
					break;
				}
			}
			if(isPrime){
				score += 30;
			}

			// Task 14
			int sosod = 0;
			while(sumOfDigits > 0){
				sosod += sumOfDigits % 10;
				sumOfDigits /= 10;
			}
			if(sosod % 2 == 0){
				score -= 7;
			}

			// Task 15
			char base2[] = Pi.toString(2).toCharArray();
			int nOnes = 0;
			for(int i = 0; i < base2.length; i++){
				if(base2[i] == '1'){
					nOnes++;
				}
			}
			if(nOnes % 2 == 1){
				score += 17;
			}

			// Task 16
			for(int i = 1; i < L; i++){
				if(C[i-1] % 2 != C[i] % 2){
					score += 3;
				}
			}

			// Task 17
			int ix[] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
			int iy[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};
			double dist = 0;
			for(int i = 1; i < L; i++){
				double dx = ix[C[i]-'0'] - ix[C[i-1]-'0'];
				double dy = iy[C[i]-'0'] - iy[C[i-1]-'0'];
				dist += Math.sqrt(dx * dx + dy * dy);
			}
			double rdist = Math.round(dist*10) / 10.0;
			score += rdist;

			// Task 18
			double dp2f[][][] = new double[L][10][10];
			for(int i = 0; i < L; i++){
				for(int j = 0; j < 10; j++){
					for(int k = 0; k < 10; k++){
						dp2f[i][j][k] = 1e18;
					}
				}
			}
			for(int i = 0; i < 10; i++){
				dp2f[0][C[0]-'0'][i] = 0;
				dp2f[0][i][C[0]-'0'] = 0;
			}
			for(int i = 1; i < L; i++){
				int z = C[i]-'0';
				for(int j = 0; j < 10; j++){
					for(int k = 0; k < 10; k++){
						double dx = ix[z] - ix[j];
						double dy = iy[z] - iy[j];
						double cdst = Math.sqrt(dx * dx + dy * dy);
						dp2f[i][z][k] = Math.min(dp2f[i][z][k], dp2f[i-1][j][k] + cdst);
						dp2f[i][k][z] = Math.min(dp2f[i][k][z], dp2f[i][z][k]);
					}
				}
			}
			double cans = 1e18;
			for(int i = 0; i < 10; i++){
				for(int j = 0; j < 10; j++){
					cans = Math.min(cans, dp2f[L-1][i][j]);
				}
			}
			double rcans = (double)Math.round(cans*10) / 10.0;
			score += rcans;

			// Task 19
			long dp19[] = new long[L];
			int pv[] = new int[L];
			int po[] = new int[10];
			for(int i = 0; i < 10; i++){
				po[i] = -1;
			}
			for(int i = 0; i < L; i++){
				int z = C[i] - '0';
				pv[i] = po[z];
				po[z] = i;
			}
			for(int i = 1; i < L; i++){
				long s1 = dp19[i-1] + Math.abs(C[i] - C[i-1]);
				int z = C[i] - '0';
				long s2 = s1;
				if(pv[i] != -1){
					s2 = dp19[pv[i]] + (i - pv[i]) * z;
				}
				dp19[i] = Math.min(s1, s2);
			}
			score += dp19[L-1];

			// Task 20
			long MOD = 1000000007;
			long dp[][][][] = new long[L][2][3][2];
			for(int i = 0; i < 10; i++){
				int z = C[0] - '0';
				int i1 = 0, i2 = 0, i3 = i%3, i4 = 0;
				if(i > z){
					continue;
				}
				if(i == z){
					i4 = 1;
				}
				if(i == 3){
					i2 = 1;
				}
				dp[i1][i2][i3][i4]++;
			}
			for(int i = 1; i < L; i++){
				int z = C[i] - '0';
				for(int j = 0; j < 10; j++){
					if(j == z && j == 3){
						for(int k = 0; k < 3; k++){
							dp[i][1][(k+j)%3][1] += dp[i-1][0][k][1] + dp[i-1][1][k][1];
							dp[i][1][(k+j)%3][0] += dp[i-1][0][k][0] + dp[i-1][1][k][0];
						}
					}else if(j == z && j != 3){
						for(int k = 0; k < 3; k++){
							dp[i][0][(k+j)%3][0] += dp[i-1][0][k][0];
							dp[i][1][(k+j)%3][0] += dp[i-1][1][k][0];
							dp[i][0][(k+j)%3][1] += dp[i-1][0][k][1];
							dp[i][1][(k+j)%3][1] += dp[i-1][1][k][1];
						}
					}else if(j > z && j == 3){
						for(int k = 0; k < 3; k++){
							dp[i][1][(k+j)%3][0] += dp[i-1][0][k][0] + dp[i-1][1][k][0];
						}
					}else if(j > z && j != 3){
						for(int k = 0; k < 3; k++){
							dp[i][1][(k+j)%3][0] += dp[i-1][1][k][0];
							dp[i][0][(k+j)%3][0] += dp[i-1][0][k][0];
						}
					}else if(j < z && j == 3){
						for(int k = 0; k < 3; k++){
							dp[i][1][(k+j)%3][0] += dp[i-1][0][k][0] + dp[i-1][0][k][1] + dp[i-1][1][k][0] + dp[i-1][1][k][1];
						}
					}else if(j < z && j != 3){
						for(int k = 0; k < 3; k++){
							dp[i][0][(k+j)%3][0] += dp[i-1][0][k][0] + dp[i-1][0][k][1];
							dp[i][1][(k+j)%3][0] += dp[i-1][1][k][0] + dp[i-1][1][k][1];
						}
					}else{
						System.err.println("USDLFHSODIFHOSDIFH");
					}
				}
				for(int j = 0; j < 2; j++){
					for(int k = 0; k < 3; k++){
						for(int l = 0; l < 2; l++){
							dp[i][j][k][l] %= MOD;
						}
					}
				}
			}
			long res = MOD-1;
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 3; j++){
					for(int k = 0; k < 2; k++){
						//pw.print(dp[L-5][i][j][k] + ".");
						if(i == 0 && j != 0) continue;
						res = (res + dp[L-1][i][j][k]) % MOD;
					}
					//pw.print("/");
				}
				//pw.println();
			}
			//pw.printf("%.1f\n", score);
			score += res;
			//pw.println(res);

			pw.printf("%.1f\n", score);

		}

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