#include <QCommandLineParser>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>
// #include <fstream>
// #include <iostream>

int main(int argc, char *argv[]) {

  // std::cout << "HELLO WORLD !!!!" << std::endl;

  // std::ofstream outfile("test.txt");

  // outfile << "my text here!" << std::endl;

  // outfile.close();

  // return 0;
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  // QCommandLineParser parser;
  // parser.setApplicationDescription("Viewer3D Application");
  // parser.addHelpOption();
  // parser.addVersionOption();

  // QCommandLineOption fileOption(QStringList() << "f"
  //                                             << "file",
  //                               "Path to the file to load", "filePath");
  // parser.addOption(fileOption);

  // parser.process(app);

  // // Retrieve file path from arguments
  QString filePath = {};

  // QString currentFilePath = parser.value(fileOption);

  // QFileInfo fileInfo(currentFilePath);
  // currentFilePath = fileInfo.absoluteFilePath();

  // // Check if the file exists
  // QFile file(currentFilePath);
  // if (file.exists() && file.open(QIODevice::ReadOnly)) {
  //   filePath = currentFilePath;

  //   // Log info about the file
  //   qInfo() << "File is valid and can be read:" << filePath;
  //   file.close(); // Close the file after checking
  // } else {
  //   qWarning() << "File does not exist or cannot be read:" <<
  //   currentFilePath;
  // }

  // Expose filePath to QML
  engine.rootContext()->setContextProperty("filePath", filePath);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
  engine.loadFromModule("Viewer3D", "Main");

  return app.exec();
}
