import java.io.*;
import java.util.*;
import java.math.*;

public class anthony {
    static Scanner sc = new Scanner(System.in);
    static final int MOD = 1_000_000_007;
    public static void main(String[] args) {
        String s = sc.nextBigInteger().add(BigInteger.ONE).toString(3);
        int n = s.length();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = s.charAt(i) - '0';
        long[] pref = new long[n]; pref[0] = a[0];
        for (int i = 1; i < n; i++) pref[i] = (pref[i-1] * 3 + a[i]) % MOD;
        long[] pow3 = new long[n+1]; pow3[0] = 1;
        for (int i = 1; i < n+1; i++) pow3[i] = pow3[i-1] * 3 % MOD;
        long ans = 0;
        // sum of digits
        for (int i = 0; i < n; i++) {
            long add = i == 0 ? 0 : pref[i-1];
            add *= pow3[n-i]; add %= MOD;
            add += (long)a[i] * (a[i] - 1) / 2 * pow3[n-1-i] % MOD; add %= MOD;
            long suf = (pref[n-1] - pref[i] * pow3[n-1-i]) % MOD;
            add += suf * a[i] % MOD; add %= MOD;
            ans += add; ans %= MOD;
        }
        // sum of lengths
        for (int i = 0; i < n; i++) {
            ans += pref[n-1] - pow3[n-1-i]; ans %= MOD;
        }
        ans -= pref[n-1] - 1; ans %= MOD;
        if (ans < 0) ans += MOD;
        System.out.println(ans);
    }
}
