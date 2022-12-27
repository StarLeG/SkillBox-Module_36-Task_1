#include <QApplication>
#include <QPushButton>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>


class ImageCircle : public QPushButton
{
	Q_OBJECT
public:
	ImageCircle() = default;
	ImageCircle(QWidget* parent);
	void paintEvent(QPaintEvent* e);
	QSize sizeHint() const override;
	QSize minimumSizeHint() const override;
	void setColor(int newValue);


public slots:
	void setYellow();
	void setRed();
	void setGreen();

private:
	QPixmap mCurretCirclePixmap;
	QPixmap mRedCirclePixmap;
	QPixmap mGreenCirclePixmap;
	QPixmap mYellowCirclePixmap;
	int slaiderValue = 0;
};

ImageCircle::ImageCircle(QWidget* parent)
{
	setParent(parent);
	setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
	mGreenCirclePixmap = QPixmap("pic//green.png");
	mRedCirclePixmap = QPixmap("pic//red.png");
	mYellowCirclePixmap = QPixmap("pic//yellow.png");
	mCurretCirclePixmap = mGreenCirclePixmap;
	setGeometry(mCurretCirclePixmap.rect());
}

void ImageCircle::paintEvent(QPaintEvent* e)
{
	QPainter p(this);
	p.drawPixmap(e->rect(),mCurretCirclePixmap);
}

QSize ImageCircle::sizeHint() const
{
	return QSize(100,100);
}

QSize ImageCircle::minimumSizeHint() const
{
	return sizeHint();
}

void ImageCircle::setGreen()
{
	mCurretCirclePixmap = mGreenCirclePixmap;
	update();
}

void ImageCircle::setRed()
{
	mCurretCirclePixmap = mRedCirclePixmap;
	update();
}

void ImageCircle::setYellow()
{
	mCurretCirclePixmap = mYellowCirclePixmap;
	update();
}

void ImageCircle::setColor(int newValue)
{
	if(newValue >= 0 && newValue < 33)
	{
		ImageCircle::setGreen();
		return;
	}
	if(newValue >= 33 && newValue < 66)
	{
		ImageCircle::setYellow();
		return;
	}

	if(newValue >= 66 && newValue <= 99)
	{
		ImageCircle::setRed();
		return;
	}
}

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	auto* slider = new QSlider(Qt::Horizontal);
	slider->setMinimum(0);
	slider->setMaximum(99);
	slider->resize(200,50);

	ImageCircle greenLeD(nullptr);
	greenLeD.setFixedSize(200,250);
	greenLeD.move(1000,100);

	QObject::connect(&slider,&QSlider::valueChanged,);

	greenLeD.setColor(15);



	greenLeD.show();
	slider->show();
	QApplication::exec();
}
#include "main.moc"