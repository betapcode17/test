//Định nghĩa hàm thành viên
#include<iostream>
#include "point.h"
using namespace std;
Point::Point(int xval, int yval)
{
    this->xVal = xVal;
    this->yVal = yval;
}
Point::Point(const Point & p):xVal(p.xVal),yVal(p.yVal)
{
}
Point ::~Point()
{
}
// con trỏ this là của thằng đứng trước toán hạng
//hàm thành viên nên số toán tử -1
Point Point::operator-(const Point& p){
   Point q(this->xVal-p.xVal,this->yVal-p.yVal);
   return q;
}

void Point::show()
{
    cout<<this->xVal<<" ,"<<this->yVal<<endl;
}
// thứ tự truyền tham số từ trái sang phải
// nếu đổi vị trí
/*ostream& operator<<(ostream& o,const Point& p){
    o << p.xVal<<", "<<p.yVal<<endl;
    return o;
}*/
// toán tử nhập xuất chỉ được đa năng hóa bằng hàm toàn cục
// ostream& operator<<(ostream& o,const Point& p){
//     o << p.xVal<<", "<<p.yVal<<endl;
//     return o;
// }
istream& operator>>(istream& i, Point& p){
    cout<<"xVal= ";
    i >> p.xVal;
    cout<<"xVal= ";
    i>>p.yVal;
    return i;
}
