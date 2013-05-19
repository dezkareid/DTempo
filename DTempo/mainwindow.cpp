#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    tiempo = 0;
    timer->setInterval(1000);
    pause = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_comenzar_clicked()
{
    if (!pause)
    {
        tiempo = ui->tiempo->text().toInt();
        timer->start(1000);
    }
    else
        timer->start();
    ui->lcd->display(tiempo);

    pause = false;
}

void MainWindow::on_b_pausar_clicked()
{
    if(timer->isActive())
        timer->stop();
    pause = true;
}

void MainWindow::on_b_parar_clicked()
{
    timer->stop();
    ui->lcd->display("0");
    tiempo = 0;

}

void MainWindow::update()
{
    if(tiempo==0)
    {
        timer->stop();
        return;
    }
    tiempo--;
    ui->lcd->display(tiempo);

}
