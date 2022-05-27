#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>

enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product
{
    std::string name;
    Color color;
    Size size;

};

struct ProductFilter
{
    std::vector<Product*> by_color(std::vector<Product*> items, Color color)
    {
        std::vector<Product*> result;
        for(auto& i : items)
            if(i->color == color)
                result.push_back(i);
        return result;
    }

    std::vector<Product*> by_size(std::vector<Product*> items, Size size)
    {
        std::vector<Product*> result;
        for(auto& i : items)
            if(i->size == size)
                result.push_back(i);
        return result;
    }

    std::vector<Product*> by_size_and_color(std::vector<Product*> items, Size size, Color color)
    {
        std::vector<Product*> result;
        for(auto& i : items)
            if(i->size == size && i->color == color)
                result.push_back(i);
        return result;
    }
};
template <typename T> struct AndSpecification;

template <typename T> struct Specification
{
    virtual bool is_satisfied(T* item) = 0;

    AndSpecification<T> operator&&(Specification<T>&& other)
    {
        return AndSpecification(*this, other);
    }
};

template <typename T> struct Filter
{
    virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>&) = 0;
};

struct BetterFilter : Filter<Product>
{
    std::vector <Product*> filter(std::vector<Product*> items, Specification<Product> &spec) override
    {
        std::vector<Product*> result;
        for (auto& item : items)
            if(spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;
    ColorSpecification(Color color) : color(color){}
    bool is_satisfied(Product* item) override
    {
        return item->color == color;
    }
};


struct SizeSpecification : Specification<Product>
{
    Size size;
    SizeSpecification(Size s) : size(s){}
    bool is_satisfied(Product* item) override
    {
        return item->size == size;
    }
};


template <typename T> struct AndSpecification : Specification<T>
{
    Specification<T>& left;
    Specification<T>& right;

    AndSpecification(Specification<T>& l, Specification<T>& r) : left(l), right(r){}
    bool is_satisfied(T* item) override
    {
        return left.is_satisfied(item) && right.is_satisfied(item);
    }

};



int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    std::vector< Product*> items {&apple, &tree, &house};

    ProductFilter pf;
    auto green_things = pf.by_color(items, Color::green);
    auto large_things = pf.by_size(items, Size::large);
    auto large_and_green_things = pf.by_size_and_color(items, Size::large, Color::green);

    for (auto& item : green_things)
        std::cout << item->name << " is green."<< std::endl;

    for (auto& item : large_things)
        std::cout << item->name << " is large."<< std::endl;

    for (auto& item : large_and_green_things)
        std::cout << item->name << " is large and green."<< std::endl;

    BetterFilter bf;
    ColorSpecification green_color(Color::green);
    SizeSpecification large_size(Size::large);
    AndSpecification<Product> large_green(large_size, green_color);

    auto lgcombo = ColorSpecification(Color::green) && SizeSpecification(Size::large);

    for (auto& item : bf.filter(items, green_color))
        std::cout << item->name << " is green.\n";

    for (auto& item : bf.filter(items, large_size))
        std::cout << item->name << " is large.\n";

    for (auto& item : bf.filter(items, large_green))
        std::cout << item->name << " is large and green.\n";

    for (auto& item : bf.filter(items, lgcombo))
        std::cout << item->name << " is large and green.\n";
}
