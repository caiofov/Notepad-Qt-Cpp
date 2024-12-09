#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
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

private:
    Ui::NotepadWindow *ui;
    QString currentFile = "";
};
#endif // NOTEPADWINDOW_H
