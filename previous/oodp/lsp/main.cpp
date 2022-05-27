#include <iostream>

class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int getWidth() const {
        return width;
    }

    virtual void setWidth(int width) {
        Rectangle::width = width;
    }

    int getHeight() const {
        return height;
    }

    virtual void setHeight(int height) {
        Rectangle::height = height;
    }

    int area() const {return width * height;}
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size,size) {}

    void setWidth(int width) override {
       this->width = this->height = width;
    }

    void setHeight(int height) override {
        this->width = this->height = height;
    }
};

void process(Rectangle& r)
{
    int w = r.getWidth();
    r.setHeight(10);

    std::cout << "expected area = " << (w*10)
         << ", got :" << r.area() << std::endl;
}

int main() {
    Rectangle r{3,4};
    process(r);

    Square s{5};
    process(s);

    return 0;
}
