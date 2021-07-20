// -*- C++ -*-
/*!
 * @file  HsvTargetDetectorTest.h
 * @brief ModuleDescription
 * @date  $Date$
 *
 * $Id$
 */

#ifndef HSVTARGETDETECTOR_TEST__H
#define HSVTARGETDETECTOR_TEST_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">
#include "InterfaceDataTypesSVC_impl.h"
#include "BasicDataTypeSVC_impl.h"
#include "ExtendedDataTypesSVC_impl.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

/*!
 * @class HsvTargetDetectorTest
 * @brief ModuleDescription
 *
 * 受け取った画像をHSV方式で色を抽出し，そのピクセル数と重心の座標
 * をポート出力する
 *
 */
class HsvTargetDetectorTest
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  HsvTargetDetectorTest(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~HsvTargetDetectorTest();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
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
   * former rtc_stopping_entry()
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
   * former rtc_active_entry()
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
   * former rtc_active_exit()
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
   * former rtc_active_do()
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
   * former rtc_aborting_entry()
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
   * former rtc_error_do()
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
   * This is same but different the former rtc_init_entry()
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
   * no corresponding operation exists in OpenRTm-aist-0.2.0
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
   * no corresponding operation exists in OpenRTm-aist-0.2.0
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
  RTC::TimedLong m_pix_num;
  /*!
   * 色抽出したピクセル数
   */
  RTC::InPort<RTC::TimedLong> m_pix_numIn;
  RTC::TimedPoint2D m_center_pos;
  /*!
   * 色抽出した重心
   */
  RTC::InPort<RTC::TimedPoint2D> m_center_posIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::CameraImage m_rtc_img;
  /*!
   */
  RTC::OutPort<RTC::CameraImage> m_rtc_imgOut;
  
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
  DLL_EXPORT void HsvTargetDetectorTestInit(RTC::Manager* manager);
};

#endif // HSVTARGETDETECTOR_TEST_H
