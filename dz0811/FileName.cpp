#include<iostream>
#include<vector>
#include<cmath>  // for sqrt function
using namespace std;

class Equation
{
public:
    virtual vector<double> roots() = 0;
};

class Linear : public Equation
{
public:
    Linear(int n1, int n2)
    {
        this->_n1 = n1;
        this->_n2 = n2;
    }
    vector<double> roots() override
    {
        vector<double> r;
        r.push_back((-double(_n1) / _n2));
        return r;
    }
private:
    int _n1;
    int _n2;
};

class Quadratic : public Equation
{
public:
    Quadratic(int n1, int n2, int n3)
    {
        this->_n1 = n1;
        this->_n2 = n2;
        this->_n3 = n3;
    }
    vector<double> roots() override
    {
        vector<double> r;
        double d = sqrt((double(_n2) * _n2) - (4 * _n1 * _n3));
        if (d < 0)
        {
            return r;
        }
        else if (d == 0)
        {
            r.push_back(-double(_n2) / (2 * _n1));
            return r;
        }
        else
        {
            r.push_back((-double(_n2) + d) / (2 * _n1));
            r.push_back((-double(_n2) - d) / (2 * _n1));
            return r;
        }
    }
private:
    int _n1;
    int _n2;
    int _n3;
};

int main()
{
    Linear l(4, 5);
    Quadratic q(1, -3, 2);
    vector<double> r;
    r = l.roots();
    cout << "X: " << r[0] << endl;
    r.clear();
    r = q.roots();
    for (size_t i = 0; i < r.size(); i++)
    {
        cout << "X" << i + 1 << ": " << r[i] << endl;
    }
    return 0;
}
