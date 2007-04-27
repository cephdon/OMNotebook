/*
------------------------------------------------------------------------------------
This file is part of OpenModelica.

Copyright (c) 1998-2006, Link�pings universitet,
Department of Computer and Information Science, PELAB
See also: www.ida.liu.se/projects/OpenModelica

All rights reserved.

(The new BSD license, see also
http://www.opensource.org/licenses/bsd-license.php)


Redistribution and use in source and binary forms, with or without
modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    
	* Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    * Neither the name of Link�pings universitet nor the names of its contributors
      may be used to endorse or promote products derived from this software without
      specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

For more information about the Qt-library visit TrollTech:s webpage regarding
licence: http://www.trolltech.com/products/qt/licensing.html

------------------------------------------------------------------------------------
*/

//Qt headers
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

//Std headers
#include <iostream>

//IAEX headers
#include "graphWindow.h"
#include "dataSelect.h"
#include "preferenceWindow.h"

using namespace std;

GraphWindow::GraphWindow(QWidget* parent): QMainWindow(parent)
{
	setupUi(this);

	compoundWidget =graphicsView;
	QObject::connect(actionOpen, SIGNAL(activated()), this, SLOT(openFile()));

	connect(graphicsView->gwMain, SIGNAL(newMessage(QString)), this, SLOT(showMessage(QString)));
    QObject::connect(actionGrid, SIGNAL(toggled(bool)), graphicsView->gwMain, SLOT(showGrid(bool)));

    QObject::connect(actionPan, SIGNAL(toggled(bool)), graphicsView->gwMain, SLOT(setPan(bool)));
	QObject::connect(actionSelect, SIGNAL(toggled(bool)), graphicsView->gwMain, SLOT(setSelect(bool)));
	QObject::connect(actionZoom, SIGNAL(toggled(bool)), graphicsView->gwMain, SLOT(setZoom(bool)));

	connect(actionPreferences, SIGNAL(triggered()), compoundWidget, SLOT(showPreferences()));

	QActionGroup* ag = new QActionGroup(this);
	ag->addAction(actionPan);
	ag->addAction(actionSelect);
	ag->addAction(actionZoom);
	ag->setExclusive(true);
	
	connect(actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

GraphWindow::~GraphWindow()
{

}

void GraphWindow::showPreferences()
{
	PreferenceWindow* pw = new PreferenceWindow(compoundWidget, 0);
	pw->setAttribute(Qt::WA_DeleteOnClose);
	pw->show();
}

void GraphWindow::showMessage(QString message)
{
	statusbar->showMessage(message);
}

void GraphWindow::sceneDestroyed()
{

}