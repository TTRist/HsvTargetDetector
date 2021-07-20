// -*- C++ -*-
/*!
 * @file  HsvTargetDetectorTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "HsvTargetDetectorTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* hsvtargetdetector_spec[] =
  {
    "implementation_id", "HsvTargetDetectorTest",
    "type_name",         "HsvTargetDetectorTest",
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
HsvTargetDetectorTest::HsvTargetDetectorTest(RTC::Manager* manager)
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
HsvTargetDetectorTest::~HsvTargetDetectorTest()
{
}



RTC::ReturnCode_t HsvTargetDetectorTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("pix_num", m_pix_numIn);
  addInPort("center_pos", m_center_posIn);

  // Set OutPort buffer
  addOutPort("rtc_img", m_rtc_imgOut);

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
RTC::ReturnCode_t HsvTargetDetectorTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetectorTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetectorTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t HsvTargetDetectorTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t HsvTargetDetectorTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t HsvTargetDetectorTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t HsvTargetDetectorTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetectorTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetectorTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetectorTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HsvTargetDetectorTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{

  void HsvTargetDetectorTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(hsvtargetdetector_spec);
    manager->registerFactory(profile,
                             RTC::Create<HsvTargetDetectorTest>,
                             RTC::Delete<HsvTargetDetectorTest>);
  }

};


