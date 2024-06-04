#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define double long double

using namespace std;

double PI = 3.141592653589793238462643383279502884L;

double in_circle(double xa, double ya, double ra, double x, double y){
	double lhs = (x - xa) * (x - xa) + (y - ya) * (y - ya);
	if(lhs <= ra * ra){
		return true;
	}
	return false;
}

double n1(double xa, double ya, double ra, double x, double y){
	if(in_circle(xa, ya, ra, x, y)) return 0;
	double dist_to_center = sqrt((x - xa) * (x - xa) + (y - ya) * (y - ya));
	return dist_to_center - ra;
}

double n2(double xa, double ya, double ra, double xb, double yb, double rb, double x, double y){
	if(in_circle(xa, ya, ra, x, y)) return n1(xb, yb, rb, x, y);
	// debug stuff
	double angle_min = 0;
	double angle_max = 3*PI;
	double ans = 10000;
	for(int i = 0; i < 18; i++){
		double angle_diff = angle_max - angle_min;
		double prev = 0;
		double pprev = 0;
		double prev_angle = 0;
		double pprev_angle = 0;
		int n = 7;
		for(int j = -2; j <= n+2; j++){
			double angle = angle_min + j * angle_diff / n;
			double nx = xa + ra * cos(angle), ny = ya + ra * sin(angle);
			//cerr << angle * 180 / PI << endl;
			double cur = sqrt((nx - x) * (nx - x) + (ny - y) * (ny - y)) + n1(xb, yb, rb, nx, ny);
			if(cur > prev && pprev > prev){
				angle_min = pprev_angle;
				angle_max = angle;
				ans = min(ans, cur);
				break;
			}
			pprev = prev;
			prev = cur;
			pprev_angle = prev_angle;
			prev_angle = angle;
		}
	}
	return ans;
}

double n3(double xa, double ya, double ra, double xb, double yb, double rb, double xc, double yc, double rc, double x, double y){
	if(in_circle(xa, ya, ra, x, y)){
		return n2(xb, yb, rb, xc, yc, rc, x, y);
	}
	double ans = 10000;
	int n = 9888;
	for(int i = 0; i < n; i++){
		double angle = i * 2 * PI / n;
		double nx = xa + ra * cos(angle), ny = ya + ra * sin(angle);
		//cerr << angle * 180 / PI << endl;
		double cur = sqrt(nx * nx + ny * ny) + n2(xb, yb, rb, xc, yc, rc, nx, ny);
		//cerr << angle * 180 / PI << ' ' << cur << ' ' << cur - sqrt(nx * nx + ny * ny) << endl;
		//cerr << endl << endl;
		ans = min(ans, cur);
	}
	return ans;
}

int N, X[3], Y[3], R[3], I[3];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	auto start = chrono::high_resolution_clock::now();
	for(int i = 0; i < N; i++){
		eat >> X[i] >> Y[i] >> R[i];
	}
	moo << fixed << setprecision(3);
	if(N == 1){
		moo << n1(X[0], Y[0], R[0], 0, 0) << endl;
	}else if(N == 2){
		double ans = 100000, z = 0;
		z = n2(X[0], Y[0], R[0], X[1], Y[1], R[1], 0, 0);
		ans = min(ans, z);
		z = n2(X[1], Y[1], R[1], X[0], Y[0], R[0], 0, 0);
		ans = min(ans, z);
		moo << ans << endl;
	}else{
		double ans = 100000, z = 0;
		z = n3(X[0], Y[0], R[0], X[1], Y[1], R[1], X[2], Y[2], R[2], 0, 0);
		ans = min(ans, z);
		z = n3(X[1], Y[1], R[1], X[0], Y[0], R[0], X[2], Y[2], R[2], 0, 0);
		ans = min(ans, z);
		z = n3(X[1], Y[1], R[1], X[2], Y[2], R[2], X[0], Y[0], R[0], 0, 0);
		ans = min(ans, z);
		z = n3(X[0], Y[0], R[0], X[2], Y[2], R[2], X[1], Y[1], R[1], 0, 0);
		ans = min(ans, z);
		z = n3(X[2], Y[2], R[2], X[1], Y[1], R[1], X[0], Y[0], R[0], 0, 0);
		ans = min(ans, z);
		z = n3(X[2], Y[2], R[2], X[0], Y[0], R[0], X[1], Y[1], R[1], 0, 0);
		ans = min(ans, z);
		moo << ans << endl;
	}
	auto finish = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(finish - start);
	cerr << duration.count() << endl;
}