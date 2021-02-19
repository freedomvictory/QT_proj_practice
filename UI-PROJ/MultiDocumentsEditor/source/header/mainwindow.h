#ifndef MAINWINDOW_H 
#define MAINWINDOW_H 

#include <QMainWindow> 
class MdiChild;
class QMdiSubWindow;
class QSignalMapper;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered(); 
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();

    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_P_triggered();

    void on_actionClose_triggered();
    void on_actionCloseAll_triggered();
    void on_actionTile_triggered();
    void on_actionCascade_triggered();
    void on_actionNext_triggered();
    void on_actionPrevious_triggered();

    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();

    void on_actionExit_triggered();

    void updateMenus(); 
    MdiChild* createMdiChild(); //create sub window 
    void setActiveSubWindow(QWidget *window);   //set active sub-window
    void updateWindowMenu();    //update window menu 

    void showTextRowAndCol(); //show text row and column number 

private:
    Ui::MainWindow *ui;
    QAction *actionSeparator;
    MdiChild *activeMdiChild(); //got active subwindow
    QMdiSubWindow *findMdiChild(const QString &fileName);  //find subwindow that already loaded `fileName`

    QSignalMapper *windowMapper; 

    void readSettings(); //read window setting  
    void writeSettings();//write window setting 

    void initWindow();

protected:
    void closeEvent(QCloseEvent* event);


};



#endif 