#include <bits/stdc++.h>

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPQ(i, n) for (int i = 0; i <= n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 7;

template<typename T>
class Matrix
{
private:
    /* data */
    std::vector<std::vector<T>> data;
    size_t rows, cols;
public:
    Matrix(size_t rows, size_t cols)
        : rows(rows), cols(cols) 
    {
        data.resize(rows, std::vector<T>(cols, 0));
    }

    // Constructor that accepts an initializer list of initializer lists
    Matrix(std::initializer_list<std::initializer_list<T>> values) {
        rows = values.size();
        if (rows > 0) {
            cols = values.begin()->size();
            data.resize(rows, std::vector<T>(cols, 0));
            size_t i = 0;
            for (const auto& row : values) {
                size_t j = 0;
                for (const T& value : row) {
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

    Matrix<T> operator*(const Matrix<T>& other){
        if(cols != other.rows){
            throw std::invalid_argument("Matrix dimensions are incompatible for multiplication");
        }
        Matrix<T> result(rows, other.cols);
        REP(i, rows){
            REP(j, other.cols){
                REP(k, cols){
                    result.data[i][j] += (data[i][k] * other.data[k][j]);
                }
            }
        }
        return result;
    }
    // power of matrix
    Matrix<T> operator^(ll power) const {
        // Identity matrix
        Matrix<T> result(rows, cols);
        Matrix<T> base = *this;
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
    std::vector<T>& operator[](size_t idx){
        return data[idx];
    }

    // Displat matrix
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
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

    int n;
    double p;
    std::cin >> n >> p;
    Matrix<double> M = {
        {{1-p, p},
        {p, 1-p}}
    };
    auto res = M^n;
    std::cout << std::setprecision(10) << std::fixed << res[0][0] << std::endl;
    return 0;
}