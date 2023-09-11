#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

class Base : public runtime_error 
{
public:
    Base(const string& message) : runtime_error(message) {}
    virtual ~Base() = default;
};

class MathError : public Base 
{
public:
    MathError(const string& message) : Base(message) {}

    static double divide(double a, double b) 
    {
        if (b == 0)
            throw MathError("Деление на ноль!");
        return a / b;
    }
};

class MemoryError : public Base 
{
public:
    MemoryError(const string& message) : Base(message) {}

    static void allocateMemory() 
    {
        char* bigArray = nullptr;
        try 
        {
            bigArray = new char[1000000000000];
        }
        catch (bad_alloc& e) 
        {
            throw MemoryError("Не удалось выделить память!");
        }
        delete[] bigArray;
    }
};

class FileError : public Base 
{
public:
    FileError(const string& message) : Base(message) {}

    static void openFile() 
    {
        ifstream file("test.txt");
        if (!file.is_open())
            throw FileError("Не удалось открыть файл!");
    }
};

int main() 
{
    setlocale(LC_ALL, "ru");
    try 
    {
        double result = MathError::divide(10.0, 0.0);
    }
    catch (const MathError& e)
    {
        cerr << "Математическая ошибка: " << e.what() << endl;
    }

    try {
        MemoryError::allocateMemory();
    }
    catch (const MemoryError& e) 
    {
        cerr << "Ошибка памяти: " << e.what() << endl;
    }

    try 
    {
        FileError::openFile();
    }
    catch (const FileError& e) 
    {
        cerr << "Файловая ошибка: " << e.what() << endl;
    }

    return 0;
}