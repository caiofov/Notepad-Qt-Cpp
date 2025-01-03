#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class NotepadWindow;
}
QT_END_NAMESPACE

class NotepadWindow : public QMainWindow
{
    Q_OBJECT

public:
    NotepadWindow(QWidget *parent = nullptr);
    ~NotepadWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_textEdit_textChanged();

    void on_actionSave_triggered();

private:
    Ui::NotepadWindow *ui;
    QString currentFile = "New file";
    QString currentFilePath = "";
    bool saved = true;

    void setCurrentFilename(QString filename);

    void setSaved(bool saved);

    bool saveFile(QString filename);

    bool saveFileAs();
};
#endif // NOTEPADWINDOW_H
