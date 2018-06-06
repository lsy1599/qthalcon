/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 13.0
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HSHAPEMODEL
#define HCPP_HSHAPEMODEL

namespace HalconCpp
{

// Represents an instance of a shape model for matching.
class LIntExport HShapeModel : public HToolBase
{

public:

  // Create an uninitialized instance
  HShapeModel():HToolBase() {}

  // Copy constructor
  HShapeModel(const HShapeModel& source) : HToolBase(source) {}

  // Create HShapeModel from handle, taking ownership
  explicit HShapeModel(Hlong handle);

  // Set new handle, taking ownership
  void SetHandle(Hlong handle);

  // Deep copy of all data represented by this object instance
  HShapeModel Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_shape_model: Read a shape model from a file.
  explicit HShapeModel(const HString& FileName);

  // read_shape_model: Read a shape model from a file.
  explicit HShapeModel(const char* FileName);

  // create_aniso_shape_model_xld: Prepare an anisotropically scaled shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, double ScaleRMin, double ScaleRMax, const HTuple& ScaleRStep, double ScaleCMin, double ScaleCMax, const HTuple& ScaleCStep, const HTuple& Optimization, const HString& Metric, Hlong MinContrast);

  // create_aniso_shape_model_xld: Prepare an anisotropically scaled shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const HString& Optimization, const HString& Metric, Hlong MinContrast);

  // create_aniso_shape_model_xld: Prepare an anisotropically scaled shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const char* Optimization, const char* Metric, Hlong MinContrast);

  // create_scaled_shape_model_xld: Prepare an isotropically scaled shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, double ScaleMin, double ScaleMax, const HTuple& ScaleStep, const HTuple& Optimization, const HString& Metric, Hlong MinContrast);

  // create_scaled_shape_model_xld: Prepare an isotropically scaled shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const HString& Optimization, const HString& Metric, Hlong MinContrast);

  // create_scaled_shape_model_xld: Prepare an isotropically scaled shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const char* Optimization, const char* Metric, Hlong MinContrast);

  // create_shape_model_xld: Prepare a shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, const HTuple& Optimization, const HString& Metric, Hlong MinContrast);

  // create_shape_model_xld: Prepare a shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const HString& Optimization, const HString& Metric, Hlong MinContrast);

  // create_shape_model_xld: Prepare a shape model for matching from XLD contours.
  explicit HShapeModel(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char* Optimization, const char* Metric, Hlong MinContrast);

  // create_aniso_shape_model: Prepare an anisotropically scaled shape model for matching.
  explicit HShapeModel(const HImage& Template, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, double ScaleRMin, double ScaleRMax, const HTuple& ScaleRStep, double ScaleCMin, double ScaleCMax, const HTuple& ScaleCStep, const HTuple& Optimization, const HString& Metric, const HTuple& Contrast, const HTuple& MinContrast);

  // create_aniso_shape_model: Prepare an anisotropically scaled shape model for matching.
  explicit HShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const HString& Optimization, const HString& Metric, Hlong Contrast, Hlong MinContrast);

  // create_aniso_shape_model: Prepare an anisotropically scaled shape model for matching.
  explicit HShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const char* Optimization, const char* Metric, Hlong Contrast, Hlong MinContrast);

  // create_scaled_shape_model: Prepare an isotropically scaled shape model for matching.
  explicit HShapeModel(const HImage& Template, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, double ScaleMin, double ScaleMax, const HTuple& ScaleStep, const HTuple& Optimization, const HString& Metric, const HTuple& Contrast, const HTuple& MinContrast);

  // create_scaled_shape_model: Prepare an isotropically scaled shape model for matching.
  explicit HShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const HString& Optimization, const HString& Metric, Hlong Contrast, Hlong MinContrast);

  // create_scaled_shape_model: Prepare an isotropically scaled shape model for matching.
  explicit HShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const char* Optimization, const char* Metric, Hlong Contrast, Hlong MinContrast);

  // create_shape_model: Prepare a shape model for matching.
  explicit HShapeModel(const HImage& Template, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, const HTuple& Optimization, const HString& Metric, const HTuple& Contrast, const HTuple& MinContrast);

  // create_shape_model: Prepare a shape model for matching.
  explicit HShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const HString& Optimization, const HString& Metric, Hlong Contrast, Hlong MinContrast);

  // create_shape_model: Prepare a shape model for matching.
  explicit HShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char* Optimization, const char* Metric, Hlong Contrast, Hlong MinContrast);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Deserialize a serialized shape model.
  void DeserializeShapeModel(const HSerializedItem& SerializedItemHandle);

  // Read a shape model from a file.
  void ReadShapeModel(const HString& FileName);

  // Read a shape model from a file.
  void ReadShapeModel(const char* FileName);

  // Serialize a shape model.
  HSerializedItem SerializeShapeModel() const;

  // Write a shape model to a file.
  void WriteShapeModel(const HString& FileName) const;

  // Write a shape model to a file.
  void WriteShapeModel(const char* FileName) const;

  // Return the contour representation of a shape model.
  HXLDCont GetShapeModelContours(Hlong Level) const;

  // Return the parameters of a shape model.
  Hlong GetShapeModelParams(double* AngleStart, double* AngleExtent, double* AngleStep, HTuple* ScaleMin, HTuple* ScaleMax, HTuple* ScaleStep, HString* Metric, Hlong* MinContrast) const;

  // Return the parameters of a shape model.
  Hlong GetShapeModelParams(double* AngleStart, double* AngleExtent, double* AngleStep, double* ScaleMin, double* ScaleMax, double* ScaleStep, HString* Metric, Hlong* MinContrast) const;

  // Return the origin (reference point) of a shape model.
  void GetShapeModelOrigin(double* Row, double* Column) const;

  // Set the origin (reference point) of a shape model.
  void SetShapeModelOrigin(double Row, double Column) const;

  // Find the best matches of multiple anisotropically scaled shape models.
  static void FindAnisoShapeModels(const HImage& Image, const HShapeModelArray& ModelIDs, const HTuple& AngleStart, const HTuple& AngleExtent, const HTuple& ScaleRMin, const HTuple& ScaleRMax, const HTuple& ScaleCMin, const HTuple& ScaleCMax, const HTuple& MinScore, const HTuple& NumMatches, const HTuple& MaxOverlap, const HTuple& SubPixel, const HTuple& NumLevels, const HTuple& Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* ScaleR, HTuple* ScaleC, HTuple* Score, HTuple* Model);

  // Find the best matches of multiple anisotropically scaled shape models.
  void FindAnisoShapeModels(const HImage& Image, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const HString& SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* ScaleR, HTuple* ScaleC, HTuple* Score, HTuple* Model) const;

  // Find the best matches of multiple anisotropically scaled shape models.
  void FindAnisoShapeModels(const HImage& Image, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char* SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* ScaleR, HTuple* ScaleC, HTuple* Score, HTuple* Model) const;

  // Find the best matches of multiple isotropically scaled shape models.
  static void FindScaledShapeModels(const HImage& Image, const HShapeModelArray& ModelIDs, const HTuple& AngleStart, const HTuple& AngleExtent, const HTuple& ScaleMin, const HTuple& ScaleMax, const HTuple& MinScore, const HTuple& NumMatches, const HTuple& MaxOverlap, const HTuple& SubPixel, const HTuple& NumLevels, const HTuple& Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Scale, HTuple* Score, HTuple* Model);

  // Find the best matches of multiple isotropically scaled shape models.
  void FindScaledShapeModels(const HImage& Image, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const HString& SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Scale, HTuple* Score, HTuple* Model) const;

  // Find the best matches of multiple isotropically scaled shape models.
  void FindScaledShapeModels(const HImage& Image, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char* SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Scale, HTuple* Score, HTuple* Model) const;

  // Find the best matches of multiple shape models.
  static void FindShapeModels(const HImage& Image, const HShapeModelArray& ModelIDs, const HTuple& AngleStart, const HTuple& AngleExtent, const HTuple& MinScore, const HTuple& NumMatches, const HTuple& MaxOverlap, const HTuple& SubPixel, const HTuple& NumLevels, const HTuple& Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Score, HTuple* Model);

  // Find the best matches of multiple shape models.
  void FindShapeModels(const HImage& Image, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const HString& SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Score, HTuple* Model) const;

  // Find the best matches of multiple shape models.
  void FindShapeModels(const HImage& Image, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const char* SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Score, HTuple* Model) const;

  // Find the best matches of an anisotropically scaled shape model in an image.
  void FindAnisoShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const HTuple& SubPixel, const HTuple& NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* ScaleR, HTuple* ScaleC, HTuple* Score) const;

  // Find the best matches of an anisotropically scaled shape model in an image.
  void FindAnisoShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const HString& SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* ScaleR, HTuple* ScaleC, HTuple* Score) const;

  // Find the best matches of an anisotropically scaled shape model in an image.
  void FindAnisoShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char* SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* ScaleR, HTuple* ScaleC, HTuple* Score) const;

  // Find the best matches of an isotropically scaled shape model in an image.
  void FindScaledShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const HTuple& SubPixel, const HTuple& NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Scale, HTuple* Score) const;

  // Find the best matches of an isotropically scaled shape model in an image.
  void FindScaledShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const HString& SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Scale, HTuple* Score) const;

  // Find the best matches of an isotropically scaled shape model in an image.
  void FindScaledShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char* SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Scale, HTuple* Score) const;

  // Find the best matches of a shape model in an image.
  void FindShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const HTuple& SubPixel, const HTuple& NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Score) const;

  // Find the best matches of a shape model in an image.
  void FindShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const HString& SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Score) const;

  // Find the best matches of a shape model in an image.
  void FindShapeModel(const HImage& Image, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const char* SubPixel, Hlong NumLevels, double Greediness, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Score) const;

  // Set the metric of a shape model that was created from XLD contours.
  void SetShapeModelMetric(const HImage& Image, const HHomMat2D& HomMat2D, const HString& Metric) const;

  // Set the metric of a shape model that was created from XLD contours.
  void SetShapeModelMetric(const HImage& Image, const HHomMat2D& HomMat2D, const char* Metric) const;

  // Set selected parameters of the shape model.
  void SetShapeModelParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Prepare an anisotropically scaled shape model for matching from XLD contours.
  void CreateAnisoShapeModelXld(const HXLDCont& Contours, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, double ScaleRMin, double ScaleRMax, const HTuple& ScaleRStep, double ScaleCMin, double ScaleCMax, const HTuple& ScaleCStep, const HTuple& Optimization, const HString& Metric, Hlong MinContrast);

  // Prepare an anisotropically scaled shape model for matching from XLD contours.
  void CreateAnisoShapeModelXld(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const HString& Optimization, const HString& Metric, Hlong MinContrast);

  // Prepare an anisotropically scaled shape model for matching from XLD contours.
  void CreateAnisoShapeModelXld(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const char* Optimization, const char* Metric, Hlong MinContrast);

  // Prepare an isotropically scaled shape model for matching from XLD contours.
  void CreateScaledShapeModelXld(const HXLDCont& Contours, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, double ScaleMin, double ScaleMax, const HTuple& ScaleStep, const HTuple& Optimization, const HString& Metric, Hlong MinContrast);

  // Prepare an isotropically scaled shape model for matching from XLD contours.
  void CreateScaledShapeModelXld(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const HString& Optimization, const HString& Metric, Hlong MinContrast);

  // Prepare an isotropically scaled shape model for matching from XLD contours.
  void CreateScaledShapeModelXld(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const char* Optimization, const char* Metric, Hlong MinContrast);

  // Prepare a shape model for matching from XLD contours.
  void CreateShapeModelXld(const HXLDCont& Contours, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, const HTuple& Optimization, const HString& Metric, Hlong MinContrast);

  // Prepare a shape model for matching from XLD contours.
  void CreateShapeModelXld(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const HString& Optimization, const HString& Metric, Hlong MinContrast);

  // Prepare a shape model for matching from XLD contours.
  void CreateShapeModelXld(const HXLDCont& Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char* Optimization, const char* Metric, Hlong MinContrast);

  // Prepare an anisotropically scaled shape model for matching.
  void CreateAnisoShapeModel(const HImage& Template, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, double ScaleRMin, double ScaleRMax, const HTuple& ScaleRStep, double ScaleCMin, double ScaleCMax, const HTuple& ScaleCStep, const HTuple& Optimization, const HString& Metric, const HTuple& Contrast, const HTuple& MinContrast);

  // Prepare an anisotropically scaled shape model for matching.
  void CreateAnisoShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const HString& Optimization, const HString& Metric, Hlong Contrast, Hlong MinContrast);

  // Prepare an anisotropically scaled shape model for matching.
  void CreateAnisoShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const char* Optimization, const char* Metric, Hlong Contrast, Hlong MinContrast);

  // Prepare an isotropically scaled shape model for matching.
  void CreateScaledShapeModel(const HImage& Template, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, double ScaleMin, double ScaleMax, const HTuple& ScaleStep, const HTuple& Optimization, const HString& Metric, const HTuple& Contrast, const HTuple& MinContrast);

  // Prepare an isotropically scaled shape model for matching.
  void CreateScaledShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const HString& Optimization, const HString& Metric, Hlong Contrast, Hlong MinContrast);

  // Prepare an isotropically scaled shape model for matching.
  void CreateScaledShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const char* Optimization, const char* Metric, Hlong Contrast, Hlong MinContrast);

  // Prepare a shape model for matching.
  void CreateShapeModel(const HImage& Template, const HTuple& NumLevels, double AngleStart, double AngleExtent, const HTuple& AngleStep, const HTuple& Optimization, const HString& Metric, const HTuple& Contrast, const HTuple& MinContrast);

  // Prepare a shape model for matching.
  void CreateShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const HString& Optimization, const HString& Metric, Hlong Contrast, Hlong MinContrast);

  // Prepare a shape model for matching.
  void CreateShapeModel(const HImage& Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char* Optimization, const char* Metric, Hlong Contrast, Hlong MinContrast);

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HToolArrayRef;

typedef HToolArrayRef<HShapeModel> HShapeModelArrayRef;
typedef HSmartPtr< HShapeModelArrayRef > HShapeModelArrayPtr;


// Represents multiple tool instances
class LIntExport HShapeModelArray : public HToolArray
{

public:

  // Create empty array
  HShapeModelArray();

  // Create array from native array of tool instances
  HShapeModelArray(HShapeModel* classes, Hlong length);

  // Copy constructor
  HShapeModelArray(const HShapeModelArray &tool_array);

  // Destructor
  virtual ~HShapeModelArray();

  // Assignment operator
  HShapeModelArray &operator=(const HShapeModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HShapeModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HShapeModelArrayPtr *mArrayPtr;
};

}

#endif
