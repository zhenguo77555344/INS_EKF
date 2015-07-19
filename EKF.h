//
//  EKF.h
//  INS_EKF
//
//  Created by Louis Faury on 13/07/2015.
//  Copyright (c) 2015 Louis Faury. All rights reserved.
//

#ifndef __INS_EKF__EKF__
#define __INS_EKF__EKF__

#include <stdio.h>
#include "/usr/include/Eigen/Dense"
#include <iostream>
#include <string>


class EKF{
    
    typedef Eigen::Matrix<float,10,1> Vector10f;
    typedef Eigen::Matrix<float, 10, 10> Matrix10f;
    
public:
    
    
    EKF();
    
   /* \brief Initialize the state vector
    * \brief WARNING : For now, initialize in the inertial frame
    * \brief Position, speed and quaternion
    */
    void init_state_vector();
    
    Vector10f get_state_vector();
    
    void build_jacobian_matrix(Eigen::Vector3f*, Eigen::Vector3f*);
    
    void predict(); //TODO
    
    void correct(); //TODO
    
    ~EKF(); //TODO
    

    
    
    
    
    
private:
    
    Vector10f X; // The state vector
    Matrix10f J; // The jacobian Matrix for integration of inertial datas
    const double dt = 0.05; // Samplimp time in seconds
    
    
    
};

#endif /* defined(__INS_EKF__EKF__) */