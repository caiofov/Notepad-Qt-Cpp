#include "notepadwindow.h"
#include "./ui_notepadwindow.h"

NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotepadWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    setCurrentFilename("");
}

NotepadWindow::~NotepadWindow()
{
    delete ui;
}

void NotepadWindow::setSaved(bool saved){
    if(this->saved == saved){
        return;
    }
    this->saved = saved;
    if(!saved){
        setWindowTitle(windowTitle() + "*");
        ui->actionSave_as->setEnabled(true);
    }else{
        setWindowTitle(currentFile);
        ui->actionSave_as->setEnabled(false);
    }
}

void NotepadWindow::setCurrentFilename(QString filename){
    if(!filename.isEmpty()){
        const QFileInfo info(filename);
        filename = info.fileName();
        setWindowTitle(filename);
    }else{
        setWindowTitle("New file");
    }
    currentFile = filename;
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

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

    setCurrentFilename(filename);
    setSaved(true);
}

bool NotepadWindow::saveFile(){
    QString filename = QFileDialog::getSaveFileName(this, "Save the file");
    QFile file(filename);

    // checks for errors
    if(!file.open(QFile::WriteOnly | QFile::Text )){
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return false;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
    return true;

    setCurrentFilename(filename);
    setSaved(true);
}

void NotepadWindow::on_actionSave_as_triggered()
{
    saveFile();
}


void NotepadWindow::on_actionExit_triggered()
{
    bool success = saved;

    if(!saved){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit", "Save file before exiting?",
                                      QMessageBox::Yes|QMessageBox::No);

        success = reply == QMessageBox::Yes ? saveFile() : true;
    }
    if(success){
        QApplication::quit();
    }
}


void NotepadWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void NotepadWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void NotepadWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();

}


void NotepadWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void NotepadWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void NotepadWindow::on_textEdit_textChanged()
{
    setSaved(false);
}

