#include <iostream>
using namespace std;

class vect {

public:
    int dim;
    double* b;
    int num;
    static int count;
    vect(int d) {
        dim = d;
        num = count++;
        b = new double[dim];
        for (int i = 0; i < dim; i++) {
            b[i] = i;
        }
        cout << "конструктор вектора " << num << " dim = " << dim << endl;
    }
    ~vect() {
        cout << "деструктор вектора " << num << endl;
        delete[] b;
    }

    vect operator+(const vect& v) {
        cout << "сложение вектора " << num << " и " << v.num << endl;
        vect result(dim);
        for (int i = 0; i < dim; i++) {
            result.b[i] = b[i] + v.b[i];
        }
        return result;
    }

    vect operator-(const vect& v) {
        cout << "вычитание вектора " << num << " и " << v.num << endl;
        vect result(dim);
        for (int i = 0; i < dim; i++) {
            result.b[i] = b[i] - v.b[i];
        }
        return result;
    }

    vect operator-() {
        cout << "отрицание вектора " << num << endl;
        vect result(dim);
        for (int i = 0; i < dim; i++) {
            result.b[i] = -b[i];
        }
        return result;
    }

    vect operator*(double k) {
        cout << "умножение вектора " << num << " na " << k << endl;
        vect result(dim);
        for (int i = 0; i < dim; i++) {
            result.b[i] = b[i] * k;
        }
        return result;
    }

    vect& operator=(const vect& v) {
        cout << "присваивание вектора " << v.num << " в вектор " << num << endl;
        if (this != &v) {
            delete[] b;
            dim = v.dim;
            b = new double[dim];
            for (int i = 0; i < dim; i++) {
                b[i] = v.b[i];
            }
        }
        return *this;
    }

    double operator*(const vect& v) {
        cout << "скалярное произведение векторов " << num << " и " << v.num << endl;
        double result = 0.0;
        for (int i = 0; i < dim; i++) {
            result += b[i] * v.b[i];
        }
        return result;
    }

    void print() const {
        cout << "вектор " << num << ": ";
        for (int i = 0; i < dim; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    static int getCount() {
        return count;
    }
};

int vect::count = 1;

class matr {
public:
    int num;
    int n, m;
    double** a;
    static int count;
    matr(int b, int c) {
        n = b;
        m = c;
        num = count++;
        a = new double* [n];
        for (int i = 0; i < n; i++) {
            a[i] = new double[m];
            for (int j = 0; j < m; j++) {
                a[i][j] = i * m + j;
            }
        }
        cout << "конструктор матрицы " << num << " (" << n << "x" << m << ")" << endl;
    }

    ~matr() {
        cout << "деструктор матрицы " << num << endl;
        for (int i = 0; i < n; i++) {
            delete[] a[i];
        }
        delete[] a;
    }

    matr operator+(const matr& mtr) {
        cout << "сложение матриц " << num << " и " << mtr.num << endl;
        matr result(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.a[i][j] = a[i][j] + mtr.a[i][j];
            }
        }
        return result;
    }

    matr operator-(const matr& mtr) {
        cout << "вычитание матриц " << num << " и " << mtr.num << endl;
        matr result(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.a[i][j] = a[i][j] - mtr.a[i][j];
            }
        }
        return result;
    }

    matr operator-() {
        cout << "отрицание матриц " << num << endl;
        matr result(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.a[i][j] = -a[i][j];
            }
        }
        return result;
    }

    matr operator*(double k) {
        cout << "умножение матриц " << num << " на " << k << endl;
        matr result(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.a[i][j] = a[i][j] * k;
            }
        }
        return result;
    }

    matr& operator=(const matr& mtr) {
        cout << "присваивание матрицы " << mtr.num << " в матрицу " << num << endl;
        if (this != &mtr) {
            for (int i = 0; i < n; i++) {
                delete[] a[i];
            }
            delete[] a;
            n = mtr.n;
            m = mtr.m;
            a = new double* [n];
            for (int i = 0; i < n; i++) {
                a[i] = new double[m]();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = mtr.a[i][j];
                }
            }
        }
        return *this;
    }

    matr operator*(const matr& mtr) {
        matr result(n, mtr.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mtr.n; j++) {
                result.a[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    result.a[i][j] += a[i][k] * mtr.a[k][j];
                }
            }
        }
        return result;
    }

    vect operator*(const vect& v) {
        cout << "умножение матрицы " << num << " на вектор " << v.num << endl;
        vect result(n);
        for (int i = 0; i < n; i++) {
            result.b[i] = 0;
            for (int j = 0; j < m; j++) {
                result.b[i] += a[i][j] * v.b[j];
            }
        }
        return result;
    }

    void print() const {
        cout << "матрица " << num << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    static int getCount() {
        return count;
    }
};

int matr::count = 1;

int main() {
    vect v1(4), v2(4);
    v1.print();
    v2.print();

    vect v3 = v1 + v2;
    v3.print();

    vect v4 = v3 - v2;
    v4.print();

    vect v5 = -v3;
    v5.print();

    vect v6 = v1 * 4;
    v6.print();

    vect v7 = v6 * v3;
    v7.print();

    v3 = v1;
    v3.print();

    matr m1(4, 4), m2(4, 4);
    m1.print();
    m2.print();

    matr m3 = m1 + m2;
    m3.print();

    matr m4 = m3 - m2;
    m4.print();

    matr m5 = -m2;
    m2.print();

    matr m6 = m1 * m3;
    m6.print();

    matr m7 = m2 * 6;
    m7.print();

    m3 = m7;
    m3.print();

    vect v8 = m2 * v2;
    v8.print();

    return 0;
}
