//=========================================================================
// MultiCamViewer - Viewer and algorithms for multicamera system
//
// Copyright 2018 Pierre Guilbert
// Author: Pierre Guilbert (spguilbert@gmail.com)
// Data: 02-11-2018
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//=========================================================================

#include "distanceinfodialog.h"
#include "ui_distanceinfodialog.h"

DistanceInfoDialog::DistanceInfoDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DistanceInfoDialog)
{
  ui->setupUi(this);
  this->ui->cameraDistanceRatio->setChecked(true);
}

DistanceInfoDialog::~DistanceInfoDialog()
{
  delete ui;
}

//---------------------------------------------------------------------------
double DistanceInfoDialog::GetDistanceValue()
{
  return this->ui->distanceSpinBox->value();
}

//---------------------------------------------------------------------------
int DistanceInfoDialog::GetMethodChoice()
{
  int ret = 0;
  if (this->ui->cameraDistanceRatio->isChecked())
  {
    std::cout << "Camera distance mode" << std::endl;
    ret = 1;
  }
  else if (this->ui->distanceTwoPointsRatio->isChecked())
  {
    std::cout << "two points distance mode" << std::endl;
    ret = 2;
  }

  return ret;
}
