/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 13.0
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HDESCRIPTORMODEL
#define HCPP_HDESCRIPTORMODEL

namespace HalconCpp
{

// Represents an instance of a descriptor model.
class LIntExport HDescriptorModel : public HToolBase
{

public:

  // Create an uninitialized instance
  HDescriptorModel():HToolBase() {}

  // Copy constructor
  HDescriptorModel(const HDescriptorModel& source) : HToolBase(source) {}

  // Create HDescriptorModel from handle, taking ownership
  explicit HDescriptorModel(Hlong handle);

  // Set new handle, taking ownership
  void SetHandle(Hlong handle);

  // Deep copy of all data represented by this object instance
  HDescriptorModel Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_descriptor_model: Read a descriptor model from a file.
  explicit HDescriptorModel(const HString& FileName);

  // read_descriptor_model: Read a descriptor model from a file.
  explicit HDescriptorModel(const char* FileName);

  // create_calib_descriptor_model: Create a descriptor model for calibrated perspective matching.
  explicit HDescriptorModel(const HImage& Template, const HCamPar& CamParam, const HPose& ReferencePose, const HString& DetectorType, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, Hlong Seed);

  // create_calib_descriptor_model: Create a descriptor model for calibrated perspective matching.
  explicit HDescriptorModel(const HImage& Template, const HCamPar& CamParam, const HPose& ReferencePose, const char* DetectorType, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, Hlong Seed);

  // create_uncalib_descriptor_model: Prepare a descriptor model for interest point matching.
  explicit HDescriptorModel(const HImage& Template, const HString& DetectorType, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, Hlong Seed);

  // create_uncalib_descriptor_model: Prepare a descriptor model for interest point matching.
  explicit HDescriptorModel(const HImage& Template, const char* DetectorType, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, Hlong Seed);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Deserialize a descriptor model.
  void DeserializeDescriptorModel(const HSerializedItem& SerializedItemHandle);

  // Serialize a descriptor model.
  HSerializedItem SerializeDescriptorModel() const;

  // Read a descriptor model from a file.
  void ReadDescriptorModel(const HString& FileName);

  // Read a descriptor model from a file.
  void ReadDescriptorModel(const char* FileName);

  // Write a descriptor model to a file.
  void WriteDescriptorModel(const HString& FileName) const;

  // Write a descriptor model to a file.
  void WriteDescriptorModel(const char* FileName) const;

  // Find the best matches of a calibrated descriptor model in an image and return their 3D pose.
  HPoseArray FindCalibDescriptorModel(const HImage& Image, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, const HTuple& MinScore, Hlong NumMatches, const HCamPar& CamParam, const HTuple& ScoreType, HTuple* Score) const;

  // Find the best matches of a calibrated descriptor model in an image and return their 3D pose.
  HPose FindCalibDescriptorModel(const HImage& Image, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, double MinScore, Hlong NumMatches, const HCamPar& CamParam, const HString& ScoreType, double* Score) const;

  // Find the best matches of a calibrated descriptor model in an image and return their 3D pose.
  HPose FindCalibDescriptorModel(const HImage& Image, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, double MinScore, Hlong NumMatches, const HCamPar& CamParam, const char* ScoreType, double* Score) const;

  // Find the best matches of a descriptor model in an image.
  HHomMat2DArray FindUncalibDescriptorModel(const HImage& Image, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, const HTuple& MinScore, Hlong NumMatches, const HTuple& ScoreType, HTuple* Score) const;

  // Find the best matches of a descriptor model in an image.
  HHomMat2D FindUncalibDescriptorModel(const HImage& Image, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, double MinScore, Hlong NumMatches, const HString& ScoreType, double* Score) const;

  // Find the best matches of a descriptor model in an image.
  HHomMat2D FindUncalibDescriptorModel(const HImage& Image, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, double MinScore, Hlong NumMatches, const char* ScoreType, double* Score) const;

  // Query the interest points of the descriptor model or the last processed search image.
  void GetDescriptorModelPoints(const HString& Set, const HTuple& Subset, HTuple* Row, HTuple* Column) const;

  // Query the interest points of the descriptor model or the last processed search image.
  void GetDescriptorModelPoints(const HString& Set, Hlong Subset, HTuple* Row, HTuple* Column) const;

  // Query the interest points of the descriptor model or the last processed search image.
  void GetDescriptorModelPoints(const char* Set, Hlong Subset, HTuple* Row, HTuple* Column) const;

  // Return the parameters of a descriptor model.
  HString GetDescriptorModelParams(HTuple* DetectorParamName, HTuple* DetectorParamValue, HTuple* DescriptorParamName, HTuple* DescriptorParamValue) const;

  // Create a descriptor model for calibrated perspective matching.
  void CreateCalibDescriptorModel(const HImage& Template, const HCamPar& CamParam, const HPose& ReferencePose, const HString& DetectorType, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, Hlong Seed);

  // Create a descriptor model for calibrated perspective matching.
  void CreateCalibDescriptorModel(const HImage& Template, const HCamPar& CamParam, const HPose& ReferencePose, const char* DetectorType, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, Hlong Seed);

  // Prepare a descriptor model for interest point matching.
  void CreateUncalibDescriptorModel(const HImage& Template, const HString& DetectorType, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, Hlong Seed);

  // Prepare a descriptor model for interest point matching.
  void CreateUncalibDescriptorModel(const HImage& Template, const char* DetectorType, const HTuple& DetectorParamName, const HTuple& DetectorParamValue, const HTuple& DescriptorParamName, const HTuple& DescriptorParamValue, Hlong Seed);

  // Query alphanumerical results that were accumulated during descriptor-based matching.
  HTuple GetDescriptorModelResults(const HTuple& ObjectID, const HString& ResultNames) const;

  // Query alphanumerical results that were accumulated during descriptor-based matching.
  HTuple GetDescriptorModelResults(Hlong ObjectID, const HString& ResultNames) const;

  // Query alphanumerical results that were accumulated during descriptor-based matching.
  HTuple GetDescriptorModelResults(Hlong ObjectID, const char* ResultNames) const;

  // Return the origin of a descriptor model.
  void GetDescriptorModelOrigin(HTuple* Row, HTuple* Column) const;

  // Return the origin of a descriptor model.
  void GetDescriptorModelOrigin(double* Row, double* Column) const;

  // Sets the origin of a descriptor model.
  void SetDescriptorModelOrigin(const HTuple& Row, const HTuple& Column) const;

  // Sets the origin of a descriptor model.
  void SetDescriptorModelOrigin(double Row, double Column) const;

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HToolArrayRef;

typedef HToolArrayRef<HDescriptorModel> HDescriptorModelArrayRef;
typedef HSmartPtr< HDescriptorModelArrayRef > HDescriptorModelArrayPtr;


// Represents multiple tool instances
class LIntExport HDescriptorModelArray : public HToolArray
{

public:

  // Create empty array
  HDescriptorModelArray();

  // Create array from native array of tool instances
  HDescriptorModelArray(HDescriptorModel* classes, Hlong length);

  // Copy constructor
  HDescriptorModelArray(const HDescriptorModelArray &tool_array);

  // Destructor
  virtual ~HDescriptorModelArray();

  // Assignment operator
  HDescriptorModelArray &operator=(const HDescriptorModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HDescriptorModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HDescriptorModelArrayPtr *mArrayPtr;
};

}

#endif
