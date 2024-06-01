import java.io.*;
import java.util.*;
import java.math.*;

public class eric{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");
	static int[] cvt2(BigInteger x, int N){
		byte[] ba = x.toByteArray();
		int[] res = new int[ba.length*8];
		for(int i = 0; i < ba.length; i++){
			for(int j = 0; j < 8; j++){
				res[i*8+j] = (ba[i]>>(7-j)) & 1;
			}
		}
		int[] res2 = new int[N];
		for(int i = 0; i < Math.min(N, res.length); i++){
			res2[N-i-1] = res[res.length-i-1];
		}
		return res2;
	}
	static int[] cvt4(BigInteger x, int N){
		byte[] ba = x.toByteArray();
		int[] res = new int[ba.length*4];
		for(int i = 0; i < ba.length; i++){
			for(int j = 0; j < 4; j++){
				res[i*4+j] = (ba[i]>>(6-2*j)) & 3;
			}
		}
		int[] res2 = new int[N];
		for(int i = 0; i < Math.min(N, res.length); i++){
			res2[N-i-1] = res[res.length-i-1];
		}
		return res2;
	}
	static BigInteger rcvt2(int[] x){
		byte[] ba = new byte[x.length/8+10];
		int N = x.length;
		for(int i = 0; i < x.length; i++){
			int r = N-i-1;
			int rba = ba.length-i/8-1;
			int rbb = i&7;
			ba[rba] |= x[r] << rbb;
		}
		return new BigInteger(ba);
	}
	static int[] add4(int[] a, int[] b){
		int carry = 0;
		int res[] = new int[a.length];
		for(int i = a.length-1; i >= 0; i--){
			int cur = a[i] + b[i] + carry;
			carry = cur/4;
			cur %= 4;
			res[i] = cur;
		}
		return res;
	}
	public static void main(String[] args) throws IOException{
		int N = nextInt(), P = nextInt();
		while(P --> 0){
			BigInteger xi = new BigInteger(next()), yi = new BigInteger(next());
			BigInteger di = new BigInteger(next());
			int[] x = cvt2(xi, N), y = cvt2(yi, N);
			int[] b4i = new int[N];
			int dir = 0; // 0=up, 1=down, 2=left, 3=right
			for(int i = 0; i < N; i++){
				int a = x[i], b = y[i];
				if(dir == 0){
					if(a==0&&b==0){
						b4i[i] = 0;
						dir = 2;
					}
					if(a==0&&b==1){
						b4i[i] = 1;
						dir = 0;
					}
					if(a==1&&b==1){
						b4i[i] = 2;
						dir = 0;
					}
					if(a==1&&b==0){
						b4i[i] = 3;
						dir=3;
					}
				}else if(dir == 1){
					if(a==1&&b==1){
						b4i[i] = 0;
						dir = 3;
					}
					if(a==1&&b==0){
						b4i[i] = 1;
						dir = 1;
					}
					if(a==0&&b==0){
						b4i[i] = 2;
						dir = 1;
					}
					if(a==0&&b==1){
						b4i[i] = 3;
						dir = 2;
					}
				}else if(dir == 2){
					if(a==0&&b==0){
						b4i[i] = 0;
						dir = 0;
					}
					if(a==1&&b==0){
						b4i[i] = 1;
						dir = 2;
					}
					if(a==1&&b==1){
						b4i[i] = 2;
						dir = 2;
					}
					if(a==0&&b==1){
						b4i[i] = 3;
						dir = 1;
					}
				}else if(dir == 3){
					if(a==1&&b==1){
						b4i[i] = 0;
						dir = 1;
					}
					if(a==0&&b==1){
						b4i[i] = 1;
						dir = 3;
					}
					if(a==0&&b==0){
						b4i[i] = 2;
						dir = 3;
					}
					if(a==1&&b==0){
						b4i[i] = 3;
						dir = 0;
					}
				}
			}
			int w[] = add4(cvt4(di, N), b4i);
			int fx[] = new int[N], fy[] = new int[N];
			dir = 0;
			for(int i = 0; i < N; i++){
				int z = w[i];
				if(dir == 0){
					if(z==0){
						fx[i]=0;fy[i]=0;
						dir = 2;
					}
					if(z==1){
						fx[i]=0;fy[i]=1;
						dir = 0;
					}
					if(z==2){
						fx[i]=1;fy[i]=1;
						dir = 0;
					}
					if(z==3){
						fx[i]=1;fy[i]=0;
						dir = 3;
					}
				}else if(dir == 1){
					if(z==0){
						fx[i]=1;fy[i]=1;
						dir = 3;
					}
					if(z==1){
						fx[i]=1;fy[i]=0;
						dir = 1;
					}
					if(z==2){
						fx[i]=0;fy[i]=0;
						dir = 1;
					}
					if(z==3){
						fx[i]=0;fy[i]=1;
						dir = 2;
					}
				}else if(dir == 2){
					if(z==0){
						fx[i]=0;fy[i]=0;
						dir = 0;
					}
					if(z==1){
						fx[i]=1;fy[i]=0;
						dir = 2;
					}
					if(z==2){
						fx[i]=1;fy[i]=1;
						dir = 2;
					}
					if(z==3){
						fx[i]=0;fy[i]=1;
						dir = 1;
					}
				}else if(dir == 3){
					if(z==0){
						fx[i]=1;fy[i]=1;
						dir = 1;
					}
					if(z==1){
						fx[i]=0;fy[i]=1;
						dir = 3;
					}
					if(z==2){
						fx[i]=0;fy[i]=0;
						dir = 3;
					}
					if(z==3){
						fx[i]=1;fy[i]=0;
						dir = 0;
					}
				}
			}
			BigInteger pc = rcvt2(fx);
			pw.print(pc + " ");
			pc = rcvt2(fy);
			pw.println(pc);
		}
		pw.close();
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