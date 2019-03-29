#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#ifdef ARM
#include <QWSServer>
#endif
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_prevPoint(QPoint(0, 0)), m_curPoint(QPoint(0, 0))
{
	QColor backclolor = qRgb(255, 255, 255);
	m_image = QImage(width(), height(), QImage::Format_RGB32);	//将大小设置成和界面一样大，这样刷图就刚好刷完整个界面
	m_image.fill(backclolor);

	ui->setupUi(this);

#ifdef ARM
	this->setWindowFlags(Qt::FramelessWindowHint);      //设置窗口标志为无边框
	QWSServer::setCursorVisible(false);			//去掉鼠标
#endif
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
	m_prevPoint = e->pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
	m_curPoint = e->pos();

	QPainter painter(&m_image);
	QPen pen;
	pen.setColor(Qt::red);
	pen.setWidth(2);
	painter.setPen(pen);
	painter.drawLine(m_prevPoint, m_curPoint);

	update();

	m_prevPoint = m_curPoint;
}

void MainWindow::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawImage(0, 0, m_image);
}
