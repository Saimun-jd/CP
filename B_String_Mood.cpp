#include <bits/stdc++.h>

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPQ(i, n) for (int i = 0; i <= n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 7;

ll MOD = 1e9 + 7;
class Matrix
{
private:
    /* data */
    std::vector<std::vector<ll>> data;
    size_t rows, cols;
public:
    Matrix(size_t rows, size_t cols)
        : rows(rows), cols(cols) 
    {
        data.resize(rows, std::vector<ll>(cols, 0));
    }

    // Constructor that accepts an initializer list of initializer lists
    Matrix(std::initializer_list<std::initializer_list<ll>> values) {
        rows = values.size();
        if (rows > 0) {
            cols = values.begin()->size();
            data.resize(rows, std::vector<ll>(cols, 0));
            size_t i = 0;
            for (const auto& row : values) {
                size_t j = 0;
                for (const int& value : row) {
                    data[i][j] = value;
                    j++;
                }
                i++;
            }
        } else {
            rows = 0;
            cols = 0;
        }
    }

    Matrix operator*(const Matrix& other){
        if(cols != other.rows){
            throw std::invalid_argument("Matrix dimensions are incompatible for multiplication");
        }
        Matrix result(rows, other.cols);
        REP(i, rows){
            REP(j, other.cols){
                REP(k, cols){
                    result.data[i][j] += (data[i][k] * other.data[k][j]) % MOD;
                }
                result.data[i][j] %= MOD; 
            }
        }
        return result;
    }
    // power of matrix
    Matrix operator^(ll power) const {
        // Identity matrix
        Matrix result(rows, cols);
        Matrix base = *this;
        for (size_t i = 0; i < rows; i++) {
            result.data[i][i] = 1;
        }
        if(power == 0)
            return result;
        else if(power == 1)
            return base;
        else{
            while (power) {
                if (power & 1)
                    result = result * base;
                base = base * base;
                power >>= 1;
            }
            return result;
        }
    }
    std::vector<ll>& operator[](size_t idx){
        return data[idx];
    }

    // Displat matrix
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; i++) {
            for (size_t j = 0; j < matrix.cols; j++) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};


void solve()
{
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Matrix M{
        {{19, 7},
        {6, 20}}
    };
    ll n;
    std::cin >> n;
    auto res = M^n;
    std::cout << res[0][0] << std::endl;
    return 0;
}