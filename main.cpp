#include <QApplication>
#include <QPushButton>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>


class ImageCircle : public QPushButton
{
	Q_OBJECT
public:
	ImageCircle() = default;
	ImageCircle(QWidget* parent);
	void paintEvent(QPaintEvent* e);
	QSize sizeHint() const override;
	QSize minimumSizeHint() const override;



private slots:

public slots:

	void setYellow();
	void setRed();
	void setGreen();

private:
	QPixmap mCurretCirclePixmap;
	QPixmap mRedCirclePixmap;
	QPixmap mGreenCirclePixmap;
	QPixmap mYellowCirclePixmap;


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


int main(int argc, char* argv[])
{

	QApplication a(argc, argv);
	QWidget* windows = new QWidget;
	windows->resize(200,250);

	auto* slider = new QSlider(Qt::Horizontal,windows);
	slider->setMinimum(0);
	slider->setMaximum(99);


	ImageCircle greenLeD(nullptr);
	greenLeD.setFixedSize(250,250);


	auto* layout = new QVBoxLayout(windows);
	layout->addWidget(&greenLeD);
	layout->addWidget(slider);



	QObject::connect(slider, &QSlider::valueChanged, [&greenLeD, slider](int newValue)
	{

			if(newValue >=0 && newValue < 33)
				greenLeD.setGreen();
			else if(newValue >=33 && newValue < 66)
				greenLeD.setYellow();
			else if(newValue >=66 && newValue <= 99)
				greenLeD.setRed();


	});




	windows->show();
	QApplication::exec();
}
#include "main.moc"