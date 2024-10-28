#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // Create the map view.
    mapView = new QWebEngineView(this);
    mapView->setUrl(QUrl("https://www.openstreetmap.org"));  // Load default map.

    // Create input fields and button.
    latitudeInput = new QLineEdit(this);
    latitudeInput->setPlaceholderText("Enter Latitude");

    longitudeInput = new QLineEdit(this);
    longitudeInput->setPlaceholderText("Enter Longitude");

    navigateButton = new QPushButton("Navigate", this);
    connect(navigateButton, &QPushButton::clicked, this, &MainWindow::navigateToLocation);

    // Create layout for input fields and button.
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(latitudeInput);
    layout->addWidget(longitudeInput);
    layout->addWidget(navigateButton);
    layout->addWidget(mapView);

    // Set layout inside a widget.
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::navigateToLocation() {
    // Get the latitude and longitude from input fields.
    QString lat = latitudeInput->text();
    QString lon = longitudeInput->text();

    // Construct the OpenStreetMap URL with coordinates.
    QString url = QString("https://www.openstreetmap.org/?mlat=%1&mlon=%2&zoom=15")
                      .arg(lat).arg(lon);

    // Navigate the map to the new location.
    mapView->setUrl(QUrl(url));
}
