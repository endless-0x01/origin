#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Stopwatch* stopwatch = new Stopwatch(this);

    connect(ui->startStopButton, &QPushButton::clicked, [stopwatch, this]() {
        if (stopwatch->isRunning()) {
            stopwatch->stop();
            ui->startStopButton->setText("Старт");
        } else {
            stopwatch->start();
            ui->startStopButton->setText("Стоп");
        }
        ui->lapButton->setEnabled(stopwatch->isRunning());  // Изменено
    });

    connect(ui->resetButton, &QPushButton::clicked, [stopwatch, this]() {
        stopwatch->reset();
        ui->lapsBrowser->clear();
        ui->timeLabel->setText("0");
    });

    connect(ui->lapButton, &QPushButton::clicked, [stopwatch, this]() {  // Изменено
        static int lap = 1;
        ui->lapsBrowser->append(QString("Круг %1, время: %2 сек").arg(lap++).arg(stopwatch->lapTime() / 1000));
        stopwatch->resetLapTime();
    });

    connect(stopwatch, &Stopwatch::totalTimeChanged, [this](int newTime) {
        ui->timeLabel->setText(QString::number(newTime / 1000.0, 'f', 1));
    });

    ui->lapButton->setEnabled(false);  // Изменено
}

MainWindow::~MainWindow()
{
    delete ui;
}
