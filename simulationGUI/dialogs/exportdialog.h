#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include <QObject>
#include <QtGui>
#include <QDialog>


class ExportDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ExportDialog(int w, int h, int wsel, int hsel, QString filename_, bool nosel_=true, QWidget *parent = 0);
    
private:
    QPushButton* ExportButt;
    QPushButton* CancelButt;
    QPushButton* SaveButt;

    QLabel* lblFilename;
    QLabel* lblResolutionX;
    QLabel* lblResolutionY;
    QLabel* lblRatio;
    QLabel* lblFormat;

    QCheckBox* cbResolution;
    QCheckBox* cbRatio;
    QCheckBox* cbSelected;

    QLineEdit* editFilename;
    QLineEdit* editResolutionX;
    QLineEdit* editResolutionY;
    QLineEdit* editScale;

    QComboBox* cbxImgType;

    QHBoxLayout* lower1;
    QHBoxLayout* lower2;
    QHBoxLayout* lower3;
    QHBoxLayout* lower4;
    QVBoxLayout* top;

    int dwidth, dheight;

    int dwidthsel, dheightsel;

    float scale;

    bool svg, noselected;

    QString filename;

	inline int isfinite(double x) {
		unsigned short *val = (unsigned short *) &x;

		return (val[3] & 0x7ff0) != 0x7ff0;
	}

	inline double round( double d ){
		return floor( d + 0.5 );
	}

public:

    enum ImgFormat {Coloured, Monochrome};

    QString FileToSave();
    bool isOriginalSize();
    bool isExportSelected();
    int Xpixels();
    int Ypixels();
    bool isSvg();
    bool needsInkscape();
    bool isValidFilename();
    bool isPdf();
    bool isPdf_Tex();
    bool isEps();
    void setDiagram();
    float getScale();

    ExportDialog::ImgFormat getImgFormat();

signals:
    
private slots:
    void setFileName();
    void calcWidth();
    void calcHeight();
    void recalcRatio();
    void restoreOriginalWtoH();
    void setSvg(QString filename);
    void setSelectedWH();
    void recalcScale();

public slots:
    
};

#endif // EXPORTDIALOG_H
