/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-2010, Linköpings University,
 * Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF THIS OSMC PUBLIC
 * LICENSE (OSMC-PL). ANY USE, REPRODUCTION OR DISTRIBUTION OF
 * THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE OF THE OSMC
 * PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linköpings University, either from the above address,
 * from the URL: http://www.ida.liu.se/projects/OpenModelica
 * and in the OpenModelica distribution.
 *
 * This program is distributed  WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * For more information about the Qt-library visit TrollTech's webpage
 * regarding the Qt licence: http://www.trolltech.com/products/qt/licensing.html
 */

/*!
 * \file notebook.h
 * \author Ingemar Axelsson and Anders Fernström
 * \date 2005-02-07
 */

#ifndef NOTEBOOK_WINDOW_H
#define NOTEBOOK_WINDOW_H


//STD Headers
#include <map>

//QT Headers
#include <QtCore/QHash>

//IAEX Headers
#include "application.h"
#include "document.h"
#include "documentview.h"
#if USE_OMSKETCH
#include "Tools.h"
#endif
//Forward declaration
class QAction;
class QActionGroup;
class QKeyEvent;
class QMenu;
class QMenuBar;
class QStatusbar;
class QWidget;
class QLabel;


namespace IAEX
{
// forward declaration
class SearchForm;

class NotebookWindow : public DocumentView
{
  Q_OBJECT

public:
  NotebookWindow(Document *subject, const QString filename=0,
                 QWidget *parent=0);
  virtual ~NotebookWindow();

  virtual void update();
  virtual Document* document();
  CellApplication *application();

public slots:
  void updateMenus();            // Added 2005-11-07 AF
  void updateStyleMenu();
  void updateEditMenu();          // Added 2005-11-02 AF
  void updateCellMenu();          // Added 2006-02-03 AF
  void updateFontMenu();          // Added 2005-11-03 AF
  void updateFontFaceMenu();        // Added 2005-11-03 AF
  void updateFontSizeMenu();        // Added 2005-11-04 AF
  void updateFontStretchMenu();      // Added 2005-11-04 AF
  void updateFontColorMenu();        // Added 2005-11-07 AF
  void updateTextAlignmentMenu();      // Added 2005-11-07 AF
  void updateVerticalAlignmentMenu();    // Added 2005-11-07 AF
  void updateBorderMenu();        // Added 2005-11-07 AF
  void updateMarginMenu();        // Added 2005-11-07 AF
  void updatePaddingMenu();        // Added 2005-11-07 AF
  void updateWindowMenu();        // Added 2006-01-27 AF
  void updateWindowTitle();        // Added 2006-01-17 AF
  void updateChapterCounters();      // Added 2006-03-02 AF
  void setStatusMessage( QString msg );  // Added 2006-02-10 AF
  void forwardedAction( int action );    // Added 2006-04-27 AF
  void setPosition(int r, int c);
  void setState(QString);
  void setStatusMenu(QList<QAction*>);
  void recentTriggered();
  QVector<Cell*> SearchCells(Cell* current);  // Added 2015-07-14 To search the cells in a document and return the number of cells

protected:
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
  void SearchCells(Cell* current, QVector<Cell*> * total);

private slots:
  void newFile();
  void openFile(const QString filename="");
  void closeFile();
  void closeEvent( QCloseEvent *event );      // Added 2006-01-19 AF
  void aboutQTNotebook();
  void aboutQT();                  // Added 2006-02-21 AF
  void helpText();                // Added 2006-02-03 AF
  void saveas();
  void save();
  void quitOMNotebook();              // Added 2006-01-18 AF
  void print();                  // Added 2005-12-19 AF
  void pdf();                  // Added 2016-12-01 HK
  void selectFont();                // Added 2005-11-07 AF
  void changeStyle(QAction *action);
  void changeStyle();
  void changeFont(QAction *action);        // Added 2005-11-03 AF
  void changeFontFace(QAction *action);      // Added 2005-11-03 AF
  void changeFontSize(QAction *action);      // Added 2005-11-04 AF
  void changeFontStretch(QAction *action);    // Added 2005-11-04 AF
  void changeFontColor(QAction *action);      // Added 2005-11-07 AF
  void changeTextAlignment(QAction *action);    // Added 2005-11-07 AF
  void changeVerticalAlignment(QAction *action);  // Added 2005-11-07 AF
  void changeBorder(QAction *action);        // Added 2005-11-07 AF
  void changeMargin(QAction *action);        // Added 2005-11-07 AF
  void changePadding(QAction *action);      // Added 2005-11-07 AF
  void changeWindow(QAction *action);        // Added 2006-01-27 AF

  void undoEdit();        // Added 2006-02-03 AF
  void redoEdit();        // Added 2006-02-03 AF
  void cutEdit();          // Added 2006-02-03 AF
  void copyEdit();        // Added 2006-02-03 AF
  void pasteEdit();        // Added 2006-02-03 AF
  void findEdit();        // Added 2006-08-24 AF
  void replaceEdit();        // Added 2006-08-24 AF

  void insertImage();        // Added 2005-11-18 AF
  void insertLink();        // Added 2005-12-05 AF
  void openOldFile();        // Added 2005-12-01 AF
  void pureText();        // Added 2005-11-21 AF

#if USE_OMSKETCH
  void Sketch(); //Added by jhansi
  void sketchImageEdit();//Added by jhansi
  void viewSketchImageAttributes(); //Added by jhansi
#endif

  void createNewCell();
  void deleteCurrentCell();
  void cutCell();
  void copyCell();
  void pasteCell();
  void ungroupCell();        // Added 2006-04-26 AF
  void splitCell();        // Added 2006-04-26 AF
  void moveCursorUp();
  void moveCursorDown();
  void groupCellsAction();
  void inputCellsAction();
  void latexCellsAction();
  void textCellsAction();
  void updateRecentFiles(QString);

  void indent();
  void setAutoIndent(bool);
  void eval();
  void evalall();
  void shiftcellsUp();
  void shiftcellsDown();
  void shiftselectedcells();
private:
  void createFileMenu();
  void createEditMenu();
  void createCellMenu();
  void createFormatMenu();
  void createInsertMenu();
  void createWindowMenu();    //Added 2006-01-27 AF
  void createAboutMenu();

  bool cellEditable();      //Added 2005-11-11 AF
  void evalCells();        //Added 2006-02-14 AF
  //void createSavingTimer();

  QVector<Cell*> cells,temp_cells; //Added by jhansi

private:
  QToolBar* toolBar;
  // 2005-10-07 AF, Porting, Added this menus
  QMenu *fileMenu;
  QMenu *recentMenu;
  QMenu *editMenu;
  QMenu *cellMenu;
  QMenu *formatMenu;
  QMenu *insertMenu;          // Added 2005-11-18 AF
  QMenu *windowMenu;          // Added 2006-01-27 AF
  QMenu *aboutMenu;

  // 2005-11-03/04/07 AF, Added some more for text setting changes
  QMenu *styleMenu;
  QMenu *fontMenu;
  QMenu *faceMenu;
  QMenu *sizeMenu;
  QMenu *stretchMenu;
  QMenu *colorMenu;
  QMenu *alignmentMenu;
  QMenu *verticalAlignmentMenu;
  QMenu *borderMenu;
  QMenu *marginMenu;
  QMenu *paddingMenu;
  // 2005-12-01 AF, added for import old omnotebook file
  QMenu *importMenu;
  // 2005-11-21 AF, added for export pure text
  QMenu *exportMenu;

  QMenu *indentMenu;
  // 2005-10-07 AF, Porting, Added this actions
  // 2005-11-03/04/07 AF, Added some more for text setting changes
  QActionGroup *stylesgroup;
  QActionGroup *fontsgroup;
  QActionGroup *sizesgroup;
  QActionGroup *stretchsgroup;
  QActionGroup *colorsgroup;
  QActionGroup *alignmentsgroup;
  QActionGroup *verticalAlignmentsgroup;
  QActionGroup *bordersgroup;
  QActionGroup *marginsgroup;
  QActionGroup *paddingsgroup;

  QAction *newAction;
  QAction *openFileAction;
  QAction *saveAsAction;
  QAction *saveAction;
  QAction *printAction;        // Added 2005-12-19 AF
  QAction *pdfAction;
  QAction *closeFileAction;
  QAction *quitWindowAction;
  QAction *indentAction;
  QAction *autoIndentAction;
  QAction *evalAction;
  QAction *evalallAction;
  QAction *evalLatexAction;
  QAction *shiftcellsupAction;
  QAction *shiftcellsdownAction;
  QAction *shiftselectedcellsAction;

public:
  QAction *undoAction;
  QAction *redoAction;
  QAction *cutAction;
  QAction *copyAction;
private:
  QAction *pasteAction;
  QAction *findAction;        // Changed 2006-08-24 AF
  QAction *replaceAction;        // Added 2006-08-24 AF
  QAction *showExprAction;

  //QAction *cutCellAction;
  //QAction *copyCellAction;
  //QAction *pasteCellAction;
  QAction *addCellAction;
  QAction *ungroupCellAction;      // Added 2006-04-26 AF
  QAction *splitCellAction;      // Added 2006-04-26 AF
  QAction *deleteCellAction;
  QAction *nextCellAction;
  QAction *previousCellAction;

  QAction *groupAction;
  QAction *inputAction;
  QAction *latexAction;

  QAction *textAction;

  QAction *aboutAction;
  QAction *helpAction;        // Added 2006-02-03 AF
  QAction *aboutQtAction;        // Added 2006-02-21 AF

  QAction *facePlain;
  QAction *faceBold;
  QAction *faceItalic;
  QAction *faceUnderline;

  QAction *sizeSmaller;
  QAction *sizeLarger;
  QAction *size8pt;
  QAction *size9pt;
  QAction *size10pt;
  QAction *size12pt;
  QAction *size14pt;
  QAction *size16pt;
  QAction *size18pt;
  QAction *size20pt;
  QAction *size24pt;
  QAction *size36pt;
  QAction *size72pt;
  QAction *sizeOther;

  QAction *stretchUltraCondensed;
  QAction *stretchExtraCondensed;
  QAction *stretchCondensed;
  QAction *stretchSemiCondensed;
  QAction *stretchUnstretched;
  QAction *stretchSemiExpanded;
  QAction *stretchExpanded;
  QAction *stretchExtraExpanded;
  QAction *stretchUltraExpanded;

  QAction *colorBlack;
  QAction *colorWhite;
  QAction *color10Gray;
  QAction *color33Gray;
  QAction *color50Gray;
  QAction *color66Gray;
  QAction *color90Gray;
  QAction *colorRed;
  QAction *colorGreen;
  QAction *colorBlue;
  QAction *colorCyan;
  QAction *colorMagenta;
  QAction *colorYellow;
  QAction *colorOther;

  QAction *chooseFont;

  QAction *alignmentLeft;
  QAction *alignmentRight;
  QAction *alignmentCenter;
  QAction *alignmentJustify;
  QAction *verticalNormal;
  QAction *verticalSub;
  QAction *verticalSuper;

  QAction *borderOther;
  QAction *marginOther;
  QAction *paddingOther;

  QAction *insertImageAction;    // Added 2005-11-18 AF
  QAction *insertLinkAction;    // Added 2005-12-05 AF
  QAction *importOldFile;      // Added 2005-12-01 AF
  QAction *exportPureText;    // Added 2005-11-21 AF

#if USE_OMSKETCH
  QAction *insertSketch;//Added by jhansi
  QAction *insertSketchImage;//Added by jhansi
  QAction *editSketchImage;//Added by jhansi
  QAction *editSketchAttributes;//Added by jhansi

  //added by jhansi
  QString imageFileName;

  //vector to hold the stored image file names,position of in cell and text of the cell
  QVector<QString> filenames;
  QVector<QString> onbfilenames;
  QVector<QString> positions;
  QVector<QString> texts;
  QVector<QString> cellIds;

  Tools *window;
  bool isShown;
#endif

  // 2005-11-03/04/07 AF, Added for the new menus (for text changes)
  QHash<QString, QAction*> fonts_;
  QHash<QString, QAction*> sizes_;
  QHash<int, QAction*> stretchs_;
  QHash<QAction*, QColor*> colors_;
  QHash<int, QAction*> alignments_;
  QHash<int, QAction*> verticals_;
  QHash<int, QAction*> borders_;
  QHash<int, QAction*> margins_;
  QHash<int, QAction*> paddings_;
  QHash<QAction*, DocumentView*> windows_;

  //Change to Document.
  CellApplication *app_;
  Document *subject_;

  //list<Document *> opendocs_;
  QString filename_;

  // QTimer *savingTimer_;
  map<QString, QAction*> styles_;

  SearchForm* findForm_;    // added 2006-08-24 AF
  bool closing_;        // Added 2006-02-09 AF

  static QString openDir_;  // Added 2006-03-01 AF
  static QString saveDir_;  // Added 2006-03-01 AF
  static QString imageDir_;  // Added 2006-03-01 AF
  static QString linkDir_;  // Added 2006-03-01 AF

  QLabel* posIndicator, *stateIndicator;
  QString err_hierarchy = tr("Cells cannot be moved inside or outside another hierarchy.");
};
}
#endif
