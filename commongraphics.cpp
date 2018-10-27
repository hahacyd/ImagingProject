#include"commongraphics.h"
GShape::GShape(QPainter* tpainter):painter(tpainter){

}
void GCircle::setR(int r){
    R = r;
}
void GShape::setXY(int x,int y){
   locx = x;
   locy = y;
}
void GCircle::drawItem(int ox,int oy,int r){
    setR(r);   //save the circle's radius;
    setXY(ox,oy);


    double p = 0;
    int x = 0,y = 0 + r;
    painter->drawPoint(locx,locy);
    painter->drawPoint(locx,locy + r);
    while(y > x){
        p = fCircle(x,double(y) - 1/2);
        if(p < 0){
            //nexty = y;
        }
        else{
            y = y - 1;
        }

        painter->drawPoint(locx+x,locy+y);
        painter->drawPoint(locx-x,locy+y);
        painter->drawPoint(locx+x,locy-y);
        painter->drawPoint(locx-x,locy-y);
        painter->drawPoint(locx+y,locy+x);
        painter->drawPoint(locx+y,locy-x);
        painter->drawPoint(locx-y,locy+x);
        painter->drawPoint(locx-y,locy-x);

        x = x + 1;
    }
}
double GCircle::fCircle(double x,double y){
    return x*x + y*y - R*R;
}

double GEllipse::fEllipse(double x,double y){
    return pow(x,2)*pow(Ry,2) + pow(y,2)*pow(Rx,2) - pow(Rx,2)*pow(Ry,2);

}
void GEllipse::drawItem(int lx,int ly,int rx,int ry){
    setXY(lx,ly);

    setAB(rx,ry);
    int x = 0,y = 0 + ry;

    //first paint area 1
    double p0 = 0.0;
    double ek = 0.0;
    ek = fabs(pow(ry,2) * x / (pow(rx,2) * y));
    while(ek < 1){
        p0 = fEllipse(x+1,double(y) - 1/2);
        if(p0 < 0){
            //p0 = p0 + 2*pow(ry,2)*x + 3*pow(ry,2);
        }
        else{
            //p0 = p0 + 2*pow(ry,2)*x -2*pow(rx,2)*y + 2*pow(rx,2)+ 3*pow(ry,2);
            y -= 1;
        }
        x++;

        painter->drawPoint(lx+x,ly+y);
        painter->drawPoint(lx-x,ly+y);
        painter->drawPoint(lx+x,ly-y);
        painter->drawPoint(lx-x,ly-y);
        ek = fabs(pow(ry,2) * x / (pow(rx,2) * y));
    }


    //second paint area 2
    while(y > 0){
        p0 = fEllipse(double(x) + 1/2,y - 1);
        if(p0 < 0){
            x++;

        }
        else{
        }
        y -= 1;
        painter->drawPoint(lx+x,ly+y);
        painter->drawPoint(lx-x,ly+y);
        painter->drawPoint(lx+x,ly-y);
        painter->drawPoint(lx-x,ly-y);
    }
}
void GEllipse::setAB(int a,int b){
    Rx = a;
    Ry = b;
}
/**/
