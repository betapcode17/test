#include <iostream>
#include "Matrix.h"
Matrix::Matrix(int r,int c,int t){
    this->r=r;
    this->c=c;
    this->p = new int*[this->r];
    for(int i =0;i<this->r;i++){
        *(this->p+i)= new int[this->c];
        for(int j=0;j<this->c;j++){
            *(*(this->p+i)+j)=t;
        }
    }
}
Matrix::~Matrix(){
    for(int i=0;i<this->r;i++){
        delete[] *(this->p+i);
    }
    delete[] p;
}

ostream &operator<<(ostream &o,  Matrix &M)
{
    for(int i=0;i<M.r;++i){
        for(int j=0;j<M.c;++j){
           // o<<*(*(M.p+i)+j)<<" ";
           o<<M(i,j);
        }
        o<<endl;   
    }
    return o;
}
//m(i,j)
int &Matrix::operator()(const int &i, const int &j)
{
    static int data = -1;
    if(i>=0 && i< this->r && j>=0 && j<this->c)
    return *(*(this->p+i)+j);
    else
    return data;
}