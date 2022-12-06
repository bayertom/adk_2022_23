#include "algorithms.h"
#include <cmath>

Algorithms::Algorithms()
{    
}


double Algorithms::getEuclDistance(double x1,double y1,double x2,double y2)
{
    // Euclidean distance
    double dx = x1-x2;
    double dy = y1-y2;
    return sqrt(dx*dx + dy*dy);
}


std::tuple<double, double, double> Algorithms::getPointLineDistance(double x, double y, double x1, double y1, double x2, double y2)
{
    // Point and line distance
    double d12 = getEuclDistance(x1, y1, x2, y2);

    //Distance point p and line (p1, p2)
    double dist = (x*(y1 - y2) + x1*(y2 - y) + x2*(y - y1))/d12;

    //Coordinates of the point on (p1, p2) nearest to p
    double d1 = getEuclDistance(x1,y1,x,y);
    double k = sqrt(d1*d1-dist*dist);

    double rx = x1 + k*(x2-x1)/d12;
    double ry = y1 + k*(y2-y2)/d12;

    return {dist, rx, ry};
}


std::tuple<double, double, double> Algorithms::getPointLineSegmentDistance(double x, double y, double x1, double y1, double x2, double y2)
{
    // Point and line segment distance
    double ux = x2 - x1;
    double uy = y2 - y1;

    // Normal vector
    double nx = uy;
    double ny = -ux;

    //Supplementary point P3, P4
    double x3 = x1 + nx;
    double y3 = y1 + ny;
    double x4 = x2 + nx;
    double y4 = y2 + ny;

    // Position Q to P1,P3
    auto [dqp13, xi1, yi1] = getPointLineDistance(x, y, x1, y1, x3, y3);
    auto [dqp24, xi2, yi2] = getPointLineDistance(x, y, x2, y2, x4, y4);
    double crit = dqp13 * dqp24;

    // Point Q and line (P1, P2) distance
    if (crit < 0)
    {
        auto [d, xi, yi] = getPointLineDistance(x, y, x1, y1, x2, y2);
        return {d, xi, yi};
    }
    // Point Q left from P1, P3
    if (dqp13 > 0)
        return {getEuclDistance(x, y, x1, y1), x1, y1};

    // Point Q left from P2, P4
    return {getEuclDistance(x, y, x2, y2), x2, y2};
}


std::tuple<int, double, double, double> Algorithms::getNearestLineSegmentPoint(double xq, double yq, Matrix &X, Matrix &Y)
{
     //Get nearest point and its coordinates
    int imin = -1;
    double dmin = 1.0e10;
    double xn, yn;

    auto [m,n] = X.size();

    //Browse all points
    for (int i = 0; i < m; i++)
    {
        //Compute distance
        auto [d, xi, yi] = getPointLineSegmentDistance(xq, yq, X(i, 0), Y(i, 0), X(i+1, 0), Y(i+1, 0));

        //Actualize minimum
        if (d < dmin)
        {
                dmin = d;
                imin = i;
                xn = xi;
                yn = yi;
        }
    }
    return {imin, dmin, xn, yn};
}


Matrix Algorithms::createA(double alfa, double beta, double gamma, double h, int n)
{
    // Create definition atrix of spline of minimum energy spline
    double h2= h*h;
    double h4 = h2*h2;

    double a = alfa + 2*beta/h2 + 6*gamma/h4;
    double b = - beta/h2 - 4*gamma/h4;
    double c = gamma/h4;

    //Create matrix A
    Matrix A(n,n);

    for (int i = 0; i<n; i++)
    {
        //main diagonal
        A(i,i) = a;

        //Non-diagonal elements
        if(i<n-1)
        {
            A(i,i+1) = b;
            A(i+1,i) = b;
        }

        //Non-diagonal elements
        if(i<n-2)
        {
            A(i,i+2) = c;
            A(i+2,i) = c;
        }
    }
    return A;
}


std::vector<QPointF> Algorithms::minEnergySpline1Element1Barrier(std::vector<QPointF> element,std::vector<QPointF> barrier, double alfa, double beta, double gamma, double lambda, double dmin, int iter)
{
    //Create minimum energy spline: 1 simplified element, 1 barrier
    int ne = element.size();
    int nb = barrier.size();

    //Create supplementary matrices
    Matrix Xe(ne,1), Ye(ne,1);
    Matrix Xb(nb,1), Yb(nb,1);

    //Initaliaze Xe, Ye matrices
    for(int i = 0; i<ne; i++)
    {
        Xe(i,0)=element[i].x();
        Ye(i,0)=element[i].y();
    }

    //Initaliaze Xb, Yb matrices
    for(int i = 0; i<nb; i++)
    {
        Xb(i,0)=barrier[i].x();
        Yb(i,0)=barrier[i].y();
    }

    // Coordinate differencies and step
    Matrix hX = Xe.diff();
    Matrix hY = Ye.diff();
    Matrix hXY = (hX|hX + hY|hY).sqrtm(); //Hadamard product .*
    double h = hXY.mean();

    //create matrix A
    Matrix A = createA(alfa, beta, gamma, h, ne);

    //Create inverse matrix
    Matrix I(ne,ne,0,1);
    Matrix AI = (A + lambda * I).inv();

    // Coordinate differencies
    Matrix DXe(ne,1), DYe(ne,1);

    //Main iteration    
    Matrix Xei = Xe , Yei = Ye;

    for(int i=0; i < iter; i++)
    {
        // Outer energy matrices
        Matrix Ex(ne,1), Ey(ne,1);

        // Partial derivatives of energy according to X, Y
        for(int j=1; j < ne-1; j++)
        {
            // Point nearest to Xej, Yej in Xb, Yb
            auto[in, xn, yn, dn]=getNearestLineSegmentPoint(Xei(j,0), Yei(j,0), Xb, Yb);

            // Partial derivative of energy accroding to x
            double ex = getEx(Xei(j,0), Yei(j,0), xn, yn, dmin);

            // Partial derivative of energy accroding to y
            double ey = getEy(Xei(j,0), Yei(j,0), xn, yn, dmin);

            // Set derivatives to energy matrices
            Ex(j,0)=ex;
            Ey(j,0)=ey;
        }

        // Compute shifts
        DXe = AI*(lambda*DXe-Ex);
        DYe = AI*(lambda*DYe-Ey);

        // New vertices
        Xei = Xe + DXe;
        Yei = Ye + DYe;
    }

    // Convert matrix representations into polyline
    std::vector<QPointF>displaced;
    for(int i=0; i<ne; i++)
    {
        QPointF p(Xei(i,0),Yei(i,0));
        displaced.push_back(p);
    }

    return displaced;
}


double Algorithms::getEx(double x, double y, double xn, double yn, double dmin)
{
    // Partial derivative according of outer energy to x
    double c = 2*dmin;

    double d = getEuclDistance(x,y,xn,yn);

    if (d < dmin)
       return -c*(x-xn)/(d*dmin);

    return 0;
}


double Algorithms::getEy(double x, double y, double xn, double yn, double dmin)
{
    // Partial derivative according of outer energy to x
    double c = 2*dmin;

    double d = getEuclDistance(x,y,xn,yn);

    if (d < dmin)
       return -c*(y-yn)/(d*dmin);

    return 0;
}






