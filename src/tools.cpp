#include <iostream>
#include "tools.h"

using namespace std;
using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
	VectorXd rmse(4);
	rmse << 0,0,0,0;

    if (estimations.size() == 0 || estimations.size() != ground_truth.size()) {
        cout << "invalid inputs for RMSE" << endl;
    }

	//accumulate squared residuals
	for(int i=0; i < estimations.size(); ++i){
	    VectorXd resid = estimations[i] - ground_truth[i];
	    VectorXd sq_resid = resid.array() * resid.array();
	    rmse += sq_resid;
	}
    
	//calculate the mean
	rmse = rmse.array() / estimations.size();

	//calculate the squared root
	rmse = rmse.array().sqrt();

	//return the result
	return rmse;
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
	MatrixXd Hj(3,4);
	//recover state parameters
	float px = x_state(0);
	float py = x_state(1);
	float vx = x_state(2);
	float vy = x_state(3);

	//pre-compute a set of terms to avoid repeated calculation
	float dem1 = px*px+py*py;
	float dem2 = sqrt(dem1);
	float dem3 = (dem1*dem2);

	//check division by zero
	if(fabs(dem1) < 0.0001){
		cout << "CalculateJacobian () - Error - Division by Zero" << endl;
		Hj << 1e-9, 1e-9, 1e-9, 1e-9,
		      1e-9, 1e-9, 1e-9, 1e-9,
		      1e-9, 1e-9, 1e-9, 1e-9;
		return Hj;
	}

	//compute the Jacobian matrix
	Hj << (px/dem2), (py/dem2), 0, 0,
		  -(py/dem1), (px/dem1), 0, 0,
		  py*(vx*py - vy*px)/dem3, px*(px*vy - py*vx)/dem3, px/dem2, py/dem2;

	return Hj;
}
