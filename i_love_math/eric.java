import java.io.*;
import java.util.*;
import java.math.*;

public class eric{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");
	static BigInteger THREE = new BigInteger("3");
	static int[] convert3(BigInteger x, int order){
		if(order == 0){
			int[] ret = new int[1];
			ret[0] = x.intValue();
			return ret;
		}
		BigInteger sep = THREE.pow(order);
		BigInteger hi = x.divide(sep);
		BigInteger lo = x.subtract(hi.multiply(sep));
		int[] a = convert3(hi, order/2), b = convert3(lo, order/2);
		int[] res = new int[a.length+b.length];
		for(int i = 0; i < a.length; i++){
			res[i] = a[i];
		}
		for(int i = 0; i < b.length; i++){
			res[i+a.length] = b[i];
		}
		return res;
	}
	public static void main(String[] args) throws IOException{
		String S = br.readLine();
		BigInteger Z = new BigInteger(S);
		int l10 = S.length();
		int l3 = (int)(l10 * 2.095903274289384604296567522021401250607518006)+5;
		int rl3 = 1;
		while(rl3 < l3){
			rl3 <<= 1;
		}
		int[] zt = convert3(Z, rl3);
		int l0 = 0;
		for(int i = 0; i < zt.length; i++){
			if(zt[i] != 0) break;
			l0++;
		}
		int[] z = new int[zt.length-l0];
		for(int i = 0; i < z.length; i++){
			z[i] = zt[i+l0];
		}
		for(int i = 0; i < z.length; i++){
			pw.print(z[i]);
		}
		pw.println();
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