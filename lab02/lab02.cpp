#include <iostream>
using namespace std;

class vect {
public:
    int dim;
    double* b;
    int num;
    static int count;

    vect(int n=0) : dim(n), b(new double[n]()) {
        num = ++count;
        cout<< "вектор №" << num <<" создан (dim = " << dim << ")\n";
    }
    
    vect(const vect& v) : dim(v.dim), b(new double[v.dim]) {
        num = ++count;
        for (int i = 0; i < dim; i++)
            b[i] = v.b[i];
        cout << "вектор №" << num << " создан копированием из вектора №" << v.num << "\n";
    }
    
    ~vect() {
        delete[] b;
        cout << "вектор №" << num << " удален\n";
    }
    
    vect& operator=(const vect& v) {
        if (this != &v) {
            delete[] b;
            dim = v.dim;
            b = new double[dim];
            for (int i = 0; i < dim; i++)
                b[i] = v.b[i];
            cout << "вектор №" << num << " присвоен из вектора №" << v.num << "\n";
        }
        return *this;
    }
    
    vect add(const vect& v) const {
        cout << "добавление вектора №" << num << " и вектора №" << v.num << "\n";
        vect result(dim);
        for (int i=0; i<dim; i++)
            result.b[i] = b[i] + v.b[i];
        return result;
    }
    
    vect sub(const vect& v) const {
        cout << "вычитание вектора №" << v.num << " из вектора №" << num << "\n";
        vect result(dim);
        for (int i=0; i<dim; i++)
            result.b[i] = b[i] - v.b[i];
        return result;
    }
    
    vect neg() const {
        cout << "унарный минус вектора №" << num << "\n";
        vect result(dim);
        for (int i=0; i<dim; i++)
            result.b[i] = -b[i];
        return result;
    }
    
    double dot(const vect& v) const {
        cout << "скалярное умножение вектора №" << num << " на вектор №" << v.num << "\n";
        double result = 0;
        for (int i=0; i<dim; i++)
            result += b[i] * v.b[i];
        return result;
    }
    
    vect multiply(double k) const {
        cout << "умножение вектора №" << num << " на " << k << "\n";
        vect result(dim);
        for (int i=0; i < dim; i++)
            result.b[i] = b[i] * k;
        return result;
    }
    
    void print() const {
        cout << "вектор №" << num << ": [";
        for (int i=0; i < dim; i++)
            cout << b[i] << " ";
        cout << "]\n";
    }
};

class matr {
public:
    int dim;
    double* a;
    int num;
    static int count;
    
    matr(int n=0) : dim(n), a(new double[n*n]()) {
        num = ++count;
        cout << "матрица №" << num << " создана (dim=" << dim << ")\n";
    }
    
    matr(const matr& m) : dim(m.dim), a(new double[m.dim*m.dim]) {
        num = ++count;
        for (int i = 0; i < dim*dim; i++)
            a[i] = m.a[i];
        cout << "матрица №" << num << " создана копированием из матрицы №" << m.num << "\n";
    }
    
    ~matr() {
        delete[] a;
        cout << "матрица №" << num << " удалена\n";
    }
    
    matr& operator=(const matr& m) {
        if (this != &m) {
            delete[] a;
            dim = m.dim;
            a = new double[dim*dim];
            for (int i = 0; i < dim*dim; i++)
                a[i] = m.a[i];
            cout << "матрица №" << num << " присвоена из матрицы №" << m.num << "\n";
        }
        return *this;
    }
    
    matr add(const matr& m) const {
        cout << "добавление матрицы №" << num << " и матрицы №" << m.num << "\n";
        matr result(dim);
        for(int i=0; i<dim*dim; i++)
            result.a[i] = a[i] + m.a[i];
        return result;
    }
    
    matr sub(const matr& m) const {
        cout << "вычитание матрицы №" << m.num << " из матрицы №" << num << "\n";
        matr result(dim);
        for(int i=0; i<dim*dim; i++)
            result.a[i] = a[i] - m.a[i];
        return result;
    }
    
    matr neg() const {
        cout << "унарный минус матрицы №" << num << "\n";
        matr result(dim);
        for(int i=0; i<dim*dim; i++)
            result.a[i] = -a[i];
        return result;
    }
    
    matr multiply(const matr& m) const {
        cout << "умножение матрицы №" << num << " на матрицу №" << m.num << "\n";
                matr result(dim);
                for (int i = 0; i < dim; i++) {
                    for (int j = 0; j < dim; j++) {
                        result.a[i*dim + j] = 0;
                        for (int k = 0; k < dim; k++) {
                            result.a[i*dim + j] += a[i*dim + k] * m.a[k*dim + j];
                        }
                    }
                }
                return result;
            }
            
            matr multiply(double k) const {
                cout << "умножение матрицы №" << num << " на " << k << "\n";
                matr result(dim);
                for(int i=0; i<dim*dim; i++)
                    result.a[i] = a[i] * k;
                return result;
            }
            
            vect multiply(const vect& v) const {
                cout << "умножение матрицы №" << num << " на вектор №" << v.num << "\n";
                vect result(dim);
                for (int i = 0; i < dim; i++) {
                    result.b[i] = 0;
                    for (int j = 0; j < dim; j++) {
                        result.b[i] += a[i*dim + j] * v.b[j];
                    }
                }
                return result;
            }
            
            void print() const {
                cout << "матрица №" << num << ":\n";
                for (int i = 0; i < dim; i++) {
                    cout << "[ ";
                    for (int j = 0; j < dim; j++) {
                        cout << a[i*dim + j] << " ";
                    }
                    cout << "]\n";
                }
            }
        };

        int vect::count = 0;
        int matr::count = 0;

        int main() {
            vect v1(2), v2(2);
            v1.b[0] = 1; v1.b[1] = 2;
            v2.b[0] = 3; v2.b[1] = 4;
            
            cout << "\n---действия с векторами---\n";
            vect v3 = v1.add(v2);
            v3.print();
            
            vect v4 = v1.sub(v2);
            v4.print();
            
            vect v5 = v1.neg();
            v5.print();
            
            double dot = v1.dot(v2);
            cout << "скалярное произведение: " << dot << "\n";
            
            vect v6 = v1.multiply(2.5);
            v6.print();
            
            vect v7 = v1;
            v7.print();
            
            matr m1(2), m2(2);
            m1.a[0] = 1; m1.a[1] = 2; m1.a[2] = 3; m1.a[3] = 4;
            m2.a[0] = 5; m2.a[1] = 6; m2.a[2] = 7; m2.a[3] = 8;
            
            cout << "\n---действия с матрицами---\n";
            matr m3 = m1.add(m2);
            m3.print();
            
            matr m4 = m1.sub(m2);
            m4.print();
            
            matr m5 = m1.neg();
            m5.print();
            
            matr m6 = m1.multiply(m2);
            m6.print();
            
            matr m7 = m1.multiply(2.5);
            m7.print();
            
            vect v8 = m1.multiply(v1);
            v8.print();
            
            matr m8 = m1;
            m8.print();
            
            return 0;
        }
