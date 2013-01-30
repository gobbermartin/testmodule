/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// .NAME vtkSlicerTestModuleLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerTestModuleLogic_h
#define __vtkSlicerTestModuleLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"
class vtkSlicerVolumesLogic;

// MRML includes

// STD includes
#include <cstdlib>

#include "vtkSlicerTestModuleModuleLogicExport.h"


/// \ingroup Slicer_QtModules_ExtensionTemplate
class VTK_SLICER_TESTMODULE_MODULE_LOGIC_EXPORT vtkSlicerTestModuleLogic :
  public vtkSlicerModuleLogic
{
public:

  static vtkSlicerTestModuleLogic *New();
  vtkTypeMacro(vtkSlicerTestModuleLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);
  void SetVolumesLogic(vtkSlicerVolumesLogic* logic);

protected:
  vtkSlicerTestModuleLogic();
  virtual ~vtkSlicerTestModuleLogic();

  virtual void SetMRMLSceneInternal(vtkMRMLScene* newScene);
  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  virtual void RegisterNodes();
  virtual void UpdateFromMRMLScene();
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node);
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node);
private:

  vtkSlicerTestModuleLogic(const vtkSlicerTestModuleLogic&); // Not implemented
  void operator=(const vtkSlicerTestModuleLogic&);               // Not implemented

  
  class vtkInternal;
  vtkInternal* Internal;
};

#endif
