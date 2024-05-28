// Football 2

import java.util.*;
import java.lang.*;

public class solve_warith {
    
    static Scanner sc = new Scanner(System.in);
    
    static long gcd(long x, long y) {
        if (y == 0L) return x;
        return gcd(y, x % y);
    }
    
    static void answer() {
        int N = sc.nextInt(), K = sc.nextInt();
        long x = sc.nextInt(), y = sc.nextInt();
        long[][] coords = new long[N][2];
        for (int i = 0; i < N; i++) {
            coords[i][0] = sc.nextInt() - x;
            coords[i][1] = sc.nextInt() - y;
        }
        long ans = 0;
        HashMap<String, Integer> slopes = new HashMap<>();
        for (int i = 0; i < N; i++) {
            long a = coords[i][0], b = coords[i][1];
            if (a == 0 && b == 0) {
                ++ans;
                continue;
            } else if (a == 0) {
                String s = "0 " + (b < 0 ? -1 : 1);
                slopes.put(s, slopes.getOrDefault(s, 0) + 1);
            } else if (b == 0) {
                String s = (a < 0 ? -1 : 1) + " 0";
                slopes.put(s, slopes.getOrDefault(s, 0) + 1);
            }
            boolean neg = (a < 0) ^ (b < 0);
            a = Math.abs(a);
            b = Math.abs(b);
            long g = gcd(a, b);
            a /= g;
            b /= g;
            String s = (neg ? "-" : "") + a + " " + b;
            slopes.put(s, slopes.getOrDefault(s, 0) + 1);
        }
        
        ArrayList<Integer> al = new ArrayList<>();
        for (String str : slopes.keySet()) {
            al.add(slopes.get(str));
        }
        Collections.sort(al, Collections.reverseOrder());
        for (int i = 0; i < K; i++) ans += al.get(i);
        System.out.println(ans);
    }
    
    public static void main(String[] args) {
        int T = sc.nextInt();
        while (T --> 0) answer();
    }
}