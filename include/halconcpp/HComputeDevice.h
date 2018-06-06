/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 13.0
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HCOMPUTEDEVICE
#define HCPP_HCOMPUTEDEVICE

namespace HalconCpp
{

// Class representing a compute device handle.
class LIntExport HComputeDevice : public HToolBase
{

public:

  // Create an uninitialized instance
  HComputeDevice():HToolBase() {}

  // Copy constructor
  HComputeDevice(const HComputeDevice& source) : HToolBase(source) {}

  // Set new handle, taking ownership
  void SetHandle(Hlong handle);



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // open_compute_device: Open a compute device.
  explicit HComputeDevice(Hlong DeviceIdentifier);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Query compute device parameters.
  HTuple GetComputeDeviceParam(const HString& GenParamName) const;

  // Query compute device parameters.
  HTuple GetComputeDeviceParam(const char* GenParamName) const;

  // Set parameters of an compute device.
  void SetComputeDeviceParam(const HString& GenParamName, const HTuple& GenParamValue) const;

  // Set parameters of an compute device.
  void SetComputeDeviceParam(const HString& GenParamName, const HString& GenParamValue) const;

  // Set parameters of an compute device.
  void SetComputeDeviceParam(const char* GenParamName, const char* GenParamValue) const;

  // Close all compute devices.
  static void ReleaseAllComputeDevices();

  // Close a compute_device.
  void ReleaseComputeDevice() const;

  // Deactivate all compute devices.
  static void DeactivateAllComputeDevices();

  // Deactivate a compute device.
  void DeactivateComputeDevice() const;

  // Activate a compute device.
  void ActivateComputeDevice() const;

  // Initialize a compute device.
  void InitComputeDevice(const HTuple& Operators) const;

  // Open a compute device.
  void OpenComputeDevice(Hlong DeviceIdentifier);

  // Get information on a compute device.
  static HTuple GetComputeDeviceInfo(Hlong DeviceIdentifier, const HString& InfoName);

  // Get information on a compute device.
  static HTuple GetComputeDeviceInfo(Hlong DeviceIdentifier, const char* InfoName);

  // Get the list of available compute devices.
  static HTuple QueryAvailableComputeDevices();

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HToolArrayRef;

typedef HToolArrayRef<HComputeDevice> HComputeDeviceArrayRef;
typedef HSmartPtr< HComputeDeviceArrayRef > HComputeDeviceArrayPtr;


// Represents multiple tool instances
class LIntExport HComputeDeviceArray : public HToolArray
{

public:

  // Create empty array
  HComputeDeviceArray();

  // Create array from native array of tool instances
  HComputeDeviceArray(HComputeDevice* classes, Hlong length);

  // Copy constructor
  HComputeDeviceArray(const HComputeDeviceArray &tool_array);

  // Destructor
  virtual ~HComputeDeviceArray();

  // Assignment operator
  HComputeDeviceArray &operator=(const HComputeDeviceArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HComputeDevice* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HComputeDeviceArrayPtr *mArrayPtr;
};

}

#endif
