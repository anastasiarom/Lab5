// lab5: Родословная 
//

#include <iostream>
#include<string>
using namespace std;

int input_int(int min, int max)
{
    int i;
    bool fail = true;
    do
    {
        cin >> i;
        if (cin.fail() || i < min || i>max || cin.rdbuf()->in_avail() > 1)
            cout << "\nError" << endl;
        else
            fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}
class human
{
protected:
    string name;
    int age;
    int height;
public:
   human() : name("aaa"), age(0), height(0)
   {}
   human(string n, int a, int h) :name(n), age(a), height(h)
   {}
   virtual~human()
   {}
   virtual void output() = 0;
   virtual double ideal_weight() = 0;
   virtual void input() = 0;
   };
class granny : virtual public human
{
protected:
    string eyes;
public:
    granny(string n, int a, int h, string e) : human(n, a, h), eyes(e)
    {}
    granny()
    {}
    ~granny()
    {}
    void output()
    {
        cout << "\nMy name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
        cout << "My eyes are " << eyes << endl;
    }
    double ideal_weight()
    {
        return ((3.5 * height / 2.54) - 108) * 0.453;
    }
    void input()
    {
        cout << "For granny " << endl;
        cout << "What is your name? " << endl;
        rewind(stdin);
        getline(cin, name);
        cout << "How old are you? " << endl;
        age = input_int(40, 125);
        cout << "What is your height? " << endl;
        height = input_int(67, 272);
        cout << "What color are your eyes? " << endl;
        rewind(stdin);
        getline(cin, eyes);
    }
};
class mum : public granny
{
protected:
    string hair;
public:
    mum(string n, int a, int h, string e, string ha) : human(n, a, h), granny(n, a, h, e), hair(ha)
    {}
    mum() 
    {}
    ~mum()
    {}
    void output()
    {
        cout << "\nMy name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
        cout << "My eyes are " << eyes << endl;
        cout << "My hair is " << hair << endl;
    }
    double ideal_weight()
    {
        return  45.5 + (2.3 * (0.394 * height - 60));    
    }
    void input()
    {
        cout << "\nFor mum " << endl;
        cout << "What is your name? " << endl;
        rewind(stdin);
        getline(cin, name);
        cout << "How old are you? " << endl;
        age = input_int(18, 125);
        cout << "What is your height? " << endl;
        height = input_int(67, 272);
        cout << "What color are your eyes? " << endl;
        rewind(stdin);
        getline(cin, eyes);
        cout << "What color is your hair? " << endl;
        rewind(stdin);
        getline(cin, hair);
    }
};
class grandad :public human
{
protected:
    bool freckles;
public:
    grandad(string n, int a, int h, bool f) : human(n, a, h), freckles(f)
    {}
    grandad()
    {}
    ~grandad()
    {}
    void output()
    {
        cout << "\nMy name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
        if (freckles)
            cout << "I have got freckles" << endl;
        else
            cout << "I haven't got freckles" << endl;
    }
    double ideal_weight()
    {
        return 50+((height-150.)*0.75)+((age-21)/4);
    }
    void input()
    {
        cout << "\nFor grandad " << endl;
        cout << "What is your name? " << endl;
        rewind(stdin);
        getline(cin, name);
        cout << "How old are you? " << endl;
        age = input_int(40, 125);
        cout << "What is your height? " << endl;
        height = input_int(67, 272);
        cout << "You have freckles. Choose true(1) or false(0)" << endl;
        freckles = input_int(0, 1);
    }
};

int main()
{
    human* arr[3];
    arr[0] = new granny();
    arr[1] = new mum();
    arr[2] = new grandad();
    for (int i = 0; i < 3; i++)
    {
        arr[i]->input();
        arr[i]->output();
        cout << "Ideal weight " << arr[i]->ideal_weight() << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        delete arr[i];
    }
}

