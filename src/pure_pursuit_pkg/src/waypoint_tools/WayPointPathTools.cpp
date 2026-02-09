#include <iostream>

#include "pure_pursuit_pkg/WayPointPathTools.hpp"


	WayPointPathTools::WayPointPathTools(pure_pursuit_pkg::msg::WayPointPath path_points, double l)
        : path{path_points}, L{l} {}
        
        geometry_msgs::msg::Point WayPointPathTools::findClosestPointOnPath(double *dClosest, double x_rob, double y_rob)
        {
            geometry_msgs::msg::Point pClosest;
            int N=this->path.points.size();
            *dClosest=1000000;
            double dLClosest = 1000000;
            geometry_msgs::msg::Point pi; //Robot position
            pi.x=x_rob;
            pi.y=y_rob;
            if (path.closed_path.data)
            {
                for (int i=0;i<N;i++)
                {
                    geometry_msgs::msg::Point p;
                    double d;
                    double dL;
    
                    p=this->p2sLookAheadDistance(path.points[i],path.points[(i+1)%N],pi,&d);
                    dL=abs(d-L);
                    if (dL<dLClosest)
                    {
                        pClosest=p;
                        *dClosest=d;
                        dLClosest = dL;
                    }
                }
            }
            else
            {
                for (int i=0;i<(N-1);i++)
                {
                    geometry_msgs::msg::Point p;
                    double d;
                    double dL;
                    p=this->p2sLookAheadDistance(path.points[i],path.points[i+1],pi,&d);
                    dL=abs(d-L);
    
                    if (dL<dLClosest)
                    {
                        pClosest=p;
                        *dClosest=d;
                        dLClosest = dL;
    
                    }
                }
            }
            return pClosest;
        
        }

    geometry_msgs::msg::Point WayPointPathTools::p2sLookAheadDistance(const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2, const geometry_msgs::msg::Point& pi, double *d)
	{
		geometry_msgs::msg::Point p;
		geometry_msgs::msg::Point v;
		v.x=p2.x-p1.x;
		v.y=p2.y-p1.y;
		double v2=pow(v.x,2)+pow(v.y,2);
		geometry_msgs::msg::Point p1pi;
		p1pi.x=p1.x-pi.x;
		p1pi.y=p1.y-pi.y;
		double p1pi2L=pow(p1pi.x,2)+pow(p1pi.y,2)-pow(L,2);
		double vp1pi=v.x*p1pi.x+v.y*p1pi.y;
		double a0=4*pow(v2,2);
		double a1=12*v2*vp1pi;
		double a2=4*v2*p1pi2L+8*pow(vp1pi,2);
		double a3=4*vp1pi*p1pi2L;
		std::cout << a0 <<" "<< a1 << " " << a2 << " " << a3 << std::endl;
		std::vector<double> lambda;
		lambda=this->calculateRoots(a0,a1,a2,a3);

		std::vector<double>::iterator it;
		double selected_lambda=0.0;
		for (it=lambda.begin();it!=lambda.end();it++)
		{
			if (*it>selected_lambda)
			{
				selected_lambda=*it;
			}
		}
		p.x=v.x*selected_lambda+p1.x;
		p.y=v.y*selected_lambda+p1.y;
		*d=sqrt(pow(p.x-pi.x,2)+pow(p.y-pi.y,2));
		return p;
	}

    std::vector<double> WayPointPathTools::calculateRoots(const double &a0,const double &a1,const double &a2,const double &a3)
	{
		std::vector<double> roots;
		if (fabs(a0)<1e-8) {
			if (fabs(a1)<1e-8) {
				if (fabs(a3)<1e-8) {
					return roots;
				} else {
					roots.push_back(std::max(std::min(-a3/a2,1.0),0.0));
					return roots;
				}
			}
			double discriminant = a2 * a2 - 4 * a1 * a3;
			if (discriminant > 0) {
				roots.push_back(std::max(std::min((-a2 + sqrt(discriminant)) / (2 * a1),1.0),0.0));
				roots.push_back(std::max(std::min((-a2 - sqrt(discriminant)) / (2 * a1),1.0),0.0));
			} else if (discriminant == 0) {
				roots.push_back(std::max(std::min(-a2 / (2 * a1),1.0),0.0));
			}
			return roots;
		}
		double A = a1 / a0;
		double B = a2 / a0;
		double C = a3 / a0;

		
		double Q = (3 * B - pow(A, 2)) / 9;
		double R = (9 * A * B - 27 * C - 2 * pow(A, 3)) / 54;
		double D = pow(Q, 3) + pow(R, 2);
		
		double offset = A / 3.0;
		
		if (D > 0.0) {
			double S = cbrt(R + sqrt(D));
			double T = cbrt(R - sqrt(D));
			roots.push_back(S + T - offset);
		} else if (D==0) {
			double S = cbrt(R);
			roots.push_back(std::max(std::min(2 * S - offset,1.0),0.0));
			roots.push_back(std::max(std::min(-S - offset,1.0),0.0));

		} else {
			double theta = acos(R / sqrt(-pow(Q, 3)));
			double sqrtQ = sqrt(-Q);
			roots.push_back(std::max(std::min(2 * sqrtQ * cos(theta / 3) - offset,1.0),0.0));
			roots.push_back(std::max(std::min(2 * sqrtQ * cos((theta + 2 * M_PI) / 3) - offset,1.0),0.0));
			roots.push_back(std::max(std::min(2 * sqrtQ * cos((theta + 4 * M_PI) / 3) - offset,1.0),0.0));
		}
		return roots;
	}