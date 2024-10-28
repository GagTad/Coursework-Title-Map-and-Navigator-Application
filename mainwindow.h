#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void navigateToLocation();  // Slot to handle navigation requests.

private:
    QWebEngineView *mapView;
    QLineEdit *latitudeInput;
    QLineEdit *longitudeInput;
    QPushButton *navigateButton;
};

#endif // MAINWINDOW_H
