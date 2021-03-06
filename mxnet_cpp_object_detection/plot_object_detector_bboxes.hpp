#ifndef PLOT_OBJECT_DETECTOR_BBOXES_HPP
#define PLOT_OBJECT_DETECTOR_BBOXES_HPP

#include "object_detector_filter.hpp"

#include <mxnet-cpp/ndarray.h>

#include <opencv2/core.hpp>

#include <string>
#include <vector>

class object_detector_filter;

namespace viz {

std::vector<cv::Scalar> generate_colors(size_t target_size);

class plot_object_detector_bboxes
{
public:
    explicit plot_object_detector_bboxes(std::vector<std::string> labels, float thresh = 0.5f);
    plot_object_detector_bboxes(std::vector<std::string> labels, std::vector<cv::Scalar> colors, float thresh = 0.5f);

    ~plot_object_detector_bboxes();

    void plot(cv::Mat &inout, std::vector<mxnet::cpp::NDArray> const &predict_results);

    void set_process_size_of_detector(cv::Size const &process_size) noexcept;
    void set_thresh(float val) noexcept;

private:
    std::pair<cv::Point, cv::Point> normalize_points(float x1, float y1,
                                                     float x2, float y2,
                                                     bool normalize, cv::Size const &input_size) const noexcept;

    std::vector<cv::Scalar> colors_;
    std::vector<std::string> labels_;
    std::unique_ptr<object_detector_filter> obj_filter_;
    cv::Size process_size_;
    float thresh_ = 0.5;
};

}

#endif // PLOT_OBJECT_DETECTOR_BBOXES_HPP
