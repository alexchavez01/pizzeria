//
// Created by Sofia Visa on 11/28/21.
//

#ifndef JURASSICMOUNTAINS_TRIANGLE_HPP
#define JURASSICMOUNTAINS_TRIANGLE_HPP
class Triangle {
private:
    double sideLen;
public:
    Triangle(double side);
    Triangle();

    double getArea() const;
    void setSide(double s);
    double getSideLen() const;
};

Triangle::Triangle(double side){
    sideLen = side;
}

Triangle::Triangle(){
    sideLen = 1000;
}

double Triangle::getArea() const{
    return (sideLen * sideLen * sqrt(3) / 4);
}

double Triangle::getSideLen() const{
    return sideLen;
}

void Triangle::setSide(double s){
    sideLen = s;
}
#endif //JURASSICMOUNTAINS_TRIANGLE_HPP
