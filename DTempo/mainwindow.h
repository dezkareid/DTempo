#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
 #include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *timer;
    int tiempo;
    bool pause;
    ~MainWindow();
    
private slots:
    void on_b_comenzar_clicked();

    void on_b_pausar_clicked();

    void on_b_parar_clicked();

    void update();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
