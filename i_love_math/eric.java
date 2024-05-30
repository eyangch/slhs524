import java.io.*;
import java.util.*;
import java.math.*;

//210222120001110000210201012001011012201120201112002000101
//210222120001110000210201012001011012201120201112002000101

//1111202111022020201111102100020212100110222100010220010222221101120200101010211110021020222222222202220200022110210221000211110110202111210202201120200211201011110021011011222110101210010111112120122222211200120100102221202201201021102211200222011102102021110012002120121011220222202221222020222
//1111202111022020201111102100020212100110222100010220010222221101120200101010211110021020222222222202220200022110210221000211110110202111210202201120200211201011110021011011222110101210010111112120122222211200120100102221202201201021102211200222011102102021110012002120121011220222202221222020222

public class eric{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");
	static BigInteger THREE = new BigInteger("3");
	static int zt[];
	static void convert3(BigInteger x, int order, int s, int e){
		if(order == 0){
			zt[s] = x.intValue();
			return;
		}
		BigInteger sep = THREE.pow(order);
		BigInteger hi = x.divide(sep);
		BigInteger lo = x.subtract(hi.multiply(sep));
		convert3(hi, order/2, s, (s+e)/2);
		convert3(lo, order/2, (s+e)/2, e);
	}
	public static void main(String[] args) throws IOException{
		long start = System.nanoTime();
		String S = br.readLine();
		BigInteger Z = new BigInteger(S);
		Z = BigInteger.TEN.pow(100000);
		int l10 = S.length();
		l10 = 100001;
		int l3 = (int)(l10 * 2.095903274289384604296567522021401250607518006)+5;
		int rl3 = 1;
		while(rl3 < l3){
			rl3 <<= 1;
		}
		zt = new int[2*rl3];
		convert3(Z, rl3, 0, 2*rl3);
		int l0 = 0;
		for(int i = 0; i < zt.length; i++){
			if(zt[i] != 0) break;
			l0++;
		}
		int[] z = new int[zt.length-l0];
		for(int i = 0; i < z.length; i++){
			z[i] = zt[i+l0];
		}
		/*for(int i = 0; i < z.length; i++){
			pw.print(z[i]);
		}
		pw.println();*/
		long end = System.nanoTime();
		pw.println((end - start) / 1000000);
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