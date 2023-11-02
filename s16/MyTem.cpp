

static unsigned int sizeSum = 0;
static unsigned int intSum = 0;
static unsigned int floatSum = 0;
template <typename T>
void print (ostream& os, const T& t) {
    os << t;
}


template <typename T, typename... Args>
void print (ostream& os, const T& t, const Args&... args) {
    os << t << " ";
    print(os, args...);
}


template <typename... Args>
void prePrint(ostream& os, const Args&... args) {
    os << "variadic size is " << sizeof...(args) << std::endl;
    print(os, addSize(args)...);
    os << " \n Total Bytes are " << sizeSum << std::endl;
    os << "int Bytes are " << intSum << std::endl;
    os << "float Bytes are " << floatSum << std::endl;
    os << "others' Bytes are " << sizeSum - floatSum - intSum << std::endl;
}

template < typename... Args>
void print (ostream& os , const std::string& s, const Args&... args) {
    os << "\""  << s  << "\" ";
    print(os, args...);
}


template < typename... Args>
void print (ostream& os, const char* const c, const Args&... args) {
    os << "["  << c  << "," << reinterpret_cast<const void*>(c) << "] ";
    print(os, args...);
}

template < typename... Args>
void print (ostream& os, const MyClass& myClass, const Args&... args) {
    os << "{"  << myClass << ", " << &myClass << "}";
    print(os, args...);
}


template <typename T>
const T& addSize(const T& t) {
    sizeSum += sizeof(t);
    return t;
}

template <>
const float& addSize<float>(const float& i) {
    sizeSum += sizeof(i);
    floatSum += sizeof(i);
    return i;
}

template <>
const int& addSize<int>(const int& i) {
    sizeSum += sizeof(i);
    intSum += sizeof(i);
    return i;
}


