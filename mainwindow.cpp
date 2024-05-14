#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // add item list to combobox mode
    QStringList listItem = (QStringList() << "Inspect" << "Simulator" << "Live" << "Calibrate");
    ui->cbbMode->addItems(listItem);

    m_pSimulator = new CSimulatorInspect;

    QObject::connect(m_pSimulator, &CSimulatorInspect::loadImageSuccess, this, [&](){
        ui->imgViewer->setPixmap(m_pSimulator->pixmap().scaled(640, 480));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnLoadImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    QByteArray ba = fileName.toLocal8Bit();
    const char *pathImage = ba.data();

    m_pSimulator->loadImage(pathImage);
}
