#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Связываем сигнал clicked() кнопки с соответствующим слотом saveButton_clicked()
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveButton()
{
    // Получаем текст из QTextEdit
    QString textToSave = ui->textEdit->toPlainText();

    // Открываем диалоговое окно для выбора файла и пути сохранения
    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Текстовые файлы (*.txt)");

    // Если пользователь выбрал файл, то сохраняем текст в файл
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textToSave;
            file.close();
            QMessageBox::information(this, "Успех", "Файл успешно сохранен.");
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить файл.");
        }
    }
}
