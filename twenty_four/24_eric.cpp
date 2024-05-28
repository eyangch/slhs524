#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, K, A[4];
int p3[] = {0, 1, 2};

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> A[0] >> A[1] >> A[2] >> A[3] >> K;
		sort(A, A+4);
		bool found = false;
		do{
			do{
				for(int i = 0; i < 4; i++){
					for(int j = 0; j < 4; j++){
						for(int k = 0; k < 4; k++){
							vector<double> stuff;
							stuff.push_back(A[0]);
							stuff.push_back(i);
							stuff.push_back(A[1]);
							stuff.push_back(j);
							stuff.push_back(A[2]);
							stuff.push_back(k);
							stuff.push_back(A[3]);
							vector<int> num;
							for(int l = 0; l < 7; l++){
								if(l % 2 == 0) num.push_back(-1);
								else num.push_back(l/2);
							}
							for(int l = 0; l < 3; l++){
								for(int m = 0; m < stuff.size(); m++){
									if(num[m] == p3[l]){

										double a = stuff[m-1];
										double x = stuff[m];
										double b = stuff[m+1];
										//moo << "OP: " << a << ' ' << x << ' ' << b << endl;
										stuff.erase(stuff.begin()+m+1);
										stuff.erase(stuff.begin()+m);
										num.erase(num.begin()+m+1);
										num.erase(num.begin()+m);
										if(x == 0) stuff[m-1] = a+b;
										if(x == 1) stuff[m-1] = a-b;
										if(x == 2) stuff[m-1] = a*b;
										if(x == 3){
											if(b == 0) stuff[m-1] = a+b;
											else stuff[m-1] = a/b;
										}
										break;
									}
								}
							}
							double res = stuff[0];
							/*if(res == 5){
								moo << A[0] << ' ' << A[1] << ' ' << A[2] << ' ' << A[3] << endl;
								moo << i << ' ' << j << ' ' << k << endl;
								moo << p3[0] << ' ' << p3[1] << ' ' << p3[2] << endl;
							}*/
							/*if(T == 1){
								if(A[0] == 7 && A[1] == 3 && A[2] == 3 && A[3] == 7 && i == 2 && j == 0 && k == 3)
								moo << res << endl; moo.flush();
							}*/
							if(abs(res - K) < 0.000001){
								found = true;
							}
						}
					}
				}
			}while(next_permutation(p3, p3+3));
		}while(next_permutation(A, A+4));
		if(found){
			moo << "YES" << endl;
		}else{
			moo << "NO" << endl;
		}
	}
}