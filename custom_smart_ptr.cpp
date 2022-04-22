//作者：灯又烬
//链接：https://www.nowcoder.com/discuss/640457?channel=-1&source_id=discuss_terminal_discuss_sim_nctrack&ncTraceId=97a9ae9d1f344b2cb80c7f2f68231c35.477.16479376006407709
//来源：牛客

template<typename SmartPointer,typename Type>
class Ref{
    friend SmartPointer;
    Ref(Type* _p) :p(_p), count(1){}
    ~Ref(){ delete p; }
    Type *p;
    size_t count;
};
 
template <typename T>
class myPointer{
private:
    Ref<myPointer, T> *rf;
public:       
    myPointer(T *p) : rf(new Ref<myPointer, T>(p)) {}
    myPointer(const myPointer &a) : rf(a->rf){}
    ~myPointer(){if(!--rf->count) delete rf;}

    myPointer& operator=(const myPointer &rhs) {
        ++rhs->count; //increase the ref count for the argument;
        if(!--rf->count) delete rf; //if no smart_ptr is pointing at the current ref of this smart_ptr, free memory.
        rf = rhs->rf; // passing new ref to this smart_ptr;
        if(!--rhs->rf->count) delete rhs;
        return *this;
    }

    T operator *(const myPointer &p) const{
        return *(rf->p);
    }
 
};