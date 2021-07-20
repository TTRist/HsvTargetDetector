// -*- C++ -*-
/*!
 * @file  HsvTargetDetector.h
 * @brief ModuleDescription
 * @date  $Date$
 *
 * $Id$
 */

#ifndef HSVTARGETDETECTOR_H
#define HSVTARGETDETECTOR_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "InterfaceDataTypesStub.h"
#include "BasicDataTypeStub.h"
#include "ExtendedDataTypesStub.h"

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

#include <opencv2/opencv.hpp>

/*!
 * @class HsvTargetDetector
 * @brief ModuleDescription
 *
 * 受け取った画像をHSV方式で色を抽出し，そのピクセル数と重心の座標
 * をポート出力する
 *
 */
class HsvTargetDetector
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  HsvTargetDetector(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~HsvTargetDetector();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  Hue_max
   * - DefaultValue: 3
   */
  short int m_Hue_max;
  /*!
   * 
   * - Name:  Hue_min
   * - DefaultValue: 0
   */
  short int m_Hue_min;
  /*!
   * 
   * - Name:  Sat_max
   * - DefaultValue: 100
   */
  short int m_Sat_max;
  /*!
   * 
   * - Name:  Sat_min
   * - DefaultValue: 55
   */
  short int m_Sat_min;
  /*!
   * 
   * - Name:  Val_max
   * - DefaultValue: 100
   */
  short int m_Val_max;
  /*!
   * 
   * - Name:  Val_min
   * - DefaultValue: 37
   */
  short int m_Val_min;
  /*!
   * 
   * - Name:  subHue_max
   * - DefaultValue: 180
   */
  short int m_subHue_max;
  /*!
   * 
   * - Name:  subHue_min
   * - DefaultValue: 169
   */
  short int m_subHue_min;
  /*!
   * 
   * - Name:  subSat_max
   * - DefaultValue: 100
   */
  short int m_subSat_max;
  /*!
   * 
   * - Name:  subSat_min
   * - DefaultValue: 40
   */
  short int m_subSat_min;
  /*!
   * 
   * - Name:  subVal_max
   * - DefaultValue: 100
   */
  short int m_subVal_max;
  /*!
   * 
   * - Name:  subVal_min
   * - DefaultValue: 37
   */
  short int m_subVal_min;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::CameraImage m_rtc_img;
  /*!
   */
  RTC::InPort<RTC::CameraImage> m_rtc_imgIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedLong m_pix_num;
  /*!
   * 色抽出したピクセル数
   */
  RTC::OutPort<RTC::TimedLong> m_pix_numOut;
  RTC::TimedPoint2D m_center_pos;
  /*!
   * 色抽出した重心
   */
  RTC::OutPort<RTC::TimedPoint2D> m_center_posOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void HsvTargetDetectorInit(RTC::Manager* manager);
};

#endif // HSVTARGETDETECTOR_H
