import java.io.*;
import java.util.*;
import java.math.*;

public class eric{
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int N = sc.nextInt(), P = sc.nextInt();
		while(P --> 0){
			char[] xc = sc.nextBigInteger().toString(2).toCharArray(), yc = sc.nextBigInteger().toString(2).toCharArray();
			BigInteger di = sc.nextBigInteger();
			int[] x = new int[N], y = new int[N];
			for(int i = 0; i < xc.length; i++){
				x[N-i-1] = xc[xc.length-i-1] - '0';
			}
			for(int i = 0; i < yc.length; i++){
				y[N-i-1] = yc[yc.length-i-1] - '0';
			}
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
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < N; i++){
				sb.append(b4i[i]);
			}
			BigInteger pc = new BigInteger(sb.toString(), 4).add(di);
			int w[] = new int[N];
			char[] ws = pc.toString(4).toCharArray();
			for(int i = 0; i < ws.length; i++){
				w[N-i-1] = ws[ws.length-i-1] - '0';
			}
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
			//pw.println(pc);
			sb = new StringBuilder();
			for(int i = 0; i < N; i++){
				sb.append(fx[i]);
			}
			pc = new BigInteger(sb.toString(), 2);
			pw.print(pc + " ");
			sb = new StringBuilder();
			for(int i = 0; i < N; i++){
				sb.append(fy[i]);
			}
			pc = new BigInteger(sb.toString(), 2);
			pw.println(pc);
		}
		pw.close();
	}
}