
**Extended Kalman Filter Project**

The goals / steps of this project are the following:

* Complete the code for an 2D extended Kalman Filter for pedestrian tracking
* Run the code on some sample data to check RMSE values
* Compute the camera calibration matrix and distortion coefficients given a set of chessboard images.
* Apply a distortion correction to raw images.
* Use color transforms, gradients, etc., to create a thresholded binary image.
* Apply a perspective transform to rectify binary image ("birds-eye view").
* Detect lane pixels and fit to find the lane boundary.
* Determine the curvature of the lane and vehicle position with respect to center.
* Warp the detected lane boundaries back onto the original image.
* Output visual display of the lane boundaries and numerical estimation of lane curvature and vehicle position.

[//]: # (Image References)

[sample_data1]: ./output_images/sample_data1.png "Sample Data 1"
[sample_data2]: ./output_images/sample_data2.png "Sample Data 2"

## [Rubric](https://review.udacity.com/#!/rubrics/748/view) Points

---

###Results
Results for Sample Data 1:
	Accuracy - RMSE:
	0.0646304
	0.0602318
	0.499182
	0.537062

![alt text][sample_data1]


Results for Sample Data 2:
	Accuracy - RMSE:
	0.195953 - X position
	0.190227 - Y position
	0.41264 - X velocity
	0.803128 - Y velocity

![alt text][sample_data2]
