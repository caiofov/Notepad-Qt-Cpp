#include "notepadwindow.h"
#include "./ui_notepadwindow.h"

NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotepadWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

NotepadWindow::~NotepadWindow()
{
    delete ui;
}
void NotepadWindow::setCurrentFilename(QString filename){
    const QFileInfo info(filename);
    const QString fileBasename = info.fileName();

    currentFile = filename;
    setWindowTitle(fileBasename);
}

void NotepadWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void NotepadWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);

    // checks for errors
    if(!file.open(QIODevice::ReadOnly | QFile::Text )){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setCurrentFilename(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void NotepadWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save the file");
    QFile file(filename);

    // checks for errors
    if(!file.open(QFile::WriteOnly | QFile::Text )){
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    setCurrentFilename(filename);

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();

}

