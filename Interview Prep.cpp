
#include <iostream>
#include <string>
#include <map>
#include <algorithm>



using std::cout; using std::endl;
void pointers();
void increment(int* a);
int& increment1(const int& a);
int& set_g_a();

int g_a = 1;


class Player {
public:
    int x, y;
    int speed;
    int health;
    int* healthpnt = &health;

    int* add() {
        int result;
        int* ptr = &result;
        result = x + y;

        return ptr;

    }

};

struct Position {
    static int x, y;

    void printPos() {
        cout << x << ", " << y << endl;
    }
}pos1;

int Position::x = 3;
int Position::y = 4;



enum Level : int {
    A,B,C
};


int f(int n);



struct printName {
    void virtual PrintName() const = 0;


};




class Test : public printName {
protected:
    int m_x;
    mutable int m_y;

public:
    Test() :m_x(10), m_y(12) {
        std::cout << "Making Test " << m_y << m_x << std::endl;
    }
    Test(int setx, int sety) : m_x(setx), m_y(sety) {
        std::cout << "Making Test " << m_y << m_x << std::endl;
    }

    ~Test() {
        std::cout << "deleting Test " << m_x << m_y << std::endl;
    }

    virtual void getXchangeY()const {
        m_y = 24;
        std::cout << m_x << " " << m_y << std::endl;
    }

    void PrintName() const {
        std::cout << "Test" << std::endl;
    }

};

void printname(const Test& var) {
    var.PrintName();
}

void printname(Test&& var) {
    var.PrintName();
}

class Derived : public Test {

public:

    //explicit Derived() = default;
    Derived()
        :Test(5, 6) {
        //m_x = 5;
        //m_y = 6;
    }
    //Derived(const int& setx, const int& sety) : m_x(setx), m_y(sety) {}

    void getXchangeY()const override final {
        //m_y = 94;
        std::cout << m_x << " " << m_y << std::endl;
    }
    void printY() const {
        std::cout << m_y << std::endl;
    }
    void PrintName() const {
        std::cout << "Derived" << std::endl;
    }

};


class FriendTest {
private:
    static int m_a;

    friend class MyFriend;
};

class MyFriend {
    MyFriend(int a) {
        FriendTest object;
        object.m_a = a;
    }

};




class Shape {
private:
    std::string name;
public:
    Shape(std::string n) : name(n) {}

    std::string getName()const {
        return name;
    }

    virtual int perimeter(){
        return 0;
    };

};

class Rectangle : public Shape {
    int side1, side2;
    int per;
public:
    Rectangle(std::string n, int r, int r2) : Shape(n),side1(r),side2(r2) {
        per = 2*(side1) + 2*(side2);
    }
    int perimeter() override {
        return per;
    }

    void sayFart() {
        std::cout << "Fart" << std::endl;
    }

};

double vals[] = { 10.1, 12.6, 33.1, 24.1, 50.0 };

double& fixElement(int a) {
    return vals[a];
}

std::map<char, int> symbols = {
    {'!', 1},
    {'@', 2},
    {'#', 3}
};



std::string reverse(std::string word) {
    std::string backw = "";

    for (int i = word.length(); i >= 0; i--){
        backw = backw + word[i];
    }
    return backw;
}

std::string sortString(const std::string& word) {
    std::string newString = word;

    std::sort(newString.begin(), newString.end());
   
    return newString;
}



int main() {
    int myArray[] = { 1,2,5,7,3,21,1,3,45,3 };

    std::sort(myArray,(myArray + (sizeof(myArray) / sizeof(myArray[0]))));
    //for (auto i : myArray) { std::cout << i << std::endl; }

    std::cout << /*(&myArray + 1) -*/ *myArray  << std::endl;


    std::string newWord = reverse("Piggy");
    std::cout << newWord << std::endl;
    
    newWord = sortString("Piggy");
    std::cout << newWord << std::endl;
    
    std::cout << "test" << std::endl;
    std::cout << symbols['@'] << std::endl;
    std::cout << symbols['@'] << std::endl;

   /* Shape s("sahpe");
    std::cout << s.getName() << std::endl;
    std::cout << s.perimeter() << std::endl;

    Rectangle r("rect" , 1, 2);
    std::cout << r.getName() << std::endl;
    std::cout << r.perimeter() << std::endl;

    Rectangle* rect = new Rectangle("heello", 2,3);
    std::cout << rect->perimeter() << std::endl;
    rect->sayFart();*/


    //fixElement(0) = 300.0f;
    //for (auto i : vals)
    //{
    //    std::cout << i << std::endl;
    //}


    Level Dial = B;
    cout << "Dial level is: " << Dial << endl;

    Player p1;
    p1.x = 2;
    p1.y = 6;
    p1.health = 5;

    cout << *p1.add() << endl;

    int* a = new int;
    *a = 9;

    cout << a << endl;
    delete a;

    pos1.x = 5;
    Position::x = 6;

    pos1.printPos();
    int x = 7;
    int y = increment1(x);
    cout << y << endl;
    set_g_a() = 300;
    cout << g_a << endl;
    int c = set_g_a() = 200;
    cout << c << endl;
    cout << g_a << endl;


    //Test *obj2 = new Derived();

    //obj2->getXchangeY();
    //((Derived*)(obj2))->printY;
    //obj2->PrintName();

    Test* obj = new Test(2, 3);

    //obj->getXchangeY();
    //obj->PrintName();

    Test obj1 = { 13,14 };
    printname(*obj);
    printname(std::move(obj1));

    delete obj;
    //delete obj2;

    //for (int i = 1; i < 101; i++) {
    ///*	if (i % 3) {
    //		cout << "fizz"
    //	}*/

    //	i % 3 == 0 ? i % 5 == 0 ? std::cout << "fizzbuzz" << std::endl : std::cout << "fizz" << std::endl : i % 5 == 0 ? std::cout << "buzz" << std::endl : std::cout << i << std::endl;

    //}
    try {
        f(-1);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

}


int f(int n)
{
    if (n < 0) {
        throw std::runtime_error("error n < 0");
    }
    if (n == 0)
        return 1;

    return f(n - 1) * n;
}



int& set_g_a() {
    return g_a;
}

int& increment1(const int& a) {
    int b = a + 1;
    return b;
}

void increment(int* a) {
    (*a)++;

}


void pointers() {
    int var = 8;

    int* ptr = &var;

    cout << *ptr << endl;
    cout << &var << endl;

    *ptr = 10;

    cout << *ptr << endl;
    cout << &var << endl;


    int** doubleptr = &ptr;

    cout << **doubleptr << endl;
    cout << &var << endl;
    char* buffer = new char[8];

    delete[] buffer;



    int a = 5;

    int* b = &a;

    int& ref = a;
}
