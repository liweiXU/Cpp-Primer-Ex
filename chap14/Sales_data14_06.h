#ifndef SALES_DATA14_06_H
#define SALES_DATA14_06_H
 
 
#include <iostream>
#include <string>
 
class Sales_data
{
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend bool operator<(const Sales_data&, const Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
 
public:
    Sales_data() = default;
    Sales_data(const std::string &book): bookNo(book) {  }
    Sales_data(std::istream &is) { is >> *this; }
 
public:
    Sales_data& operator+=(const Sales_data&);
    std::string isbn() const { return bookNo; }
    double avg_price() const;
 
private:
    std::string bookNo;                 //书号
    unsigned units_sold = 0;            //出售册数
    double revenue = 0.0;               //收入
};
 
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}
 
Sales_data operator+(const Sales_data&, const Sales_data&);
 
inline bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return (lhs.units_sold == rhs.units_sold) &&
           (lhs.revenue == rhs.revenue) &&
           (lhs.isbn() == rhs.isbn());
}
 
inline bool operator !=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}
 
Sales_data& Sales_data::operator +=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
 
Sales_data operator +(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}
 
std::istream& operator>>(std::istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
 
    if(in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_data();
 
    return in;
}
 
std::ostream& operator <<(std::ostream& out, const Sales_data& s)
{
    const char sep = '\t';
    out << "\n\t" << s.isbn() << sep << s.units_sold << sep
        << s.revenue << sep << s.avg_price();
 
    return out;
}
 
double Sales_data::avg_price() const
{
    if(units_sold)
        return revenue / units_sold;
    else
        return 0;
}
 
#endif // SALES_DATA14_06_H