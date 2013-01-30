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

// TestModule Logic includes
#include "vtkSlicerTestModuleLogic.h"
#include "vtkSlicerVolumesLogic.h"

// MRML includes

// VTK includes
#include <vtkNew.h>

// STD includes
#include <cassert>

//----------------------------------------------------------------------------
class vtkSlicerTestModuleLogic::vtkInternal
{
public:
  vtkInternal();

  vtkSlicerVolumesLogic* VolumesLogic;
};

//----------------------------------------------------------------------------
vtkSlicerTestModuleLogic::vtkInternal::vtkInternal()
{
  this->VolumesLogic = 0;
}
//----------------------------------------------------------------------------
vtkStandardNewMacro(vtkSlicerTestModuleLogic);

//----------------------------------------------------------------------------
vtkSlicerTestModuleLogic::vtkSlicerTestModuleLogic()
{
}

//----------------------------------------------------------------------------
vtkSlicerTestModuleLogic::~vtkSlicerTestModuleLogic()
{
}

 void vtkSlicerTestModuleLogic::SetVolumesLogic(vtkSlicerVolumesLogic* logic)
{
  this->Internal->VolumesLogic = logic;
}

//----------------------------------------------------------------------------
void vtkSlicerTestModuleLogic::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//---------------------------------------------------------------------------
void vtkSlicerTestModuleLogic::SetMRMLSceneInternal(vtkMRMLScene * newScene)
{
  vtkNew<vtkIntArray> events;
  events->InsertNextValue(vtkMRMLScene::NodeAddedEvent);
  events->InsertNextValue(vtkMRMLScene::NodeRemovedEvent);
  events->InsertNextValue(vtkMRMLScene::EndBatchProcessEvent);
  this->SetAndObserveMRMLSceneEventsInternal(newScene, events.GetPointer());

  //THIS CODE CAUSES LINK ERROR:
  this->Internal->VolumesLogic->CreateAndAddLabelVolume(
         this->GetMRMLScene(), NULL, "CropVolume_ref_volume");
}

//-----------------------------------------------------------------------------
void vtkSlicerTestModuleLogic::RegisterNodes()
{
  assert(this->GetMRMLScene() != 0);
}

//---------------------------------------------------------------------------
void vtkSlicerTestModuleLogic::UpdateFromMRMLScene()
{
  assert(this->GetMRMLScene() != 0);
}

//---------------------------------------------------------------------------
void vtkSlicerTestModuleLogic
::OnMRMLSceneNodeAdded(vtkMRMLNode* vtkNotUsed(node))
{
}

//---------------------------------------------------------------------------
void vtkSlicerTestModuleLogic
::OnMRMLSceneNodeRemoved(vtkMRMLNode* vtkNotUsed(node))
{
}

