#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWebEngineView view;
    view.setUrl(QUrl("https://www.openstreetmap.org"));
    view.show();
    return app.exec();
}
