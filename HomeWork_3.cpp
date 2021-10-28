#include <iostream>
#include <string>

/////// exercise 1

class Figure {
protected:
    double a;
    double h;
    double s;
    const double p = 3.14;
public:
    virtual double area() = 0;
    virtual void printarea() = 0;
};

class Parallelogram : public Figure {
public:
    Parallelogram(double a, double h) {
        this->a = a;
        this->h = h;
    }
    double area() override{
        s = a * h; // a - сторона, h - высота
        return s;
    }
    void printarea() override {
        std::cout << "Area of Parallelogram is: " << s << std::endl;
    }
};

class Circle : public Figure {
public:
    Circle(double a) {
        this->a = a;
    }
    double area() override {
        s = p * a * a; // a - радиус круга
        return s; 
    }
    void printarea() override {
        std::cout << "Area of Circle is: " << s << std::endl;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double a, double h) : Parallelogram(a, h) {}
    double area() override {
        s = a * h; // a - 1 сторона, h - 2 сторона
        return s;
    }
    void printarea() override {
        std::cout << "Area of Rectangle is: " << s << std::endl;
    }
};

class Square : public Parallelogram {
public:
    Square(double a) : Parallelogram(a,h){}
    double area() override {
        s = a*a; // a - сторона
        return s;
    }
    void printarea() override {
        std::cout << "Area of Square is: " << s << std::endl;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double h) : Parallelogram(a, h) {}
    double area() override {
        s = a * h; // a - 1 диагональ , h - 2 диагональ
        return s;
    }
    void printarea() override {
        std::cout << "Area of Rhombus is: " << s << std::endl;
    }
};

/////////

/////// exercise 2

class Car {
    std::string company;
    std::string model;
public:
    Car(std::string company, std::string model) {
        this->company = company;
        this->model = model;
        std::cout << "Company: " << company << std::endl << "Model: " << model << std::endl;
    }
};

class PassengerCar : virtual public Car {
public:
    PassengerCar(std::string company, std::string model) : Car(company, model){}
};

class Bus : virtual public Car {
public:
    Bus(std::string company, std::string model) : Car(company, model) {}
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(std::string company, std::string model) : PassengerCar(company, model), Bus(company, model), Car(company, model) {}
};

///////

////// exercise 3

class Fraction {
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    std::string getfraction()
    { 
        if ((numerator || denominator) == 0)
        {
            return "0";
        }
        else
        {
            return std::to_string(numerator) + "/" + std::to_string(denominator);
        }
    }
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return Fraction(0, 0);
    }
    else
    {
        if (f1.denominator != f2.denominator)
        {
            int numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
            int denominator = f1.denominator * f2.denominator;
            for (size_t i = 2; i < 11; i++)
            {
                if ((numerator % i) == 0 && (denominator % i) == 0)
                {
                    numerator = numerator / i;
                    denominator = denominator / i;
                    i = 1;
                }
            }
            return Fraction(numerator, denominator);
        }
        else if (f1.denominator == f2.denominator)
        {
            int numerator = f1.numerator+f2.numerator;
            int denominator = f1.denominator;
            for (size_t i = 2; i < 11; i++)
            {
                if ((numerator % i) == 0 && (denominator % i) == 0)
                {
                    numerator = numerator / i;
                    denominator = denominator / i;
                    i = 1;
                }
            }
            return Fraction(numerator, denominator);

        }
    }
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return Fraction(0, 0);
    }
    else
    {
        if (f1.denominator != f2.denominator)
        {
            int numerator = (f1.numerator * f2.denominator) - (f2.numerator * f1.denominator);
            int denominator = f1.denominator * f2.denominator;
            if (numerator < 0)
            {
                numerator = numerator * -1;
                for (size_t i = 2; i < 11; i++)
                {
                    if ((numerator % i) == 0 && (denominator % i) == 0)
                    {
                        numerator = numerator / i;
                        denominator = denominator / i;
                        i = 1;
                    }
                }
                return Fraction(numerator*-1, denominator);
            }
            else
            {
                for (size_t i = 2; i < 11; i++)
                {
                    if ((numerator % i) == 0 && (denominator % i) == 0)
                    {
                        numerator = numerator / i;
                        denominator = denominator / i;
                        i = 1;
                    }
                }
                return Fraction(numerator, denominator);
            }
        }
        else if (f1.denominator == f2.denominator && f1.numerator == f2.numerator)
        {
            return Fraction(0, 0);
        }
        else if (f1.denominator == f2.denominator)
        {
            int numerator = f1.numerator - f2.numerator;
            int denominator = f1.denominator;
            if (numerator < 0)
            {
                numerator = numerator * -1;
                for (size_t i = 2; i < 11; i++)
                {
                    if ((numerator % i) == 0 && (denominator % i) == 0)
                    {
                        numerator = numerator / i;
                        denominator = denominator / i;
                        i = 1;
                    }
                }
                return Fraction(numerator * -1, denominator);
            }
            else
            {
                for (size_t i = 2; i < 11; i++)
                {
                    if ((numerator % i) == 0 && (denominator % i) == 0)
                    {
                        numerator = numerator / i;
                        denominator = denominator / i;
                        i = 1;
                    }
                }
                return Fraction(numerator, denominator);
            }
        }
    }
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return Fraction(0, 0);
    }
    else
    {
        int numerator = f1.numerator * f2.numerator;
        int denominator = f1.denominator * f2.denominator;
        for (size_t i = 2; i < 11; i++)
        {
            if ((numerator % i) == 0 && (denominator % i) == 0)
            {
                numerator = numerator / i;
                denominator = denominator / i;
                i = 1;
            }
        }
        return Fraction(numerator, denominator);
    }
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return Fraction(0, 0);
    }
    else
    {
        int numerator = f1.numerator * f2.denominator;
        int denominator = f1.denominator * f2.numerator;
        for (size_t i = 2; i < 11; i++)
        {
            if ((numerator % i) == 0 && (denominator % i) == 0)
            {
                numerator = numerator / i;
                denominator = denominator / i;
                i = 1;
            }
        }
        return Fraction(numerator, denominator);
    }
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return false;
    }
    else
    {
        if (f1.numerator == f2.numerator && f1.denominator == f2.denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return false;
    }
    else
    {
        if (f1==f2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool operator>(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return false;
    }
    else
    {
        if (f1.denominator == f2.denominator)
        {
            if (f1.numerator > f2.numerator)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            int numerator = f1.numerator * f2.denominator;
            int numerator1 = f2.numerator * f1.denominator;
            if (numerator > numerator1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool operator<(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return false;
    }
    else
    {
        if (f1 > f2 || f1==f2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool operator<=(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return false;
    }
    else
    {
        if (f1 < f2 || f1==f2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool operator>=(const Fraction& f1, const Fraction& f2) {
    if (f1.denominator == 0 && f2.denominator == 0)
    {
        return false;
    }
    else
    {
        if (f1 > f2 || f1 == f2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

////////

/////// exercise 4

class Card {
    enum cardSuit { Hediamond, Club, Heart, Spade };
    cardSuit CS;
    enum cardValue {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
    cardValue CV;
    bool cardPos;
public:
    void Flip(){
        if (cardPos == 0) { cardPos = 1; }
        else { cardPos = 0; }
    }
    int GetValue() {
        switch (CV) {
        case Ace:
            return 1;
            break;
        case Two:
            return 2;
            break;
        case Three:
            return 3;
            break;
        case Four:
            return 4;
            break;
        case Five:
            return 5;
            break;
        case Six:
            return 6;
            break;
        case Seven:
            return 7;
            break;
        case Eight:
            return 8;
            break;
        case Nine:
            return 9;
            break;
        case Ten:
            return 10;
            break;
        case Jack:
            return 10;
            break;
        case Queen:
            return 10;
            break;
        case King:
            return 10;
            break;
        }
    }
};

//////

int main()
{
    ////// exercise 1

    Parallelogram p0(3, 2);
    Circle c0(3);
    Rectangle r0(11.2, 8.8);
    Square s0(3);
    Rhombus rh0(10.5,5.3);

    Figure* figures[] = { &p0,&c0,&r0,&s0,&rh0 };
    for (size_t i = 0; i < 5; i++)
    {
        figures[i]->area();
        figures[i]->printarea();
    }

    std::cout << std::endl;
    //////

    ///////exercise 2

    Car c1("BMW", "3 Series");
    PassengerCar p1("Toyota", "Camry");
    Bus b1("Scania", "Citywide");
    Minivan m1("Mercedes-Benz", "Viano");

    std::cout << std::endl;

    ///////

    ////// exercise 3

    Fraction f1(1, 5);
    Fraction f2(4, 5);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;
    std::cout << f3.getfraction() << std::endl;
    std::cout << f4.getfraction() << std::endl;
    std::cout << f5.getfraction() << std::endl;
    std::cout << f6.getfraction() << std::endl;
    if (f1 == f2) { std::cout << "They are equal." << std::endl; }
    else { std::cout << "They are not equal." << std::endl; }
    if (f1 != f2) { std::cout << "They are not equal." << std::endl; }
    else { std::cout << "They are equal." << std::endl; }
    if (f1 > f2) { std::cout << "The First Fraction is more than the second one." << std::endl; }
    else { std::cout << "The First Fraction is not more than the second one." << std::endl; }
    if (f1 >= f2) { std::cout << "The First Fraction is more than the second one or they are equal." << std::endl; }
    else { std::cout << "The First Fraction is not more than the second one and they are not equal." << std::endl; }
    if (f1 < f2) { std::cout << "The First Fraction is less than the second one." << std::endl; }
    else { std::cout << "The First Fraction is not less than the second one." << std::endl; }
    if (f1 <= f2) { std::cout << "The First Fraction is less than the second one or they are equal." << std::endl; }
    else { std::cout << "The First Fraction is not less than the second one and they are not equal." << std::endl; }

    //////

    system("pause");
    return 0;
}
