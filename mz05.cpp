#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Figure
{
    virtual ~Figure(){};
    virtual double get_square() const = 0;
    virtual std::string to_string() const{}; // = 0; #TODO реализовать to_string в наследниках
};

struct Rectangle : Figure
{
private:
    double a, b;
public:
    double get_square() const override{
        return a * b;
    }

    Rectangle(double a, double b) : a(a), b(b){};

    static Rectangle* make(const std::string &s) {
        std::istringstream some_stream(s);
        double a, b;
        some_stream >> a >> b;
        return new Rectangle(a, b);
    } 

    ~Rectangle() override = default;
};

struct Square : Figure
{
private:
    double a;
public:
    double get_square() const override{
        return a * a;
    }

    explicit Square(double a) : a(a){};

    static Square* make(const std::string &s) {
        std::istringstream some_stream(s);
        double a;
        some_stream >> a;
        return new Square(a);
    }

    ~Square() override = default;
};

struct Circle : Figure
{
private:
    double r;
public:
    double get_square() const override {
        return M_PI * r * r;
    }

    explicit Circle(double r) : r(r){};

    static Circle* make(const std::string &s) {
        std::istringstream some_stream(s);
        double r;
        some_stream >> r;
        return new Circle(r);
    }

    ~Circle() override = default;
};

struct Singleton
{
private:
    Singleton() = default;
    Singleton(const Singleton&) = default;
    Singleton& operator=(Singleton&);
public:
    static Singleton & factory_instance() {
        static Singleton s;
        return s;
    }

    static Figure* createFigure(char type, const std::string &s) {
        switch(type)
        {
            case 'S':
                return Square::make(s);
            case 'C':
                return Circle::make(s);
            default :
                return Rectangle::make(s);
        }
    }


};

bool cmp(const Figure * a, const Figure * b) {
    return a->get_square() < b->get_square();
}

int main()
{
    std::vector<Figure *> objects;
    Singleton &instance = Singleton::factory_instance();
    std::string s;
    while (std::getline(std::cin, s)) {
        std::istringstream some_stream(s);
        char id;
        std::string to_mk, second_p;
        some_stream >> id >> to_mk;
        if (id == 'R') {
            some_stream >> second_p;
            to_mk.append(" ");
            to_mk.append(second_p);
        }

        objects.push_back(instance.createFigure(id, to_mk));
    }

    stable_sort(objects.begin(), objects.end(), cmp);
    for (auto f : objects) {
        std::cout << f->to_string() << std::endl;
    }

    for (auto it : objects) {
        delete it;
    }
}
