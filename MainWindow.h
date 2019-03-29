#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;

protected:
	void		mousePressEvent(QMouseEvent *e);
	void		mouseReleaseEvent(QMouseEvent *e);
	void		mouseMoveEvent(QMouseEvent *e);

	void		paintEvent(QPaintEvent *e);

private:
	QImage		m_image;		//实际画图的地方
	QPoint		m_prevPoint;
	QPoint		m_curPoint;
};

#endif // MAINWINDOW_H
