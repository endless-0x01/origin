#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // set name buttons radio
  ui->rb_button_on->setText("On");
  ui->rb_button_on->setChecked(false);
  ui->rb_button_off->setText("Off");
  ui->rb_button_off->setChecked(true);

  // set name pushButton
  ui->pushButton->setText("Start");
  ui->pushButton->setCheckable(true);

  // add item list
  ui->comboBox->addItem("C++");
  ui->comboBox->addItem("Java");
  ui->comboBox->addItem("Go");
  ui->comboBox->addItem("Python");

  // set range bar
  ui->progressBar->setRange(0, 10);
  ui->progressBar->setValue(0);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  if (ui->rb_button_on->isChecked()) {
    int current_value = ui->progressBar->value();
    current_value += 1;
    if (current_value > 10) {
      current_value = 0;
      ui->progressBar->setValue(0);
    }
    ui->progressBar->setValue(current_value);
  }
}
