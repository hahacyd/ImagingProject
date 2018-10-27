#ifndef COMMONGRAPHICS_H
#define COMMONGRAPHICS_H
#include<QPainter>


class GShape{   //this is other derived class's parent class;
public:
    GShape(QPainter *tpainter);
    //virtual void drawItem();
    virtual void drawItem(int originx,int originy,int r){}
    virtual void drawItem(int x,int y,int ra,int rb){}

    virtual ~GShape(){}
    void setXY(int x,int y);

protected:

    QPainter* painter;
    int locx,locy;

};

class GCircle:public GShape{
public:
    GCircle(QPainter *tpainter):GShape(tpainter){}
    void drawItem(int originx,int originy,int r);


    double fCircle(double x,double y);
    void setR(int r);
private:
    int R;
};
class GEllipse:public GShape{
public:
    GEllipse(QPainter* tpainter):GShape(tpainter){}
    void drawItem(int x,int y,int ra,int rb);


    void setAB(int a,int b);   //set major axis and minor axis;
    double fEllipse(double x,double y);
private:
    int Rx,Ry;
};


#endif // COMMONGRAPHICS_H
