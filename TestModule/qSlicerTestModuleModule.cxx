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

// Qt includes
#include <QtPlugin>

// TestModule Logic includes
#include <vtkSlicerTestModuleLogic.h>

// TestModule includes
#include "qSlicerTestModuleModule.h"
#include "qSlicerTestModuleModuleWidget.h"

#include <vtkSlicerVolumesLogic.h>

// Slicer includes
#include <qSlicerCoreApplication.h>
#include <qSlicerModuleManager.h>

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerTestModuleModule, qSlicerTestModuleModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerTestModuleModulePrivate
{
public:
  qSlicerTestModuleModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerTestModuleModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerTestModuleModulePrivate
::qSlicerTestModuleModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerTestModuleModule methods

//-----------------------------------------------------------------------------
qSlicerTestModuleModule
::qSlicerTestModuleModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerTestModuleModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerTestModuleModule::~qSlicerTestModuleModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerTestModuleModule::helpText()const
{
  return "This is a loadable module bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerTestModuleModule::acknowledgementText()const
{
  return "This work was was partially funded by NIH grant 3P41RR013218-12S1";
}

//-----------------------------------------------------------------------------
QStringList qSlicerTestModuleModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Jean-Christophe Fillion-Robin (Kitware)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerTestModuleModule::icon()const
{
  return QIcon(":/Icons/TestModule.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerTestModuleModule::categories() const
{
  return QStringList() << "Examples";
}

//-----------------------------------------------------------------------------
QStringList qSlicerTestModuleModule::dependencies() const
{
  return QStringList() << "Volumes";
}

//-----------------------------------------------------------------------------
void qSlicerTestModuleModule::setup()
{
  this->Superclass::setup();

   vtkSlicerTestModuleLogic* moduleLogic =
   vtkSlicerTestModuleLogic::SafeDownCast(this->logic());

   qSlicerAbstractCoreModule* volumesModule =
   qSlicerCoreApplication::application()->moduleManager()->module("Volumes");

   vtkSlicerVolumesLogic* volumesLogic = 
   vtkSlicerVolumesLogic::SafeDownCast(volumesModule->logic());
   moduleLogic->SetVolumesLogic(volumesLogic);
   
 
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerTestModuleModule
::createWidgetRepresentation()
{
  return new qSlicerTestModuleModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerTestModuleModule::createLogic()
{
  return vtkSlicerTestModuleLogic::New();
}
