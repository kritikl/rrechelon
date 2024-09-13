#include <bits/stdc++.h>
using namespace std;

void converttoRRE(vector<vector<int>>& v) {
    int n = v.size();
    int m = v[0].size();
    int lead = 0;
    for (int r = 0; r < n; ++r) {
        if (lead >= m) {
            return;
        }
        int i = r;
        while (v[i][lead] == 0) {
            i++;
            if (i == n) {
                i = r;
                lead++;
                if (lead == m) {
                    return;
                }
            }
        }

        if (i != r) {
            for (int j = 0; j < m; ++j) {
                int temp = v[r][j];
                v[r][j] = v[i][j];
                v[i][j] = temp;
            }
        }

        int leadVal = v[r][lead];
        for (int j = 0; j < m; ++j) {
            v[r][j] /= leadVal;
        }

        for (int i = 0; i < n; ++i) {
            if (i != r) {
                int factor = v[i][lead];
                for (int j = 0; j < m; ++j) {
                    v[i][j] -= factor * v[r][j];
                }
            }
        }
        lead++;
    }
}
void print(vector<vector<int>> &v){
    int n = v.size();
    int m = v[0].size();

    for(int i = 0; i < n; i++){
        for(int j =  0; j < m; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
   int n, m;
   cout <<"Enter no of rows and columns of the v: ";
   cin >> n >> m;
   vector<vector<int>> v(n, vector<int> (m));
   cout << "Enter the elements of the Matrix : " << endl;
   for(int i = 0; i < n; i++){
    for(int j = 0; j  < m; j++){
        cin >> v[i][j];
    }
   }

   cout << "Initial Matrix : \n";
   print(v);

   converttoRRE(v);

    cout << "Matrix in RRE form : \n";
    print(v);
    return 0;
}