#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <utility>
using std::cout;
using std::endl;
using std::vector;
using std::pair;

void test6();
void test7();
void test8();

//task6
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    out << "[";
    for (size_t i = 0; i < v.size() - 1; ++i)
        out << v[i] << ", ";

    if (!v.empty())
    {
        out << v.back();
    }
    out << "]";
    return out;
}


template <typename T>
vector<pair<typename T::value_type, typename T::value_type>> pairing(const T& c)
{
    using val_t = T::value_type;
    vector<pair<val_t, val_t>> v{};

    for (typename T::size_type i = 0; i < (c.size() - c.size() % 2 - 1); i += 2)
        v.push_back(pair(c[i], c[i + 1]));
    if (c.size() % 2)
        v.push_back(pair(c[c.size() - 1], val_t()));
    return v;
}

//task7
template <typename T>
class Manager
{
private:
    T* _ptr;
public:
    Manager() : _ptr(nullptr) {};

    void allocate()
    {
        _ptr = (T*)std::malloc(sizeof(T));
    }

    void construct(const T& t)
    {
        new (_ptr) T(t);
    }

    void destruct() {
        _ptr->~T();
    }
    void deallocate() {
        free(_ptr);
    }

    T& get() {
        return *_ptr;
    }
};

//task8
template <typename T>
class Ref
{
private:
    T* _ptr;
public:
    Ref(T& t) : _ptr(&t) {};

    Ref(Ref& t) : _ptr(t._ptr) {};

    T& get() { return *_ptr; }

    T operator=(const T& t) { return *_ptr = t; }

    T operator+(const T& t) { return *(new T(*_ptr + t)); }

    T operator+=(const T& t) { return *this = *this + t; }

    T* operator->() { return _ptr; }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, Ref<U> r);
};

template <typename U>
std::ostream& operator<<(std::ostream& out, Ref<U> r)
{
    out << *(r._ptr);
    return out;
}


int main()
{
    test6();
    std::cout << "\n\n";
    test7();
    std::cout << "\n\n";
    test8();
}


void test6()
{
    vector v{ 10, 20, 30, 40, 50, 60 };
    cout << pairing(v) << endl;


    std::array<std::string, 7> a{ "cat", "dog", "mouse", "elephant", "tiget", "axolotl", "wolf" };
    cout << pairing(a) << endl;


    std::string s{ "Cats and dogs!" };
    cout << pairing(s) << endl;
    return;
}

/*
    Ïðîãðàììà äîëæíà íàïå÷àòàòü:
    [(10, 20), (30, 40), (50, 60)]
    [(cat, dog), (mouse, elephant), (tiget, axolotl), (wolf, )]
    [(C, a), (t, s), ( , a), (n, d), ( , d), (o, g), (s, !)]
*/

void test7()
{
    Manager<std::string> a;
    a.allocate();
    a.construct("Cats and dogs");
    a.get() += " and elephant";
    cout << a.get() << endl;
    a.destruct();
    a.construct("Sapere Aude");
    cout << a.get() << endl;
    a.destruct();
    a.deallocate();
}

void toUpper(Ref<std::string> r)
{
    for (size_t i = 0; i < r->size(); ++i)
        r.get()[i] = toupper(r.get()[i]);
}

void test8()
{
    

    int a = 10;
    Ref<int> ra = a;
    ra += 10;
    cout << a << " " << ra << endl;
    std::string s = "Cat";
    Ref<std::string> rs = s;
    rs = "Mouse";
    rs += "Elephant";
    cout << rs << endl;
    cout << s << endl;
    toUpper(s);
    cout << s << endl;
    std::vector<std::string> animals{ "Cat", "Dog", "Elephant", "Worm" };
    std::vector<Ref<std::string>> refs{ animals.begin(), animals.end() };
    for (int i = 0; i < refs.size(); ++i)
        refs[i] += "s";
    for (int i = 0; i < animals.size(); ++i)
        cout << animals[i] << " ";
    cout << endl;
}
