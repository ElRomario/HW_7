#include <iostream>

using namespace std;

namespace Geometry
{
    class PointXY
    {
    private:
        double x;
        double y;
    public:
        PointXY(double _x, double _y) : x{ _x }, y{ _y } {}
        PointXY() : PointXY(1, 1) {}

        static PointXY mult(const PointXY& p1, double value)
        { return PointXY(p1.x * value, p1.y * value); }

        static bool isEqual(const PointXY& p1, const PointXY& p2)
        { return p1.x == p2.x && p1.y == p2.y; }

        void showInfo() const
        { cout << "X = " << x << "\nY = " << y << endl; }

        friend const PointXY operator+(const PointXY& p1, const PointXY& p2)
        { return PointXY(p1.x + p2.x, p1.y + p2.y); }

        friend const PointXY operator+(const PointXY& p1, double var)
        { return PointXY(p1.x + var, p1.y + var); }

        friend const PointXY operator+(double var, const PointXY& p1)
        { return PointXY(var + p1.x, var + p1.y); }

        friend ostream& operator<<(ostream& output, const PointXY& p1)
        {
            output << "(" << p1.x << "," << p1.y << ")" << endl;
            return output;
        }

        friend istream& operator>>(istream& input, PointXY& p1)
        {
            input >> p1.x >> p1.y;
            return input;
        }
    };

    class PointXYZ
    {
    private:
        double x;
        double y;
        double z;
    public:
        PointXYZ(double _x, double _y, double _z) : x{ _x }, y{ _y }, z{ _z } {}
        PointXYZ() : PointXYZ(1, 1, 1) {}

        void showInfo() const 
        { cout << "X = " << x << "\nY = " << y << "\nZ = " << z << endl; }

        static PointXYZ mult(const PointXYZ& p1, double value)
        {
            return PointXYZ(p1.x * value, p1.y * value, p1.z * value);
        }

        static bool isEqual(const PointXYZ& p1, const PointXYZ& p2)
        {
            return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;
        }

        friend const PointXYZ operator+(const PointXYZ& p1, const PointXYZ& p2)
        {
            return PointXYZ(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
        }

        friend const PointXYZ operator+(const PointXYZ& p1, double var)
        {
            return PointXYZ(p1.x + var, p1.y + var, p1.z + var);
        }

        friend const PointXYZ operator+(double var, const PointXYZ& p1)
        {
            return PointXYZ(var + p1.x, var + p1.y, var + p1.z);
        }

        friend ostream& operator<<(ostream& output, const PointXYZ& p1)
        {
            output << "(" << p1.x << "," << p1.y << ")" << endl;
            return output;
        }

        friend istream& operator>>(istream& input, PointXYZ& p1)
        {
            input >> p1.x >> p1.y >> p1.z;
            return input;
        }
    };
}

namespace MathOperations
{
    class Fraction 
    {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int _numerator, int _denominator) : numerator{ _numerator }, denominator{ _denominator } {}
        Fraction() : Fraction(1, 1) {}

        void showInfo() const {
            cout << numerator << " / " << denominator << endl;
        }
    };
}

int main() {
    Geometry::PointXY p1xy{ 1, 4 };
    Geometry::PointXY p2xy{ 2, 5 };
    Geometry::PointXY p3xy;
    double abc = 1.5;
    p3xy = abc + p1xy;
    p3xy.showInfo();

    Geometry::PointXYZ p1xyz{ 1, 2, 3 };
    Geometry::PointXYZ p2xyz{ 4, 5, 5 };
    Geometry::PointXYZ p3xyz;
    double def = 2.5;
    p3xyz = abc + p1xyz;
    p3xyz.showInfo();

    MathOperations::Fraction f1{ 3, 4 };
    MathOperations::Fraction f2{ 5, 6 };
    f1.showInfo();
    f2.showInfo();

    return 0;
}