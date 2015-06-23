/****************************************************
    作者：zhanghx
    时间：2014-4-14
    功能：Magine系统内部使用的向量结构，易于定义出常用的数据格式
    参考：


******************************************************/
#ifndef MAGINE_MAGINEBASE_MAGINEMATH_VECTORT_H
#define MAGINE_MAGINEBASE_MAGINEMATH_VECTORT_H

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>    //包括一些异常处理:std::out_of_range 在at函数中


namespace Magine
{

typedef double Scalar;

template <size_t N,typename T>
class VectorT
{
public:
    /**********************构造函数**********************************/
    //
    VectorT()
    {
        for(size_t i=0;i<N;i++) value_[i]=T(0);
    }
    //一维向量
    VectorT(const T& a)
    {
        for(size_t i=0;i<N;i++) value_[i]=a;
    }
    //二维向量
    VectorT(const T& a,const T& b)
    {
        assert(N==2);
        value_[0]=a;value_[1]=b;
    }
    //三维向量
    VectorT(const T& a,const T& b,const T& c)
    {
        assert(N==3);
        value_[0]=a;value_[1]=b;value_[2]=c;
    }
    //四维向量
    VectorT(const T& a,const T& b,const T& c,const T& d)
    {
        assert(N==4);
        value_[0]=a;value_[1]=b;value_[2]=c;value_[3]=d;
    }
    VectorT(const VectorT<N,T>& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]=v[i];
    }
    /****************Element Access*********************************/
    //
    T& operator [](size_t idx)    //for non-const object
    {
        return value_[idx];
    }
    const T& operator [] (size_t idx) const   //for const object
    {
        return value_[idx];
    }

    T& at(size_t idx)
    {
        if(idx>=N)	throw std::out_of_range("VecotorT_at!");
        return value_[idx];
    }
    const T& at(size_t idx) const
    {
        if(idx>=N)	throw std::out_of_range("VecotorT_at!");
        return value_[idx];
    }
    //
    const T* data() const
    {
        return value_;
    }
    //获取数组数据
    T* data()
    {
        return value_;
    }
    /*****************向量信息***********************************************/
    size_t size() const
    {
       return N;
    }

    //****************赋值比较***********************************************/
    //用标量赋值
    VectorT<N,T>& operator=(const T& s)
    {
        for(size_t i=0;i<N;i++)
            value_[i]=s;
        return *this;
    }
    //向量赋值
    VectorT<N,T>& operator=(const VectorT<N,T>& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]=v[i];
        return *this;
    }
    //相等判定
    bool operator==(const VectorT<N,T> &v) const
    {
        for (int i=0; i<N; i++)
            if (value_[i]!=v.value_[i])
                return false;
        return true;
    }
    //不相等判定
    bool operator!=(const VectorT<N,T> &v) const
    {
        for (int i=0; i<N; i++)
            if (value_[i]==v.value_[i])
                return false;
        return true;
    }
    /*********************Scalar Operation**********************/
    /*其中+,-,*,/的一个标量使有了临时变量，此处考虑的是使向量与标量运算之后在表达式中并不
      能改变向量的值，如cout<<vec1+3+vec4<<endl;想要改变值可以 vec1+=3 或者vec1=vec1+3
      by zhanghx 2014.4.26
    */
    //向量和标量相加赋值
    VectorT<N,T>& operator +=(const T& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]+=v;
        return *this;
    }
    VectorT<N,T> operator +(const T& v)
    {
        VectorT<N,T> temp(*this);
        return temp+=v;
    }
    VectorT<N,T>& operator -=(const T& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]-=v;
        return *this;
    }
    VectorT<N,T> operator - (const T& v)
    {
        VectorT<N,T> temp(*this);
        return temp-=v;
    }
    VectorT<N,T>& operator *= (const T& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]*=v;
        return *this;
    }
    VectorT<N,T> operator * (const T& v)
    {
        VectorT<N,T> temp(*this);
        return temp*=v;
    }
    VectorT<N,T>& operator /= (const T& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]/=v;
        return *this;
    }
    VectorT<N,T> operator / (const T& v)
    {
        VectorT<N,T> temp(*this);
        return temp/=v;
    }
    /********************* Vector operation *********************/
    VectorT<N,T>& operator+=(const VectorT<N,T>& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]+=v.value_[i];
        return *this;
    }
    VectorT<N,T>& operator-=(const VectorT<N,T>& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]-=v.value_[i];
        return *this;
    }
    VectorT<N,T>& operator*=(const VectorT<N,T>& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]*=v.value_[i];
        return *this;
    }
    VectorT<N,T>& operator/=(const VectorT<N,T>& v)
    {
        for(size_t i=0;i<N;i++)
            value_[i]/=v.value_[i];
        return *this;
    }
    //取反运算
    VectorT<N,T> operator -()
    {
        VectorT<N,T> result;
        for(size_t i=0;i<N;i++)
            result[i]=-value_[i];
        return result;
    }
    //**********************Norm***************************************/
    T sqrnorm() const
    {
        T temp = value_[0] * value_[0];
        for (size_t i = 1; i < N; i++)
            temp += value_[i] * value_[i];
        return temp;
    }
    T l1_norm() const
    {
        return sum_abs();
    }
    T l2_norm() const
    {
        return sqrt(sqrnorm());
    }
    T norm() const
    {
        return sqrt(sqrnorm());
    }
    T length() const
    {
        return norm();
    }
    VectorT<N,T>& normalize()
    {
        return  *this/norm();
    }
    //**********************Sum,Max,Min,Mean*****************************************/
    T sum() const
    {
        T temp(value_[0]);
        for(size_t i=1;i<N;i++)
            temp+=value_[i];
        return temp;
    }
    T sum_abs() const
    {
        T temp(fabs(value_[0]));
        for(size_t i=1;i<N;i++)
            temp+=fabs(value_[i]);
        return temp;
    }
    T abs()
    {
        for(size_t i=0;i<N;i++)
        {
            value_[i]=fabs(value_[i]);
        }
    }
    T max() const
    {
        T m(value_[0]);
        for(size_t i=1;i<N;i++)
            if(m<value_[i])
                m=value_[i];
        return m;
    }
    T max_abs() const
    {
        T m(fabs(value_[0]));
        for(size_t i=1;i<N;i++)
            if(m<fabs(value_[i]))
                m=fabs(value_[i]);
        return m;
    }

    T min() const
    {
        T m(value_[0]);
        for(size_t i=1;i<N;i++)
            if(m>value_[i])
                m=value_[i];
        return m;
    }
    T min_abs() const
    {
        T m(fabs(value_[0]));
        for(size_t i=1;i<N;i++)
            if(m>fabs(value_[i]))
                m=fabs(value_[i]);
        return m;
    }
    T mean() const
    {
        return sum()/T(N);
    }
    T mean_abs() const
    {
        return sum_abs()/T(N);
    }
    /*****************Other tools*****************************/
    //2015-3-7 by zhanghx
    //正交向量return orthogonal vector according current vector
    VectorT<N,T> orthogonal_vector() const
    {
        //Todo why select 0.9
        //Todo
        // Find smallest component. Keep equal case for null values.
        if(N==3)
        {
            if ((std::fabs(value_[1]) >= 0.9*std::fabs(value_[0])) && (std::fabs(value_[2]) >= 0.9*std::fabs(value_[0])))
              return VectorT<3,T>(0.0, -value_[2], value_[1]);
            else
              if ((std::fabs(value_[0]) >= 0.9*std::fabs(value_[1])) && (std::fabs(value_[2]) >= 0.9*std::fabs(value_[1])))
                return VectorT<3,T>(-value_[2], 0.0, value_[0]);
              else
                return VectorT<3,T>(-value_[1], value_[0], 0.0);
        }
        else
        {
            return VectorT<N,T>();
        }
    }

private:
    T value_[N];
};

 /********************运算*********************************************/
//两向量相加
//return const because avoid return object sever as left value such as (a+b)=c
template <size_t N,typename T>
const VectorT<N,T> operator+(const VectorT<N,T>& v1,const VectorT<N,T>& v2)
{
    VectorT<N,T> result;
    for (size_t i = 0; i < N; i++)
        result[i] = v1[i] + v2[i];
    return result;
}

//两向量相减
template <size_t N,typename T>
const VectorT<N,T> operator - (const VectorT<N,T>& v1,const VectorT<N,T>& v2)
{
    VectorT<N,T> result;
    for (size_t i = 0; i < N; i++)
        result[i] = v1[i] - v2[i];
    return result;
}
//两向量相乘
template <size_t N,typename T>
const VectorT<N,T> operator * (const VectorT<N,T>& v1,const VectorT<N,T>& v2)
{
    VectorT<N,T> result;
    for (size_t i = 0; i < N; i++)
        result[i] = v1[i] * v2[i];
    return result;
}
//两向量相除
template <size_t N,typename T>
const VectorT<N,T> operator / (const VectorT<N,T>& v1,const VectorT<N,T>& v2)
{
    VectorT<N,T> result;
    for (size_t i = 0; i < N; i++)
        result[i] = v1[i] / v2[i];
    return result;
}
//点积
template <size_t N, typename T>
T operator ^ (const VectorT<N,T> &v1, const VectorT<N,T> &v2)
{
    T sum = v1[0] * v2[0];
    for (size_t i = 1; i < N; i++)
        sum += v1[i] * v2[i];
    return sum;
}
#define DOT ^

//叉积－只限于三维向量
template <class T>
VectorT<3,T> operator % (const VectorT<3,T> &v1, const VectorT<3,T> &v2)
{
    return VectorT<3,T>(v1[1]*v2[2] - v1[2]*v2[1],
                        v1[2]*v2[0] - v1[0]*v2[2],
                        v1[0]*v2[1] - v1[1]*v2[0]);
}
#define CROSS %




//Iostream Operator
template <size_t N,typename T>
inline std::ostream& operator << (std::ostream &os,const VectorT<N,T> &v)
{
    os << "(";
    for (size_t i = 0; i < N-1; i++)
        os << v[i] << ", ";
    return os << v[N-1] << ")";
}
template <size_t N, typename T>
inline std::istream &operator >> (::std::istream &is, VectorT<N,T> &v)
{
    using namespace ::std;
    char c1 = 0, c2 = 0;

    is >> c1;
    if (c1 == '(' || c1 == '[') {
        is >> v[0] >> ws >> c2;
        for (size_t i = 1; i < N; i++) {
            if (c2 == ',')
                is >> v[i] >> ws >> c2;
            else
                is.setstate(ios::failbit);
        }
    }

    if (c1 == '(' && c2 != ')')
        is.setstate(ios::failbit);
    else if (c1 == '[' && c2 != ']')
        is.setstate(ios::failbit);

    return is;
}

//向量的常用函数
// Angle between two vectors
template <size_t N, typename T>
const T angle(const VectorT<N,T> &v1, const VectorT<N,T> &v2)
{
    using namespace ::std;
    return atan2((v1 CROSS v2).length(), v1 DOT v2);
}
//---------------------常用类型定义-----------------------------------
typedef VectorT<2,unsigned short> Vector2us;
typedef VectorT<2,unsigned int>   Vector2ui;
typedef VectorT<2,unsigned long>  Vector2ul;
typedef VectorT<2,short>          Vector2s;
typedef VectorT<2,int>            Vector2i;
typedef VectorT<2,long>           Vector2l;
typedef VectorT<2,float>          Vector2f;
typedef VectorT<2,double>	      Vector2d;

typedef VectorT<3,unsigned short> Vector3us;
typedef VectorT<3,unsigned int>   Vector3ui;
typedef VectorT<3,unsigned long>  Vector3ul;
typedef VectorT<3,short>          Vector3s;
typedef VectorT<3,int>            Vector3i;
typedef VectorT<3,long>           Vector3l;
typedef VectorT<3,float>          Vector3f;
typedef VectorT<3,double>	      Vector3d;


typedef VectorT<4,unsigned short> Vector4us;
typedef VectorT<4,unsigned int>   Vector4ui;
typedef VectorT<4,unsigned long>  Vector4ul;
typedef VectorT<4,short>          Vector4s;
typedef VectorT<4,int>            Vector4i;
typedef VectorT<4,long>           Vector4l;
typedef VectorT<4,float>          Vector4f;
typedef VectorT<4,double>	      Vector4d;


}//end of namespace Magine

#endif
