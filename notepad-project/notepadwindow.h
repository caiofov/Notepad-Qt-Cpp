#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>

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

private:
    Ui::NotepadWindow *ui;
};
#endif // NOTEPADWINDOW_H
