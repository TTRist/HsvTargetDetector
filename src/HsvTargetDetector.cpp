// -*- C++ -*-
/*!
 * @file  HsvTargetDetector.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "HsvTargetDetector.h"
#include "confReader.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;



// Module specification
// <rtc-template block="module_spec">
static const char* hsvtargetdetector_spec[] =
{
  "implementation_id", "HsvTargetDetector",
  "type_name",         "HsvTargetDetector",
  "description",       "ModuleDescription",
  "version",           "1.0.0",
  "vendor",            "Kitajima",
  "category",          "Category",
  "activity_type",     "PERIODIC",
  "kind",              "DataFlowComponent",
  "max_instance",      "1",
  "language",          "C++",
  "lang_type",         "compile",
  // Configuration variables
  "conf.default.Hue_max", "3",
  "conf.default.Hue_min", "0",
  "conf.default.Sat_max", "100",
  "conf.default.Sat_min", "55",
  "conf.default.Val_max", "100",
  "conf.default.Val_min", "37",
  "conf.default.subHue_max", "180",
  "conf.default.subHue_min", "169",
  "conf.default.subSat_max", "100",
  "conf.default.subSat_min", "40",
  "conf.default.subVal_max", "100",
  "conf.default.subVal_min", "37",

  // Widget
  "conf.__widget__.Hue_max", "slider.1",
  "conf.__widget__.Hue_min", "slider.1",
  "conf.__widget__.Sat_max", "slider.1",
  "conf.__widget__.Sat_min", "slider.1",
  "conf.__widget__.Val_max", "slider.1",
  "conf.__widget__.Val_min", "slider.1",
  "conf.__widget__.subHue_max", "slider.1",
  "conf.__widget__.subHue_min", "slider.1",
  "conf.__widget__.subSat_max", "slider.1",
  "conf.__widget__.subSat_min", "slider.1",
  "conf.__widget__.subVal_max", "slider.1",
  "conf.__widget__.subVal_min", "slider.1",
  // Constraints
  "conf.__constraints__.Hue_max", "0<=x<=180",
  "conf.__constraints__.Hue_min", "0<=x<=180",
  "conf.__constraints__.Sat_max", "0<=x<=100",
  "conf.__constraints__.Sat_min", "0<=x<=100",
  "conf.__constraints__.Val_max", "0<=x<=100",
  "conf.__constraints__.Val_min", "0<=x<=100",
  "conf.__constraints__.subHue_max", "0<=x<=180",
  "conf.__constraints__.subHue_min", "0<=x<=180",
  "conf.__constraints__.subSat_max", "0<=x<=100",
  "conf.__constraints__.subSat_min", "0<=x<=100",
  "conf.__constraints__.subVal_max", "0<=x<=100",
  "conf.__constraints__.subVal_min", "0<=x<=100",

  "conf.__type__.Hue_max", "short",
  "conf.__type__.Hue_min", "short",
  "conf.__type__.Sat_max", "short",
  "conf.__type__.Sat_min", "short",
  "conf.__type__.Val_max", "short",
  "conf.__type__.Val_min", "short",
  "conf.__type__.subHue_max", "short",
  "conf.__type__.subHue_min", "short",
  "conf.__type__.subSat_max", "short",
  "conf.__type__.subSat_min", "short",
  "conf.__type__.subVal_max", "short",
  "conf.__type__.subVal_min", "short",

  ""
};
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
HsvTargetDetector::HsvTargetDetector(RTC::Manager* manager)
// <rtc-template block="initializer">
	: RTC::DataFlowComponentBase(manager),
	m_rtc_imgIn("rtc_img", m_rtc_img),
	m_pix_numOut("pix_num", m_pix_num),
	m_center_posOut("center_pos", m_center_pos)

	// </rtc-template>
{
}

/*!
 * @brief destructor
 */
HsvTargetDetector::~HsvTargetDetector()
{
}



RTC::ReturnCode_t HsvTargetDetector::onInitialize()
{
	printf("onInitialize [HsvTargetDetector]\n");
	// Registration: InPort/OutPort/Service
	// <rtc-template block="registration">
	// Set InPort buffers
	addInPort("rtc_img", m_rtc_imgIn);

	// Set OutPort buffer
	addOutPort("pix_num", m_pix_numOut);
	addOutPort("center_pos", m_center_posOut);

	// Set service provider to Ports

	// Set service consumers to Ports

	// Set CORBA Service Ports

	// </rtc-template>

	// <rtc-template block="bind_config">
	// Bind variables and configuration variable
	bindParameter("Hue_max", m_Hue_max, "3");
	bindParameter("Hue_min", m_Hue_min, "0");
	bindParameter("Sat_max", m_Sat_max, "100");
	bindParameter("Sat_min", m_Sat_min, "55");
	bindParameter("Val_max", m_Val_max, "100");
	bindParameter("Val_min", m_Val_min, "37");
	bindParameter("subHue_max", m_subHue_max, "180");
	bindParameter("subHue_min", m_subHue_min, "169");
	bindParameter("subSat_max", m_subSat_max, "100");
	bindParameter("subSat_min", m_subSat_min, "40");
	bindParameter("subVal_max", m_subVal_max, "100");
	bindParameter("subVal_min", m_subVal_min, "37");
	// </rtc-template>

	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t HsvTargetDetector::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetector::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetector::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t HsvTargetDetector::onActivated(RTC::UniqueId ec_id)
{
	ifstream infile("./../../../MakedFile/HsvThreshold.ini");
	if (infile) conf::setMap(conf::config_map, infile, R"(=|\s)");
	else printf("パスが違う\n");
	infile.close();

	if (conf::config_map["eula"] == "true") {
		m_Hue_max = conf::readMap("Hue_max");
		m_Hue_min = conf::readMap("Hue_min");
		m_Sat_max = conf::readMap("Sat_max");
		m_Sat_min = conf::readMap("Sat_min");
		m_Val_max = conf::readMap("Val_max");
		m_Val_min = conf::readMap("Val_min");
		m_subHue_max = conf::readMap("subHue_max");
		m_subHue_min = conf::readMap("subHue_min");
		m_subSat_max = conf::readMap("subSat_max");
		m_subSat_min = conf::readMap("subSat_min");
		m_subVal_max = conf::readMap("subVal_max");
		m_subVal_min = conf::readMap("subVal_min");
	}
	else printf("Not Using Map\n");

	return RTC::RTC_OK;
}


RTC::ReturnCode_t HsvTargetDetector::onDeactivated(RTC::UniqueId ec_id)
{
	destroyAllWindows();
	return RTC::RTC_OK;
}


RTC::ReturnCode_t HsvTargetDetector::onExecute(RTC::UniqueId ec_id)
{
	if (m_rtc_imgIn.isNew()) {
		while (!m_rtc_imgIn.isEmpty()) m_rtc_imgIn.read(); // 最新データ取得
		Mat smooth_img, hsv_img;
		Mat bgr_img(m_rtc_img.height, m_rtc_img.width, CV_8UC3, &m_rtc_img.pixels[0]); // matTypeをRGBに固定
		if (bgr_img.empty()) {
			printf("no Image\n");
			RTC::RTC_OK;
		}

		medianBlur(bgr_img, smooth_img, 3);					// ぼかし
		cvtColor(smooth_img, hsv_img, COLOR_BGR2HSV, 3);	// HSV変換

		// 指定色で2値化
		Mat mask;
		Scalar th_min = Scalar(m_Hue_min, m_Sat_min * 255.0 / 100 + 0.5, m_Val_min * 255.0 / 100 + 0.5);
		Scalar th_max = Scalar(m_Hue_max, m_Sat_max * 255.0 / 100 + 0.5, m_Val_max * 255.0 / 100 + 0.5);
		inRange(hsv_img, th_min, th_max, mask);

		// HSVの範囲をもう一つ使うならマスク追加（赤は2つ必要）
		if (m_subHue_min <= m_subHue_max) {
			Mat sub_mask;
			th_min = Scalar(m_subHue_min, m_subSat_min * 255.0 / 100 + 0.5, m_subVal_min * 255.0 / 100 + 0.5);
			th_max = Scalar(m_subHue_max, m_subSat_max * 255.0 / 100 + 0.5, m_subVal_max * 255.0 / 100 + 0.5);
			inRange(hsv_img, th_min, th_max, sub_mask);
			mask += sub_mask;
		}

		//モルフォロジー変換
		for (int i = 0; i < 4; i++) {
			erode(mask, mask, cv::Mat(), cv::Point(-1, -1), 2); // 収縮
			dilate(mask, mask, cv::Mat(), cv::Point(-1, -1), 3); // 膨張
		}

		// 2値化画像から重心座標とピクセル数取得
		Moments mu = moments(mask, false);
		Point2d pos = Point2d(mu.m10 / mu.m00, mu.m01 / mu.m00);
		m_center_pos.data.x = -(pos.x - mask.cols / 2); // 回転方向を基準．左が正
		m_center_pos.data.y = pos.y;
		m_pix_num.data = countNonZero(mask);

		// 結果表示用
		Mat masked_img;
		bgr_img.copyTo(masked_img, mask);

		static long pre_t = clock();
		if (isnan(pos.x)) {
			if (clock() - pre_t > 1000) {
				m_center_pos.data.x = 0;
				m_center_pos.data.y = 0;
				m_center_posOut.write();
				m_pix_numOut.write();
			}
		}
		else {
			circle(masked_img, pos, 10, Scalar(0, 255, 0), 3);
			printf("x: %.1f  size: %d\n", m_center_pos.data.x, countNonZero(mask));
			pre_t = clock();
			m_center_posOut.write();
			m_pix_numOut.write();
		}

		


		imshow("ColorTarget", masked_img);
		waitKey(1); // 表示時間のdelay的なもの

	}
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t HsvTargetDetector::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetector::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetector::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetector::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetector::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{

	void HsvTargetDetectorInit(RTC::Manager* manager)
	{
		coil::Properties profile(hsvtargetdetector_spec);
		manager->registerFactory(profile,
			RTC::Create<HsvTargetDetector>,
			RTC::Delete<HsvTargetDetector>);
	}

};


