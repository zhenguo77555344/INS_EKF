# How Kalman filter works

## 1. Some words in the beginning
I would like to summarize one document about the Kalman filter,because what it does is realy amazing.Only few software engineers seem to know about it,and many of them consider it as a module can be copied from others project or some of them take it as complex math related tool.Both of the above situation made me sad,because it is such a general and powerful tool for combining information in the presence of uncertainty, such as sensor fusion field.

## 2. What Kalman filter is
Any dynamic system,which has uncertain information can be made an educated guess about how the system is going to do in the following time step by Kalman filter or derivation version of Kalman filter,such as EKF/UKF.If you could understand the basic Kalman filter's idear,it will be easy to learn other derivation version.

Kalman filters are ideal for systems which are continuously changing. They have the advantage that they are light on memory (they don’t need to keep any history other than the previous state), and they are very fast, making them well suited for real time problems and embedded systems.

The math for implementing the Kalman filter appears pretty scary and opaque in most places you find on website such as google. That’s a bad state of affairs, because the Kalman filter is actually super simple and easy to understand if you look at it in the right way. Thus it makes a great article topic, and I will attempt to illuminate it with lots of clear, pretty pictures and colors. The prerequisites are simple; all you need is a basic understanding of probability and matrices.

I’ll start with a loose example of the kind of thing a Kalman filter can solve.

## 3. What can we do using Kalman filter
Let’s make a toy example: You’ve built a little robot that can wander around in the woods, and the robot needs to know exactly where it is so that it can navigate.

<img src="https://www.bzarg.com/wp-content/uploads/2015/08/robot_forest-300x160.png" width="300" height="160" align="center"/>

We’ll say our robot has a state xk, which is just a position and a velocity:
    xk=(p⃗ ,v⃗ )
Note that the state is just a list of numbers about the underlying configuration of your system; it could be anything. In our example it’s position and velocity, but it could be data about the amount of fluid in a tank, the temperature of a car engine, the position of a user’s finger on a touchpad, or any number of things you need to keep track of.

Our robot also has a GPS sensor, which is accurate to about 10 meters, which is good, but it needs to know its location more precisely than 10 meters. There are lots of gullies and cliffs in these woods, and if the robot is wrong by more than a few feet, it could fall off a cliff. So GPS by itself is not good enough

<img src="https://www.bzarg.com/wp-content/uploads/2015/08/robot_ohnoes.png"align="center" width="300" height="160">

We might also know something about how the robot moves: It knows the commands sent to the wheel motors, and its knows that if it’s headed in one direction and nothing interferes, at the next instant it will likely be further along that same direction. But of course it doesn’t know everything about its motion: It might be buffeted by the wind, the wheels might slip a little bit, or roll over bumpy terrain; so the amount the wheels have turned might not exactly represent how far the robot has actually traveled, and the prediction won’t be perfect.

The GPS sensor tells us something about the state, but only indirectly, and with some uncertainty or inaccuracy. Our prediction tells us something about how the robot is moving, but only indirectly, and with some uncertainty or inaccuracy.

But if we use all the information available to us, can we get a better answer than either estimate would give us by itself? Of course the answer is yes, and that’s what a Kalman filter is for.

## 4. How Kalman filter sees our problem

Let us look at the landscape we are trying to interpret.We will continue with the simple state having only position and velocity.
We don't know what the actual position and velocity are;there are a whole range of possible combinations of position and velocity that might be true,but some of them are more likely than others.
<img src="https://www.bzarg.com/wp-content/uploads/2015/08/gauss_0.png" align="center" width="300",height="160">

The Kalman filter assumes that both position and velocity are random and Gauusian distributed.Each variable has a mean value μ, which is the center of the random distribution (and its most likely state), and a variance σ2, which is the uncertainty

<img src="https://www.bzarg.com/wp-content/uploads/2015/08/gauss_1.png" align="center" width="300",height="160">

In the above picture, position and velocity are uncorrelated, which means that the state of one variable tells you nothing about what the other might be.

The example below shows something more interesting: Position and velocity are correlated. The likelihood of observing a particular position depends on what velocity you have:

<img src="https://www.bzarg.com/wp-content/uploads/2015/08/gauss_3.png" align="center" width="300",height="160">

This kind of situation might arise if, for example, we are estimating a new position based on an old one. If our velocity was high, we probably moved farther, so our position will be more distant. If we’re moving slowly, we didn’t get as far.

This kind of relationship is really important to keep track of, because it gives us more information: One measurement tells us something about what the others could be. And that’s the goal of the Kalman filter, we want to squeeze as much information from our uncertain measurements as we possibly can!

This correlation is captured by something called a covariance matrix. In short, each element of the matrix Σij is the degree of correlation between the ith state variable and the jth state variable. (You might be able to guess that the covariance matrix is symmetric, which means that it doesn’t matter if you swap i and j). Covariance matrices are often labelled “Σ”, so we call their elements “Σij”.

<img src="https://www.bzarg.com/wp-content/uploads/2015/08/gauss_2.png" align="center" width="300",height="160">

Rome was not built in one day,so does the way learn Kalman filter.
Let us take a break and think about the following question:
which one can be covariance matrix in Kalman filter:

A:{[1,2];[3,4]} 
B:{[1,0];[0,1]}

## Kalman filter instance: GNSS/INS fusion


Program reading from log files implementing an extended Kalman filter for the inertial navigation.

To compile, you'll need to install the Eigen library. Simply go on their website to download it and then run : 

        sudo -s
        mv Eigen/ /usr/include


You'll then simply need to run : 

        make && make clean 

The 'make clean' command being optional. 

You'll need to change the path to the log you want to treat, log that would have been stored thanks to the APM_READER programm. 

